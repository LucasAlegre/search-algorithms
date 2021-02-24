GPP=g++ -std=c++14 -O3
BIN_DIR=./bin
SRC_DIR=./src/

SRC=$(wildcard $(SRC_DIR)**/*.cpp)
OBJ=$(addprefix $(BIN_DIR)/,$(notdir $(SRC:.cpp=.o)))

all: $(OBJ)
	$(GPP) -o main $(OBJ) Main.cpp 

./bin/%.o: ./src/NPuzzle/%.cpp
	@mkdir -p $(BIN_DIR)
	$(GPP) -c -o $@ $<

./bin/%.o: ./src/Algorithms/%.cpp
	@mkdir -p $(BIN_DIR)
	$(GPP) -c -o $@ $<

clean:
	rm -rf *.o bin main