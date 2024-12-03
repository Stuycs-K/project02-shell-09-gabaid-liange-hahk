#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int changeDirect(char *path){
    if(path == NULL){
        char *home = "placeholder";
        return chdir(home);
    }

    return chdir(path); 
}

void prompt(){
    int PATH_MAX = 100;
    char buff[PATH_MAX];
    char *cwd = getcwd(buff, PATH_MAX);  
    if(cwd != NULL){
        //char *home = "placeholder";
        printf("%s$ ", cwd);
    }
    else{
        perror("getcwd fail");
    }
}
