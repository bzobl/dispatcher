#ifndef DISPATCHER_H_INCLUDED
#define DISPATCHER_H_INCLUDED

#include <string>
#include <vector>

#include <glib.h>

#include "command.h"

#define DISPATCHER_ERROR dispatcher_error_quark()
inline GQuark dispatcher_error_quark()
{
  return g_quark_from_string("Dispatcher");
}

class Dispatcher {
  private:
    std::vector<Command> mCommands;

  public:
    enum Errors {
      CONFIG_MISSING_KEY,
      LAUNCH_COMMAND_NOT_FOUND,
    };

    Dispatcher();
    ~Dispatcher();

    bool load_config(std::string path, GError **error);

    bool launch(std::string command, GError **error);
};

#endif
