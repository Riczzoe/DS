cc = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
INC = -I./ -I../Searching/BST/ -I../queue/queue_linklist/

TRAVSRCS = ../Searching/BST/BST.c tree_travel.c main.c ../queue/queue_linklist/queue.c
TRAVOBJS = $(TRAVSRCS:.c=.o)
TRAVDEGOBJS = $(TRAVSRCS:.c=.dbg.o)

.PHONY: all clean debug

all: bst-trav-test
bst-trav-test: $(TRAVOBJS)
	$(cc) $(CFLAGS) $(INC) -o $@ $^

debug: bst-trav-test-dbg
bst-trav-test-dbg: $(TRAVDEGOBJS)
	$(cc) $(DBGFLAGS) $(INC) -o $@ $^

%.dbg.o: %.c
	$(cc) $(DBGFLAGS) $(INC) -c -o $@ $<
%.o: %.c
	$(cc) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f *.o bst-trav-test bst-trav-test-dbg
check: bst-trav-test
	valgrind ./bst-trav-test
