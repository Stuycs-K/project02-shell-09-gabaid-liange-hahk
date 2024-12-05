#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "pipes.h"
//will use popen()
int pipe(){
  int status;
  int PATH_MAX = 256;
  char path[PATH_MAX];
  FILE *fp = popen("", "");
  if(fp == NULL){
    perror("fp is empty");
    exit(1);
  }

  while(fgets(path, PATH_MAX, fp) !=  NULL){

  }



  return 0;
}
