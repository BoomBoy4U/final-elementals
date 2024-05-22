# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Include directories
INCLUDES = -I.

# SFML libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

# Source files
SRC = Main.cpp Game.cpp Player.cpp Enemy.cpp Boss.cpp Entity.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable
EXEC = game

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
