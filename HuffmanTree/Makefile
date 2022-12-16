CXX = g++
TARGET = bin/HuffmanTree
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/*.cpp, bin/intermediates/%.o, $(SRC))

CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

bin/intermediates/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf bin/intermediates/*.o $(TARGET)
