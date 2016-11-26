#ifndef DISPATCHER_H_INCLUDED
#define DISPATCHER_H_INCLUDED

#include <string>
#include <vector>

#include "command.h"

class Dispatcher {
  private:

    std::vector<Command> mCommands;

  public:
    Dispatcher();
    ~Dispatcher();

    bool load_config(std::string path);

    bool launch(std::string name);
};

#endif
