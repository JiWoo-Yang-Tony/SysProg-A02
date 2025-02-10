# System Program Assignment 2 makefile
# 2025-02-10
# Jiwoo Yang

encodeInput: ./obj/main.o ./obj/command.o
	cc ./obj/main.o ./obj/command.o -o encodeInput

./obj/main.o: ./src/main.c ./inc/command.h
	cc -Wall -Iinc -c ./src/main.c -o ./obj/main.o

./obj/command.o: ./inc/command.h ./src/command.c
	cc -Wall -Iinc -c ./src/command.c -o ./obj/command.o
clean:
	rm -f ./obj/main.o
	rm -f ./obj/command.o
	rm -f encodeInput

rebuild: clean
	make
