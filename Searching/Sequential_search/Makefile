cc 			= gcc
CFLAGS	 	= -std=gnu99 -Wall -pedantic
DBGFLAGS	= -std=gnu99 -Wall -pedantic -ggdb3 -DDEBUG

TEST_SRCS	= sequential_search_st.c test_sequential_search_table.c
TEST_OBJS  	= $(TEST_SRCS:.c=.o)
TEST_DBG_OBJS	= $(TEST_SRCS:.c=.dbg.o)

.PHONY: all clean debug

all: test_sequential_search_table test_sequential_search_table_dbg

test_sequential_search_table: $(TEST_OBJS)
	$(cc) $(CFLAGS) -o $@ $^

debug: test_sequential_search_table_dbg
test_sequential_search_table_dbg: $(TEST_DBG_OBJS)
	$(cc) $(DBGFLAGS) -o $@ $^

%.dbg.o: %.c
	$(cc) $(DBGFLAGS) -c $< -o $@

clean:
	rm -f *.o test_sequential_search_table test_sequential_search_table_dbg
basic_check: test_sequential_search_table
	valgrind --leak-check=full --show-leak-kinds=all ./test_sequential_search_table
