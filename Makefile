BIN    = log
CC     = cc
CFLAGS = -Wall -Wextra -O3 -march=native

HEADER = ilogger

OBJ    = logger\
         main

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ:=.o) $(HEADER:=.h)
	$(CC) $(OBJ:=.o) -o $@

default: $(BIN)

run: default
	@./log

install: $(BIN)
	mkdir -p $(DEST)/bin
	cp -f cstatusbar $(DEST)/bin
	chmod 755 $(DEST)/bin/$(BIN)

uninstall:
	rm -f $(DEST)/bin/$(BIN)

clean:
	rm -f $(BIN) modules/*.o *.o

.PHONY: install uninstall clean 
