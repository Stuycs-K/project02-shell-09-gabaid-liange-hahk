#include <unistd.h>
#include <string.h>

void parse_args(char * line, char ** arg_ary) {
	int index = 0;
	char * curr = line;
	char * token;
	while((token = strsep(&curr, " "))) {
		arg_ary[index] = token;
		index++;
	}
	arg_ary[index] = NULL;	
}
