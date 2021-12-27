#
# Harry Saliba 2021
#

CC = gcc
CFLAGS = -Wall -g

all: rummicomp

rummicomp: src/main.o src/models/tile.o src/models/tile.o

test: src/test.o
	gcc src/test.o -o test

clean:
	rm -rf src/*.o src/models/*.o rummicomp test
