#include "dispatcher.h"

#include <iostream>
#include <algorithm>

#include <sys/types.h>
#include <sys/wait.h>
#include <spawn.h>
#include <unistd.h>

extern char **environ;

Dispatcher::Dispatcher()
{
}

Dispatcher::~Dispatcher()
{
}

bool Dispatcher::load_config(std::string path, GError **error)
{
  GKeyFile *file = g_key_file_new();
  if (!g_key_file_load_from_file(file, path.c_str(), G_KEY_FILE_NONE, error)) {
    return false;
  }

  size_t n_groups;
  char ** groups = g_key_file_get_groups(file, &n_groups);

  for (size_t i = 0; i < n_groups; i++) {
    std::string group(groups[i]);
    char *path = g_key_file_get_value(file, group.c_str(), Command::PATH_STRING.c_str(), NULL);
    if (path == NULL) {
      *error = g_error_new(DISPATCHER_ERROR, CONFIG_MISSING_KEY,
                           "missing required key %s", Command::PATH_STRING.c_str());
      return false;
    }

    bool has_root = false;
    if (g_key_file_has_key(file, group.c_str(), Command::HAS_ROOT_STRING.c_str(), NULL)) {
      std::cout << "checking root" << std::endl;
      has_root = g_key_file_get_boolean(file, group.c_str(), Command::HAS_ROOT_STRING.c_str(), NULL);
    }

    std::cout << "command " << path << " has root " << has_root << std::endl;
    mCommands.emplace_back(group, path, has_root);
  }

  g_strfreev(groups);
  return true;
}

bool Dispatcher::launch(std::string command, GError **error)
{
  auto it = std::find(mCommands.begin(), mCommands.end(), command);
  if (it == mCommands.end()) {
    *error = g_error_new_literal(DISPATCHER_ERROR, LAUNCH_COMMAND_NOT_FOUND, "command not found");
    return false;
  }

  Command &cmd = (*it);

  pid_t pid;
  char *path = (char *)cmd.get_path();
  char *args[] = { path, NULL };

  int spawn_flags = cmd.drop_privileges() ? POSIX_SPAWN_RESETIDS : 0;

  posix_spawnattr_t attrs;
  posix_spawnattr_setflags(&attrs, spawn_flags);

  posix_spawn(&pid, path, NULL, &attrs, args, environ);

  int wstatus;
  waitpid(pid, &wstatus, 0);
  return true;
}
