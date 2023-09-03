cc = gcc
CFLAGS = -std=gnu99 -pedantic -Wall
# Debug flags
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
SRCS = $(wildcard *.c)
# We can use the built-in function of make.
# The syntax of function calls in make is $(functionname, arg1, arg2, arg3).
# We can use the $(wildcad pattern) function to generate the list of .c files
# in the current directory.
# Then we can use the $(patsubst pattern, replacement, text) function to 
# replace the .c endings with .o endings: 
OBJS = $(patsubst %.c, %.o, $(SRCS))
DBGOBJS = $(patsubst %.c, %.dbg.o, $(SRCS))


.PHONY: clean depend all
all: main application
debug: main-debug application-debug

main: $(OBJS)
	gcc -o $@ -O3 $(OBJS)
main-debug: $(DBGOBJS)
	gcc -o $@ -ggdb3 -Og $(DBGOBJS)
%.dbg.o: %.c
	gcc $(DBGFLAGS) -c -o $@ $<
application: application.o stack.o
	cc -o $@ -O3 $<
application-debug: application.dbg.o stack.dbg.o
	$(cc) -o $@ -Og -ggdb3 $<


# This is built in make, If we use make -p
# we will find:
# %.o: %.c
# # commands to execute (built-in)
# 	  $(COMPILE.c) $(OUTPUT_OPTION) $<
#
# To understand the rule above requires us look at the definitions of
# COMPILE.c and OUTOUT_OPTION, which are alse included in the output
# if make -p.
#
# COMPILE.c = $(cc) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
# OUTPUT_OPTION = -o $@
# $<: the first prerequisite of the rule
#
# %.o: %.c
# 	gcc $(CFLAGS) -c $<

clean:
	rm -f main main-debug *.o *.c~ *.h~
depend:
	makedepend $(SRCS)
	makedepend -a -o .dbg.o $(SRCS)

# Do NOT DELETE
main.o: stack.h
stack.o: stack.h
# DO NOT DELETE

main.o: stack.h /usr/include/stdio.h
stack.o: stack.h /usr/include/stdio.h
