# Compiler
CC = gcc

# Flags
CFLAGS = -g -Wall

# Target
TARGET = src/scoreman-deck

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c -l bcm2835

clean:
	$(RM) $(TARGET)
