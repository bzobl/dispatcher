#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>

#include <iostream>

class Command {

  private:
    std::string mName;
    std::string mPath;
    bool mHasRoot;

  public:
    static const std::string PATH_STRING;
    static const std::string HAS_ROOT_STRING;

    Command(std::string name, std::string path, bool has_root);

    bool drop_privileges() const { return !mHasRoot; }
    const char *get_path() const { return mPath.c_str(); }

    bool operator==(std::string name) {
      return mName == name;
    }
};

#endif
