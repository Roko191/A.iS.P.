#
#	Makefile for libLabUtils.so
#
#	Author: Roko Vukovic, 17.05.2025
#

CC = clang
LIB = libLabUtils


all: main move

main: genO createLib clean


genO: ./$(LIB).c
	mkdir .tmp
	$(CC) -fPIC -c -o ./.tmp/$(LIB).o $(LIB).c


createLib: genO
	$(CC) -shared -o out/$(LIB).so ./.tmp/$(LIB).o


# Planing to put working version there so program can link
move: createLib
	cp ./out/$(LIB).so ../

clean:
	rm -rf .tmp
