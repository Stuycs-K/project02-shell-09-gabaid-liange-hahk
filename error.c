#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void err(){
    /*
	Args: None
	Return: Void
	Use Case: Runs when other code errors; Prints errno and exits
	*/
    printf("Error: %s\n",strerror(errno));
    exit(1);
}