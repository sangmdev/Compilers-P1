CC = gcc
CFLAGS = -g -Wall 
TARGET = main
OBJ = main.c scanner.c scanner.h token.h

all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o exec $(OBJ)
clean:
	rm -f *.o $(TARGET)
	rm -f exec

