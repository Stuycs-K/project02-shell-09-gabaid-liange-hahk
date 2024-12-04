#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "redirect.h"

int redirIn(char * input) {
	int inp = open(input, O_WRONLY);
	dup2(inp, fileno(stdin));	
	close(inp);	
	return 0;
}

int undoIn(int save) {
	dup2(save, fileno(stdin));
	return 0;
}

int redirOut(char * target) {
	int tar = open(target, O_WRONLY);
	dup2(tar, fileno(stdout));
	close(tar);
	return 0;
}

int undoOut(int save) {
	dup2(save, fileno(stdout));
	return 0;
}
