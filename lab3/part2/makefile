CXX = g++
BIN_DIR = bin
CPPFLAGS = -Wall -g
#useful variable $@:Target Name, $<:first dependency, $^:entire dependency list 

# all:bin/pokemon

# bin/pokemon: main.cpp bin/attackMove.o bin/battle.o bin/pokemon.o
# 	g++ -g -Wall main.cpp bin/attackMove.o bin/battle.o bin/pokemon.o -o bin/pokemon

# bin/attackMove.o: attackMove.h attackMove.cpp
# 	g++ -g -Wall -c attackMove.cpp -o bin/attackMove.o

# bin//battle.o: battle.h battle.cpp 
# 	g++ -g -Wall -c battle.cpp -o battle.o

# bin/pokemon.o: pokemon.h pokemon.cpp
# 	g++ -g -Wall -c pokemon.cpp -o pokemon.o

all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/pokemon

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

$(BIN_DIR)/pokemon: main.cpp $(BIN_DIR)/attackMove.o $(BIN_DIR)/battle.o $(BIN_DIR)/pokemon.o
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/attackMove.o: attackMove.cpp attackMove.h
	$(CXX) $(CPPFLAGS) -c $< -o $@ 

$(BIN_DIR)/battle.o: battle.cpp battle.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BIN_DIR)/pokemon.o: pokemon.cpp pokemon.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean

clean: 
	rm -rf $(BIN_DIR)
	
# g++ -g -Wall -c attackMove.cpp -o bin/attackMove.o
# g++ -g -Wall -c battle.cpp -o bin/battle.o
# g++ -g -Wall -c pokemon.cpp -o bin/pokemon.o