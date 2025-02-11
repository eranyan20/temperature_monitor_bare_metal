# Compiler
CC = gcc
CFLAGS = -Wall -I./Include


SRC_DIRS = Application HAL Hardware Services
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(wildcard Application/*.c HAL/*.c Hardware/*.c Services/*.c)
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

# Target executable
TARGET = $(BIN_DIR)/temp_mon.out

all: $(TARGET)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)  # Create obj directory if not exists
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@

# Clean up compiled files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
