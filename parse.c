#include <unistd.h>
#include <string.h>
#include "directory.h"

int parse_args(char * line, char ** arg_ary) {
    int ret = -1;
	int index = 0;
	char * curr = line;
	char * token;
	while((token = strsep(&curr, " "))) {
		arg_ary[index] = token;
        if (ret == -1 && !strcmp(token, ">")) ret = index;
		index++;
	}
	arg_ary[index] = NULL;
    return ret;
}
