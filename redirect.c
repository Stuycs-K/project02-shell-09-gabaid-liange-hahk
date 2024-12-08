#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "error.h"
#include "redirect.h"
#include "parse.h"

int redirIn(char * input) {
	int inp = open(input, O_RDONLY);
	dup2(inp, fileno(stdin));	
	close(inp);	
	return 0;
}

int undoIn(int save) {
	dup2(save, fileno(stdin));
	return 0;
}

int redirOut(char * target) {
	int tar = open(target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(tar, fileno(stdout));
	close(tar);
	return 0;
}

int undoOut(int save) {
	dup2(save, fileno(stdout));
	return 0;
}

void redirHandle(char ** args, struct parse_info info) {
	pid_t execFork = fork();
	int status;
	if (execFork < 0) {
		perror("fork failed\n");
		exit(1);
	} else if (execFork == 0) {
		int backup, backup2;
		if (info.rout_idx != -1) {
			backup = dup(fileno(stdout));
			redirOut(args[info.rout_idx + 1]);
			args[info.rout_idx] = NULL;
		}
		if (info.rin_idx != -1) {
			backup2 = dup(fileno(stdin));
			redirIn(args[info.rin_idx + 1]);
			args[info.rout_idx] = NULL;
		}
		int ret = execvp(args[0], args);
		if (info.rout_idx != -1) undoOut(backup);
		if (info.rin_idx != -1) undoIn(backup2);
		if (ret == -1) err();
	} else {
		wait(&status);
	}
}
