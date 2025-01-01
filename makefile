# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lglfw -lGL

# Target executable
TARGET = opengl_window

# Source files
SRC = opengl_window.c

# Build the target
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(LDFLAGS)

# Clean up build files
clean:
	rm -f $(TARGET)

