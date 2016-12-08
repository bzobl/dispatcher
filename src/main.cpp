#include <iostream>

#include <glib.h>

#include "dispatcher.h"
#include "argparse.h"

void usage()
{
  std::cout << "Usage: dispatcher [OPTIONS] command" << std::endl;
}

int main(int argc, char **argv)
{
  GError *error = NULL;

  ArgParse args("/etc/dispatcher.conf");
  if (!args.parse_argv(argc, argv)) {
    usage();
    return 1;
  }

  Dispatcher dispatcher;
  if (!dispatcher.load_config(args.config_file, &error)) {
    std::cout << "could not load '" << args.config_file << "': "
              << error->message << std::endl;
    g_error_free(error);
    return 1;
  }

  if (args.n_args < 1) {
    usage();
    return 1;
  }

  std::string command(args.args[0]);
  if (!dispatcher.launch(command, &error)) {
    std::cout << "could not launch '" << command << "': "
              << error->message << std::endl;
    g_error_free(error);
    return 1;
  }

  std::cout << "all done, I'm happy" << std::endl;
  return 0;
}
