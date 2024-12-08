#include <unistd.h>
#include <string.h>
#include "directory.h"
#include "parse.h"

struct parse_info parse_args(char * line, char ** arg_ary) {
	/*
	Args: Command string and arg array
	Return: Struct of chosen token locations
	Use Case: Goes through the command string and finds locations of '<', '>', and '|' operators
	*/
    struct parse_info ret;
    ret.rout_idx = ret.rin_idx = -1;
    ret.pipe_idx = NULL;
	int index = 0;
	char * curr = line;
	char * token;
	while((token = strsep(&curr, " "))) {
		arg_ary[index] = token;
        if (ret.rout_idx == -1 && !strcmp(token, ">")) ret.rout_idx = index;
        else if (ret.rin_idx == -1 && !strcmp(token, "<")) ret.rin_idx = index;
        else if (ret.pipe_idx == NULL && !strcmp(token, "|")) ret.pipe_idx = token;
		index++;
	}
	arg_ary[index] = NULL;
    return ret;
}
