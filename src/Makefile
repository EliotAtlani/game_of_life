# Compiler to be used
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Paths to raylib's include and lib directories (replace with the output of brew --prefix raylib if different)
INCLUDES = -I/opt/homebrew/opt/raylib/include
LDFLAGS = -L/opt/homebrew/opt/raylib/lib

# Libraries to link (raylib and macOS frameworks required by raylib)
LIBS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit

# Source files
SRCS = main.cpp grid.cpp simulation.cpp

# Output executable name
TARGET = game

# Default target to compile the program
all: $(TARGET)

# Rule to link and generate the output executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCLUDES) $(LDFLAGS) $(LIBS) -o $(TARGET)

# Clean target to remove the compiled files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
