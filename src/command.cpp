#include "command.h"

const std::string Command::PATH_STRING = "Path";
const std::string Command::HAS_ROOT_STRING = "Root";

Command::Command(std::string name, std::string path, bool has_root) : mName(name),
                                                                      mPath(path),
                                                                      mHasRoot(has_root)
{
}
