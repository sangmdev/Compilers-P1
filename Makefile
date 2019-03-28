CC = gcc
CFLAGS = -g -Wall 
TARGET = main
OBJ = main.c

all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o exec $(OBJ)
clean:
	rm -f *.o $(TARGET)
	rm -f exec

