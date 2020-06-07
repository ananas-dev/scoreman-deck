# Compiler
CC = gcc

# Flags
CFLAGS = -g -Wall

# Target
TARGET = src/scoreman-deck

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
