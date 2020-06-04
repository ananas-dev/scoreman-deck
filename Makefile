# Compiler
CC = gcc

# Flags
CFLAGS = -g -Wall -l bcm2835

# Target
TARGET = sdeck

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
