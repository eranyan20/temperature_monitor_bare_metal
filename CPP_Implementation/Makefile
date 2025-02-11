# Compiler settings

CXX = g++
CXXFLAGS = -Wall -IInclude -std=c++11

# Directories
SRC_DIRS = Application HAL Services Hardware
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

TARGET = $(BIN_DIR)/temp_mon.out

all: $(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJ) -o $(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

compile:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

