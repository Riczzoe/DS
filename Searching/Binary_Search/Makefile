cc 			= gcc
CFLAGS	 	= -std=gnu99 -Wall -pedantic
DBGFLAGS	= -std=gnu99 -Wall -pedantic -ggdb3 -DDEBUG

TEST_SRCS 	= binary_search_st.c test.c
TEST_OBJS	= $(TEST_SRCS:.c=.o)
TEST_DBG_OBJS 	= $(TEST_SRCS:.c=.dbg.o)

.PHONY: all clean debug

all: test_binary_search test_binary_search_dbg

test_binary_search: $(TEST_OBJS)
	$(cc) $(CFLAGS) -o $@ $^

debug: test_binary_search_dbg
test_binary_search_dbg: $(TEST_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^

%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c $< -o $@

clean:
	rm -f *.o test_binary_search test_binary_search_dbg
check: test_binary_search
	valgrind --leak-check=full ./test_binary_search
