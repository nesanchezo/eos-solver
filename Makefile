# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = eos_solver

# Source files
SRC = main.cpp PengRobinson.cpp SRK.cpp

# Header files (optional, for clarity)
HEADERS = EOSBase.h PengRobinson.h SRK.h

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (to avoid conflicts with files named "clean" or "all")
.PHONY: all clean