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
CFLAGS  = -g -Wall # for debugging and so on
# CFLAGS  = -Wall # for not debugging and so on
FUNCTIONS = functions/
INCLUDES = includes/
# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: setup clean_bin

# To create the executable file count we need the object files
# strassen.o, setup.o, and all .o file peer to the project:
#
setup:  setup.o strassen.o matrix_f.o utils_f.o lcs.o lcs_f.o globalSequenceAlignment.o globalSequenceAlignment_f.o
	$(CC) $(CFLAGS) -o setup *.o

# To create the object file setup.o, we need the source
# files setup.cpp and all headers files:
#
setup.o:  setup.cpp $(INCLUDES)*.h
	$(CC) $(CFLAGS) -c setup.cpp

# To create the object file strassen.o, we need the source
# files strassen.cpp, matrix.h, strassen.h and utils.h:
#
strassen.o:  strassen.cpp $(INCLUDES)matrix.h $(INCLUDES)strassen.h $(INCLUDES)utils.h
	$(CC) $(CFLAGS) -c strassen.cpp

# To create the object file matrix.o, we need the source files
# matrix.cpp, matrix.h and utils.h:
#
matrix_f.o:  $(FUNCTIONS)matrix_f.cpp $(INCLUDES)matrix.h $(INCLUDES)utils.h
	$(CC) $(CFLAGS) -c $(FUNCTIONS)matrix_f.cpp

# To create the object file lcs.o, we need the source
# files lcs.cpp, lcs.h and utils.h:
#
lcs.o:  lcs.cpp $(INCLUDES)utils.h $(INCLUDES)lcs.h
	$(CC) $(CFLAGS) -c lcs.cpp

# To create the object file lcs_f.o, we need the source files
# lcs_f.cpp, lcs.h and utils.h:
#
lcs_f.o:  $(FUNCTIONS)lcs_f.cpp $(INCLUDES)lcs.h $(INCLUDES)utils.h
	$(CC) $(CFLAGS) -c $(FUNCTIONS)lcs_f.cpp

# To create the object file lcs.o, we need the source
# files lcs.cpp, lcs.h and utils.h:
#
globalSequenceAlignment.o:  globalSequenceAlignment.cpp $(INCLUDES)utils.h $(INCLUDES)globalSequenceAlignment.h
	$(CC) $(CFLAGS) -c globalSequenceAlignment.cpp

# To create the object file lcs_f.o, we need the source files
# lcs_f.cpp, lcs.h and utils.h:
#
globalSequenceAlignment_f.o:  $(FUNCTIONS)globalSequenceAlignment_f.cpp $(INCLUDES)globalSequenceAlignment.h $(INCLUDES)utils.h
	$(CC) $(CFLAGS) -c $(FUNCTIONS)globalSequenceAlignment_f.cpp

# To create the object file utils_f.o, we need the source files
# utils_f.cpp and utils.h:
#
utils_f.o:  $(FUNCTIONS)utils_f.cpp $(INCLUDES)utils.h
	$(CC) $(CFLAGS) -c $(FUNCTIONS)utils_f.cpp

# To start over from scratch, type 'make clean'.  This
# will call the clean_bin and the remove setup file
clean: clean_bin
	$(RM) setup

# Clean all binaries object
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean_bin: 
	$(RM)  *.o *~