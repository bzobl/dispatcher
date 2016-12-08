#include "argparse.h"

#include <cassert>
#include <unistd.h>
#include <getopt.h>

ArgParse::ArgParse(std::string config_file) : config_file(config_file)
{
}

bool ArgParse::parse_argv(const int argc, char * const *argv)
{
  static const struct option long_options[] = {
    { "config", required_argument, NULL, 'c' },
    { 0, 0, 0, 0 },
  };
  optind = 1;
  while (true) {
    int option_index;
    int c = getopt_long(argc, argv, "c:", long_options, &option_index);
    if (c == -1) {
      break;
    }

    switch (c) {
      case 'c':
	config_file = optarg;
	break;
      
      case '?':
	return false;

      default:
	assert(false);
    }
  }

  this->n_args = argc - optind;
  this->args = &argv[optind];

  return true;
}
