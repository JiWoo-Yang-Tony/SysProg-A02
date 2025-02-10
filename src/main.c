#include <stdio.h>
#include "command.h"

int main (int argc, char *argv[]){
	
	Data data;

	readCommand(argc, argv, &data);

	return 0;
}
