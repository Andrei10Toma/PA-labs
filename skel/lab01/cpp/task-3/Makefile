CC = g++
FILES = main.cpp
CFLAGS = -Wall -std=c++17
EXEC = test

all: build run

build:
	$(CC) $(FILES) -o $(EXEC) $(CFLAGS)

run:
	./$(EXEC) && cat out
clean:
	rm -rf $(EXEC)
