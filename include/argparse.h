#ifndef ARGPARSE_H_INCLUDED
#define ARGPARSE_H_INCLUDED

#include <string>

class ArgParse {
  public:
    std::string config_file;

    int n_args;
    char * const *args;

    ArgParse(std::string config_file);

    bool parse_argv(const int argc, char * const *argv);
};


#endif
