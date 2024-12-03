#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int directory(char *path){
  char buff[PATH_MAX];
  char * cwd = getcwd(buff, PATH_MAX);

  if(cwd == NULL){
    perror("cwd failed");
  }
  else{
    printf("Current directory is %s", cwd);
  }

  return 0;
}
