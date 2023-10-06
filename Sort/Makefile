cc 				= gcc
CFLAGS 			= -std=gnu99 -Wall -pedantic
DBGFLAGS    	= -std=gnu99 -Wall -pedantic -ggdb3 -DDEBUG

BASIC_SORT_SRCS = basic_sort.c  basic_sort_test.c
BASIC_SORT_OBJS = $(BASIC_SORT_SRCS:.c=.o)
BASIC_DBG_OBJS 	= $(BASIC_SORT_SRCS:.c=.dbg.o)

.PHONY: all debug clean

all: basic_sort_test

basic_sort_test: $(BASIC_SORT_OBJS)
	$(cc) $(CFLAGS) -o $@ $^

debug: basic_sort_test_dbg

basic_sort_test_dbg: $(BASIC_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^


%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c $< -o $@

clean:
	rm -f *.o *.dbg.o basic_sort_test basic_sort_test_dbg

check: all
	valgrind --leak-check=full --show-leak-kinds=all ./basic_sort_test
