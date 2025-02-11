# Compiler settings
CXX = g++
CXXFLAGS = -Wall -IInclude -std=c++11

# Directories
SRC_DIRS = Application HAL Services
OBJ_DIR = obj
BIN_DIR = bin

# Find all .cpp files in source directories
SRC = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Output executable file
TARGET = $(BIN_DIR)/main.out

# Default target to compile everything
all: $(TARGET)

# Rule to compile .cpp to .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(dir $<)  # Create the object directory if it doesn't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the final executable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)  # Create the bin directory if it doesn't exist
	$(CXX) $(OBJ) -o $(TARGET)

# Clean up object and binary files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# To compile a specific file (you can use this if you want to just compile the main file directly)
compile:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

