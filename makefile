# System Program Assignment 2 makefile
# 2025-02-10
# Jiwoo Yang

encodeInput: ./obj/main.o ./obj/command.o ./obj/fileIO.o ./obj/srec.o ./obj/asm.o ./obj/stdIO.o
	cc ./obj/main.o ./obj/command.o ./obj/fileIO.o ./obj/srec.o ./obj/asm.o ./obj/stdIO.o -o encodeInput

./obj/main.o: ./src/main.c ./inc/command.h ./inc/fileIO.h ./inc/srec.h ./inc/asm.h ./inc/stdIO.h
	cc -Wall -Iinc -c ./src/main.c -o ./obj/main.o

./obj/command.o: ./inc/command.h ./src/command.c
	cc -Wall -Iinc -c ./src/command.c -o ./obj/command.o

./obj/fileIO.o: ./inc/fileIO.h ./src/fileIO.c
	cc -Wall -Iinc -c ./src/fileIO.c -o ./obj/fileIO.o

./obj/srec.o: ./inc/srec.h ./src/srec.c
	cc -Wall -Iinc -c ./src/srec.c -o ./obj/srec.o

./obj/asm.o: ./inc/asm.h ./src/asm.c
	cc -Wall -Iinc -c ./src/asm.c -o ./obj/asm.o

./obj/stdIO.o: ./inc/stdIO.h ./src/stdIO.c
	cc -Wall -Iinc -c ./src/stdIO.c -o ./obj/stdIO.o

clean:
	rm -f ./obj/main.o
	rm -f ./obj/command.o
	rm -f ./obj/fileIO.o
	rm -f ./obj/srec.o
	rm -f ./obj/asm.o
	rm -f ./obj/stdIO.o
	rm -f encodeInput

rebuild: clean
	make
