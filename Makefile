# Compiler
CC = gcc

# Flags
CFLAGS = -g -Wall

# Target
TARGET = src/scoreman-deck

# Destination
DESTINATION = /bin/

# Name
NAME = scoreman-deck
all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c -l wiringPi

install:
	/bin/cp $(TARGET) $(DESTINATION)

uninstall:
	$(RM) $(DESTINATION)/$(NAME)

clean:
	$(RM) $(TARGET)
