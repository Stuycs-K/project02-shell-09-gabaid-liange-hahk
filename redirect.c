#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "redirect.h"

int redirIn(char * input) {
	/*
	Args: File name
	Return: 0 if succesful; calls err() if  not
	Use Case: Use to process '<' token; redirects stdin to a file
	*/
	int inp = open(input, O_RDONLY);
	if (inp == -1) err();
	if (dup2(inp, fileno(stdin)) == -1) err();	
	close(inp);	
	return 0;
}

int undoIn(int save) {
	/*
	Args: A saved file descriptor for stdin
	Return: 0 if succesful; calls err() if not
	Use Case: Used to process '<' token; undoes the redirect from redirIn()
	*/
	if (dup2(save, fileno(stdin)) == -1) err();
	return 0;
}

int redirOut(char * target) {
	/*
	Args: File name
	Return: 0 if successful; calls err() if not 
	Use Case: Used to proccess '>' token; redirects stdout to a file
	*/
	int tar = open(target, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tar == -1) err();
	if (dup2(tar, fileno(stdout)) == -1) err();
	close(tar);
	return 0;
}

int undoOut(int save) {
	/*
	Args: A saved file descriptor for stdout
	Return: 0 if successful; calls err() if not
	Use Case: Used to proccess '>' token; undoes the redirect from redirIn()
	*/
	if (dup2(save, fileno(stdout)) == -1) err();
	return 0;
}
