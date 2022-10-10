#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -g -Wall
FUNCTIONS = functions/
INCLUDES = includes/
# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: setup

# To create the executable file count we need the object files
# strassen.o, setup.o, and all .o file peer to the project:
#
setup:  setup.o strassen.o matrix.o
	$(CC) $(CFLAGS) -o setup *.o

# To create the object file setup.o, we need the source
# files setup.cpp, matrix.h, and counter.h:
#
setup.o:  setup.cpp $(INCLUDES)*.h
	$(CC) $(CFLAGS) -c setup.cpp

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
strassen.o:  strassen.cpp $(INCLUDES)matrix.h $(INCLUDES)strassen.h $(INCLUDES)utils.h
	$(CC) $(CFLAGS) -c strassen.cpp

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
matrix.o:  $(FUNCTIONS)matrix.cpp $(INCLUDES)matrix.h $(INCLUDES)utils.h
	$(CC) $(CFLAGS) -c $(FUNCTIONS)matrix.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) setup *.o *~