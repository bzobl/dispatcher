Simple Dispatcher to launch subcommands with evalated privileges

First crude proof-of-concept implementation of a dispatcher that launches programs specified in a simple config file.
The dispatcher itself is meant to be run with suid bit set and drop privileges when spawning other processes if not otherwise specified in the config file.
Please note that a check for the config file being read-only is still missing.

Also I'm not yet using a buildsystem, therefore calling
```
g++ -o dispatcher -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I./include main.cpp dispatcher.cpp command.cpp -lglib-2.0 -std=c++14 && sudo chown root dispatcher && sudo chmod +s dispatcher
```

has to suffice for now.
