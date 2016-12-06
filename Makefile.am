SUBDIRS = .
bin_PROGRAMS = dispatcher

dispatcher_CXXFLAGS = -std=c++14 -Wall -I${top_srcdir}/include $(GLIB_CFLAGS)
dispatcher_LDADD = $(GLIB_LIBS)

dispatcher_SOURCES =  src/command.cpp		\
		      src/dispatcher.cpp	\
                      src/main.cpp		\
		      ${NULL}
