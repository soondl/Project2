CC = gcc
TARGET = main
OBJECTS = ./src/main.o


all : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean :
	rm *.o main
