cc = gcc
CFLAGS = -std=gnu99 -pedantic -Wall 
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
INC = -I./ -I../queue/queue_linklist/

TEST_SRCS 		= graph_basic_test.c graph.c
TEST_OBJS 		= $(TEST_SRCS:.c=.o)
TEST_DBG_OBJS 	= $(TEST_SRCS:.c=.dbg.o)

GA_SRCS			= ../queue/queue_linklist/queue.c graph.c graph_algroithms.c graph_algroithms_test.c
GA_OBJS			= $(GA_SRCS:.c=.o)
GA_DBG_OBJS		= $(GA_SRCS:.c=.dbg.o)

.PHONY: all clean debug
all: graph_basic_test ga_test

graph_basic_test: $(TEST_OBJS)
	$(cc) $(CFLAGS) -o $@ $^
ga_test: $(GA_OBJS)
	$(cc) $(CFLAGS) $(INC) -o $@ $^

debug: graph_basic_test_dbg ga_test_dbg
graph_basic_test_dbg: $(TEST_DBG_OBJS)
	$(cc) $(DBGFLAGS) $(INC) -o $@ $^
ga_test_dbg: $(GA_DBG_OBJS)
	$(cc) $(DBGFLAGS) $(INC) -o $@ $^


%.o: %.c
	$(cc) $(CFLAGS) $(INC) -c $< -o $@
%.dbg.o: %.c
	$(cc) $(DBGFLAGS) $(INC) -c $< -o $@

clean:
	rm -f *.o *.dbg.o graph_basic_test graph_basic_test_dbg ga_test ga_test_dbg
basic_check: graph_basic_test
	valgrind --leak-check=full --show-leak-kinds=all ./graph_basic_test
ga_check: ga_test
	valgrind --leak-check=full --show-leak-kinds=all ./ga_test
