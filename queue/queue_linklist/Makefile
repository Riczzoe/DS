cc = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DBGOBJS = $(patsubst %.c, %.dbg.o, $(SRCS))

.PHONY: clean depend all
all: main
debug: main-debug

main: $(OBJS)
	$(cc) -o $@ -O3 $(OBJS)
main-debug: $(DBGOBJS)
	$(cc) -o $@ -Og -ggdb3 $(DBGOBJS)
%.dbg.o: %.c
	$(cc) -o $@ -$(DBGFLAGS) -c $<

clean:
	rm -f main main-debug *.o *.c~ *.h~
depend:
	makedepend $(SRCS)
	makedepend -a -o -dbg.o $(SRCS)
# DO NOT DELETE

main.o: queue.h /usr/include/stdio.h /usr/include/stdlib.h
queue.o: queue.h /usr/include/stdio.h /usr/include/stdlib.h

main-dbg.o: queue.h /usr/include/stdio.h /usr/include/stdlib.h
queue-dbg.o: queue.h /usr/include/stdio.h /usr/include/stdlib.h
