#include <stdio.h>
#include "parse.h"
#include <unistd.h>
#include <string.h>


int main() {
	char buffer[500];
	char * args[50];
	while (1) {
		sleep(1);
		printf("$ ");
		fgets(buffer, 499, stdin);
		parse_args(buffer, args);
		execvp(args[0], args);
	}		
}
