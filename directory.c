#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include "directory.h"
#include "error.h"

void changeDirect(char *path){
    /*
	Args: Name of path
	Return: Void; calls err() if error
	Use Case: Changes directory to inputed path
	*/
    int PATH_MAX = 256;
    char home[PATH_MAX];

    if(path == NULL || strcmp(path, "~") == 0){
        struct passwd *pw = getpwuid(getuid()); //found this command that gets user id, then gets password, allwos for home directory access. maybe theres a better way?
        strcpy(home, pw->pw_dir);
        //^pw_dir is basically the path to the home directory
        path = home;
    }
    printf("\n"); // remove this later but right now it formats the lines.txt properly
    if (chdir(path) == -1) err();
}

void prompt(){
    /*
	Args: None
	Return: Void; perrors if error
	Use Case: Prints the directory prompt for the user
	*/
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
