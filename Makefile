# Compiler and flags
CC = gcc
CFLAGS = -Wall 
LDFLAGS = -lm

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Header files
INCLUDES = -I$(INCLUDE_DIR)

# Target executable
TARGET = kd_tree

# Default target
all: directories $(TARGET)

# Create build directory
directories:
	@mkdir -p $(BUILD_DIR)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Build complete!"

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "Clean complete!"

# Run tests
test: $(TARGET)
	@echo "Running tests..."
	./$(TARGET)

# Force rebuild
rebuild: clean all

.PHONY: all clean test rebuild directories
