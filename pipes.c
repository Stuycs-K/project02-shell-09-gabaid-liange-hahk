#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "pipes.h"
#include "parse.h"
#include "redirect.h"

void pipeHandle(char * commandOne, char * commandTwo) {
  /*
	Args: Pointers to where the commands to the left and right of the pipe symbol start
	Return: Void; perrors if error
	Use Case: Uses a temp file to implement pipes
	*/

  if(commandOne == NULL || commandTwo == NULL){
    perror("pipe fail");
    exit(1);
  }

  char c1[100]; strcpy(c1, commandOne);
  char c2[100]; strcpy(c2, commandTwo);
  char t1[] = "> TEMP";
  char t2[] = " < TEMP";
  strcat(c1, t1);
  strcat(c2, t2);

  char * a1[50];
  char * a2[50];
  struct parse_info info = parse_args(c1, a1);
  redirHandle(a1, info);
  info = parse_args(c2, a2);
  redirHandle(a2, info);
  remove("TEMP");
}
