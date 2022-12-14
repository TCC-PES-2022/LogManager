BIN        = log
CC         = cc
AR         = ar
CFLAGS     = -Wall -Wextra -fPIC
COVFLAGS   = -fprofile-arcs -ftest-coverage -g
LDFLAGS    = -lgcrypt -lgpg-error
DESTDIR    ?= /tmp
LIBDEST    ?= $(DESTDIR)/lib
INCDEST    ?= $(DESTDIR)/include

HEADER = ilogger

MAIN   = main

OBJ    = log

LIB    = liblog
