#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "pipes.h"
#include "parse.h"

void pipeHandle(char *token) {
  char *commandOne = strsep(&token, "|");
  char *commandTwo = strsep(&token, "|");

  if(commandOne == NULL || commandTwo == NULL){
    perror("pipe fail");
    exit(1);
  }

  char *argsOne[100], *argsTwo[100];
  parse_args(commandOne, argsOne);
  parse_args(commandTwo, argsTwo);

  FILE *pipeOne = popen(commandOne, "r");
  if(pipeOne == NULL){
    perror("first commmand fail");
    exit(1);
  }

  FILE *pipeTwo = popen(commandTwo, "w");
  if(pipeTwo == NULL){
    perror("second command fail");
    exit(1);
  }

  char buffer[1024];
  int bytesRead;
  while((bytesRead = fread(buffer, 1, sizeof(buffer), pipeOne)) > 0){
    fwrite(buffer, 1, bytesRead, pipeTwo);
  }

  pclose(pipeOne);
  pclose(pipeTwo);
}
