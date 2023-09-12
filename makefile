# CXX Make variable for compiler
CXX=g++
# -std=c++11  C/C++ variant to use, e.g. C++ 2011
# -Wall       show the necessary warning files
# -g3         include information for symbolic debugger e.g. gdb
CXXFLAGS=-std=c++11 -Wall -g3

# object files
OBJS = tree.o countSubstrings.o

# Program name
PROGRAM = countsubstrings

# Rules format:
# target : dependency1 dependency2 ... dependencyN
#     Command to make target, uses default rules if not specified

# First target is the one executed if you just type make
# make target specifies a specific target
# $^ is an example of a special variable.  It substitutes all dependencies
$(PROGRAM) : $(OBJS)
	$(CXX) -o $(PROGRAM) $^

tree.o : tree.h tree.cpp
	$(CXX) $(CXXFLAGS) -c tree.cpp

countSubstrings.o : tree.h countSubstrings.cpp
	$(CXX) $(CXXFLAGS) -c countSubstrings.cpp

clean :
	rm -f *.o $(PROGRAM)
