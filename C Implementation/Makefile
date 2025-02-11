# Compiler
CC = gcc
CFLAGS = -Wall -IInclude  # Include directory for headers

# Directories
SRC_DIRS = Application HAL Hardware Services
OBJ_DIR = obj
BIN_DIR = bin

# Find all .c files in specific source directories
SRC = $(wildcard Application/*.c HAL/*.c Hardware/*.c Services/*.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# Target executable
TARGET = $(BIN_DIR)/main.out

# Default target
all: $(TARGET)

# Compile source files into object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)  # Create obj directory if not exists
	$(CC) $(CFLAGS) -c $< -o $@

# Link the final executable
$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@

# Clean up compiled files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
