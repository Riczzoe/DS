cc = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DBGOBJS = $(patsubst %.c, %.dbg.o, $(SRCS))

.PHONY: clean depend all
all: main main-debug
debug: main-debug

main: $(OBJS)
	$(cc) -o $@ -O3 $(OBJS)
main-debug: $(DBGOBJS)
	$(cc) -o $@ -Og -ggdb3 $(DBGOBJS)

%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c -o $@ $<

clean:
	rm -f main main-debug *.o *.c~ *.h~
depend:
	makedepend $(SRCS)
	makedepend -a -o -dbg.o $(SRCS)
