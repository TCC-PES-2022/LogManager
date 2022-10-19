BIN      = log
CC       = cc
AR       = ar
CFLAGS   = -Wall -Wextra -O3 -march=native -fPIC
LIBDEST  = ${HOME}/pes/lib
INCDEST  = ${HOME}/pes/include

HEADER = ilogger

MAIN   = main

OBJ    = logger

LIB    = liblogger

# Dynamic library
DLIB   = $(LIB:=.so)
# Static library
SLIB   = $(LIB:=.a)

default: $(BIN)

lib : slib dlib
slib: $(SLIB)
dlib: $(DLIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ:=.o) $(MAIN:=.o) $(HEADER:=.h)
	$(CC) $^ -o $@

# Generate dynamic library rule
$(DLIB): $(OBJ:=.o)
	$(CC) -shared $^ -o $@

# Generate static library rule
$(SLIB): $(OBJ:=.o)
	$(AR) -rcs $@ $^

move:
	mkdir -p $(LIBDEST)
	mkdir -p $(LIBDEST)
	cp -f $(DLIB) $(SLIB) $(LIBDEST)
	cp -f $(HEADER:=.h) $(INCDEST)

run: default
	@./log

install: $(BIN)
	mkdir -p $(DEST)/bin
	cp -f cstatusbar $(DEST)/bin
	chmod 755 $(DEST)/bin/$(BIN)

uninstall:
	rm -f $(DEST)/bin/$(BIN)

clean:
	rm -f $(BIN) modules/*.o *.o *.so *.a

.PHONY: install uninstall clean run move lib slib dlib
