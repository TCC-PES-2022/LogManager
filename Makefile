BIN      = log
CC       = cc
CFLAGS   = -Wall -Wextra -O3 -march=native
LFLAGS   = -shared
LIBDEST  = ${HOME}/pes/lib
INCDEST  = ${HOME}/pes/include

HEADER = ilogger

OBJ    = logger\
         main

SOBJ   = logger

SLIB   = $(SOBJ:=.so)

default: $(BIN)

shared: $(SLIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ:=.o) $(HEADER:=.h)
	$(CC) $(OBJ:=.o) -o $@

$(SLIB): $(OBJ:=.o)
	$(CC) $(LFLAGS) $^ -o $@

move:
	cp -f $(SOBJ:=.so) $(LIBDEST)
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
	rm -f $(BIN) modules/*.o *.o *.so

.PHONY: install uninstall clean run move
