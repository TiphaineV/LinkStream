
CC=clang++
CFLAGS=-O3 -Wall -std=c++11

all:
	$(CC) $(CFLAGS) ./src/CoreStat/CoreStat.cpp ./src/LinkStream.cpp ./src/main.cpp -o main
