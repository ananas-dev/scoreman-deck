# Compiler
CC = gcc

# Flags
CFLAGS = -g -Wall -l wiringPi

# Target
TARGET = sdeck

all: $(TARGET)

$(TARGET): $(TARGET)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
