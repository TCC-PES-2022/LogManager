BIN        = log
CC         = cc
AR         = ar
CFLAGS     = -Wall -Wextra -O3 -march=native -fPIC
COVFLAGS   = -fprofile-arcs -ftest-coverage -g
LDFLAGS    = -lgcrypt -lgpg-error
COVLDFLAGS = -lgcov --coverage
DESTDIR    ?= /tmp
LIBDEST    ?= $(DESTDIR)/lib
INCDEST    ?= $(DESTDIR)/include

HEADER = ilogger

MAIN   = main

OBJ    = logger

LIB    = liblogger
