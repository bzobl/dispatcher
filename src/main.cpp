#include <iostream>

#include "dispatcher.h"

int main(int argc, char **argv)
{
  Dispatcher dispatcher;
  dispatcher.load_config("./conf");

  std::cout << "argc is " << argc << std::endl;
  if ((argc >= 2) && !dispatcher.launch(argv[1])) {
    std::cout << "could not launch " << argv[1] << std::endl;
  }

  std::cout << "all done, I'm happy" << std::endl;
  return 0;
}
