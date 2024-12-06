#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int err(){
    printf("Error: %s\n",strerror(errno));
    exit(1);
}