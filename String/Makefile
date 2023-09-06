cc = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DBGOBJS = $(patsubst %.c, %.dbg.o, $(SRCS))

.PHONY: clean depend all
all: brute-force-search
debug: brute-force-search-dbg

brute-force-search: brute-force-search.o
	$(cc) $(CFLAGS) -o $@ $^
brute-force-search-dbg: brute-force-search.dbg.o
	$(cc) -o $@ -Og -ggdb3 $^

%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c -o $@ $<

clean: 
	rm -f *.o *.dbg.o brute-force-search brute-force-search-dbg
depend:
	makedepend $(SRCS)
	makedepend -a -o -dbg.o $(SRCS)
check: brute-force-search
	valgrind ./brute-force-search
