#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "error.h"
#include "redirect.h"
#include "parse.h"
#include "error.h"

void redirIn(char * input) {
	/*
	Args: File name
	Return: Void; calls err() if error
	Use Case: Use to process '<' token; redirects stdin to a file
	*/
	int inp = open(input, O_RDONLY);
	if (inp == -1) err();
	if (dup2(inp, fileno(stdin)) == -1) err();	
	close(inp);	
}

void undoIn(int save) {
	/*
	Args: A saved file descriptor for stdin
	Return: Void; calls err() if error
	Use Case: Used to process '<' token; undoes the redirect from redirIn()
	*/
	if (dup2(save, fileno(stdin)) == -1) err();
}

void redirOut(char * target) {
	/*
	Args: File name
	Return: Void; calls err() if error 
	Use Case: Used to proccess '>' token; redirects stdout to a file
	*/
	int tar = open(target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tar == -1) err();
	if (dup2(tar, fileno(stdout)) == -1) err();
	close(tar);
}

void undoOut(int save) {
	/*
	Args: A saved file descriptor for stdout
	Return: Void; calls err() if error
	Use Case: Used to proccess '>' token; undoes the redirect from redirIn()
	*/
	if (dup2(save, fileno(stdout)) == -1) err();
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
