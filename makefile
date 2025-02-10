# System Program Assignment 2 makefile
# 2025-02-10
# Jiwoo Yang

encodeInput: ./obj/main.o ./obj/command.o ./obj/fileIO.o
	cc ./obj/main.o ./obj/command.o ./obj/fileIO.o -o encodeInput

./obj/main.o: ./src/main.c ./inc/command.h ./inc/fileIO.h
	cc -Wall -Iinc -c ./src/main.c -o ./obj/main.o

./obj/command.o: ./inc/command.h ./src/command.c
	cc -Wall -Iinc -c ./src/command.c -o ./obj/command.o

./obj/fileIO.o: ./inc/fileIO.h ./src/fileIO.c
	cc -Wall -Iinc -c ./src/fileIO.c -o ./obj/fileIO.o

clean:
	rm -f ./obj/main.o
	rm -f ./obj/fileIO.o
	rm -f ./obj/command.o
	rm -f encodeInput

rebuild: clean
	make
