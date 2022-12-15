CXX = gcc
TARGET = bin/SortDemo
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/*.c, bin/intermediates/%.o, $(SRC))

CXXFLAGS = -c -Wall

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

bin/intermediates/%.o: src/%.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf bin/intermediates/*.o $(TARGET)
