# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -IInclude

# Directories
SRCDIR = Application HAL Hardware Service
OBJDIR = obj
BINDIR = bin

# Source and Object Files
SOURCES = $(wildcard $(patsubst %, %/*.cpp, $(SRCDIR)))
OBJECTS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

# Output Binary
TARGET = $(BINDIR)/MicrocontrollerApp

$(shell mkdir -p $(OBJDIR) $(BINDIR))

all: $(TARGET)

$(OBJDIR)/%.o: $(patsubst %, %/%.cpp, $(SRCDIR))
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)

run: all
	./$(TARGET)
