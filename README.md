Simple Dispatcher to launch subcommands with evalated privileges

First crude proof-of-concept implementation of a dispatcher that launches programs specified in a simple config file.
The dispatcher itself is meant to be run with suid bit set and drop privileges when spawning other processes if not otherwise specified in the config file.
Please note that a check for the config file being read-only is still missing.

To build run
```
./autogen.sh
mkdir _build && cd _build
../configure
make
```
