# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17

# Target executable
TARGET = main

# Source files
SRC = main.cpp

# Default rule: compile the program
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean rule: remove the compiled binary
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
