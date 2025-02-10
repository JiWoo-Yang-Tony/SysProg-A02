# System Program Assignment 2 makefile
# 2025-02-10
# Jiwoo Yang

encodeInput: ./obj/main.o
	cc ./obj/main.o -o encodeInput

./obj/main.o: ./src/main.c
	cc -c ./src/main.c -o ./obj/main.o

clean:
	rm -f ./obj/main.o

rebuild: clean
	make
