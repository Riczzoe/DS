cc = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DBGOBJS = $(patsubst %.c, %.dbg.o, $(SRCS))

.PHONY: clean depend all
all: main application
debug: main-debug application-debug

main: $(OBJS)
	$(cc) -o $@ -O3 $(OBJS)
main-debug: $(DBGOBJS)
	$(cc) -o $@ -Og -ggdb3 $(DBGOBJS)
%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c -o $@ $<
application: application.o stack.o
	$(cc) -o $@ -O3 application.o stack.o
application-debug: application.dbg.o stack.dbg.o
	$(cc) -o $@ -Og -ggdb3 application.dbg.o stack.dbg.o

clean:
	rm -f main main-debug *.o *.c~ *.h~
depend:
	makedepend $(SRCS)
	makedepend -a -o -dbg.o $(SRCS)


# DO NOT DELETE

main.o: stack.h /usr/include/stdio.h /usr/include/stdlib.h
stack.o: stack.h /usr/include/stdio.h /usr/include/stdlib.h

main-dbg.o: stack.h /usr/include/stdio.h /usr/include/stdlib.h
stack-dbg.o: stack.h /usr/include/stdio.h /usr/include/stdlib.h
