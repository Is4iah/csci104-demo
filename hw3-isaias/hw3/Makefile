CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=coloring.o maps.o 

all: coloring

coloring: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

coloring.o: coloring.cpp maps.h #datastore.h product_parser.h util.h mydatastore.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c coloring.cpp
maps.o: maps.cpp maps.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c maps.cpp

clean:
	rm -f *.o coloring

# all: sudoku

# sudoku: sudoku.o main.cpp
# 	g++ -g -Wall main.cpp sudoku.o -o sudoku

# sudoku.o: sudoku.cpp sudoku.h
# 	g++ -g -Wall -c sudoku.cpp -o sudoku.o

# clean:
# 	-@rm sudoku 
# 	-@rm sudoku.o