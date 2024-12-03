#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "directory.h"

int changeDirect(char *path){
    if(path == NULL){
        char *home = "/home/username";
        return chdir(home);
    }

    return chdir(path);
}

void prompt(){
    int PATH_MAX = 256;
    char buff[PATH_MAX];
    char *cwd = getcwd(buff, PATH_MAX);
    if(cwd != NULL){
        printf("%s$ ", cwd);
	      fflush(stdout);
    }
    else{
        perror("getcwd fail");
    }
}
