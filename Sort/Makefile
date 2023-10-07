cc 				= gcc
CFLAGS 			= -std=gnu99 -Wall -pedantic 
DBGFLAGS    	= -std=gnu99 -Wall -pedantic -ggdb3 -DDEBUG

BASIC_SORT_SRCS = basic_sort.c sort_test.c basic_sort_test.c
BASIC_SORT_OBJS = $(BASIC_SORT_SRCS:.c=.o)
BASIC_DBG_OBJS 	= $(BASIC_SORT_SRCS:.c=.dbg.o)

ALL_SORT_SRCS 	= basic_sort.c heap_sort_pq.c heap_sort.c quick_sort.c radix_sort.c sort_test.c all_sort_test.c
ALL_SORT_OBJS 	= $(ALL_SORT_SRCS:.c=.o)
ALL_DBG_OBJS 	= $(ALL_SORT_SRCS:.c=.dbg.o)

.PHONY: all debug clean

all: basic_sort_test all_sort_test

basic_sort_test: $(BASIC_SORT_OBJS)
	$(cc) $(CFLAGS) -o $@ $^
all_sort_test: $(ALL_SORT_OBJS)
	$(cc) $(CFLAGS) -o $@ $^

debug: basic_sort_test_dbg all_sort_test_dbg

basic_sort_test_dbg: $(BASIC_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^
all_sort_test_dbg: $(ALL_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^

%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c $< -o $@

clean:
	rm -f *.o *.dbg.o basic_sort_test all_sort_test basic_sort_test_dbg all_sort_test_dbg

check_basic_sort: basic_sort_test
	valgrind --leak-check=full --show-leak-kinds=all ./basic_sort_test
