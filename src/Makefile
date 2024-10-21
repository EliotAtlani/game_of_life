# Compiler to be used
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -g  # Added -g for debugging, you can remove it if not needed

# Paths to raylib's include and lib directories (replace with the output of brew --prefix raylib if different)
INCLUDES = -I/opt/homebrew/opt/raylib/include
LDFLAGS = -L/opt/homebrew/opt/raylib/lib

# Libraries to link (raylib and macOS frameworks required by raylib)
LIBS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit

# Source files
SRCS = main.cpp grid.cpp simulation.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Output executable name
TARGET = game

# Default target to compile the program
all: $(TARGET)

# Rule to link and generate the output executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDES) $(LDFLAGS) $(LIBS) -o $(TARGET)

# Rule to compile individual source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean target to remove the compiled files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
