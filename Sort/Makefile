cc 				= gcc
CFLAGS 			= -std=gnu99 -Wall -pedantic 
DBGFLAGS    	= -std=gnu99 -Wall -pedantic -ggdb3 -DDEBUG

BASIC_SORT_SRCS = basic_sort.c sort_test.c basic_sort_test.c
BASIC_SORT_OBJS = $(BASIC_SORT_SRCS:.c=.o)
BASIC_DBG_OBJS 	= $(BASIC_SORT_SRCS:.c=.dbg.o)

HEAP_SORT_SRCS 	= heap_sort_pq.c  heap_sort.c basic_sort.c sort_test.c heap_sort_test.c
HEAP_SORT_OBJS 	= $(HEAP_SORT_SRCS:.c=.o)
HEAP_DBG_OBJS 	= $(HEAP_SORT_SRCS:.c=.dbg.o)

.PHONY: all debug clean

all: basic_sort_test heap_sort_test

basic_sort_test: $(BASIC_SORT_OBJS)
	$(cc) $(CFLAGS) -o $@ $^
heap_sort_test: $(HEAP_SORT_OBJS)
	$(cc) $(CFLAGS) -o $@ $^

debug: basic_sort_test_dbg heap_sort_test_dbg

basic_sort_test_dbg: $(BASIC_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^
heap_sort_test_dbg: $(HEAP_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^


%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c $< -o $@

clean:
	rm -f *.o *.dbg.o basic_sort_test heap_sort_test basic_sort_test_dbg heap_sort_test_dbg

check_basic_sort: basic_sort_test
	valgrind --leak-check=full --show-leak-kinds=all ./basic_sort_test
check_heap_sort: heap_sort_test
	valgrind --leak-check=full --show-leak-kinds=all ./heap_sort_test
