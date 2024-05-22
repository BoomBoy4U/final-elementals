# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -std=c++11 -Wall

# Define the source files
SRC = main.cpp Player.cpp Enemy.cpp Boss.cpp Gameplay.cpp Entity.cpp GameMenu.cpp

# Define the header files
HEADERS = Player.h Enemy.h Boss.h Gameplay.h Entity.h GameMenu.h

# Define the output executable
OUTPUT = game

# Define the object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(OUTPUT)

# Link the object files to create the executable
$(OUTPUT): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each source file into an object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f $(OBJ) $(OUTPUT)

.PHONY: all clean
