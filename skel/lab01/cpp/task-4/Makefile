CC = g++
FILES = main.cpp
CFLAGS = -Wall -g -std=c++17
EXEC = test

all: build run

build: main.cpp
	$(CC) $(FILES) -o $(EXEC) $(CFLAGS)

run:
	./$(EXEC) && cat out

clean:
	rm -rf $(EXEC)
