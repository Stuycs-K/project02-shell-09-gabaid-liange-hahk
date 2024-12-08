#include <unistd.h>
#include <string.h>
#include "directory.h"
#include "parse.h"

struct parse_info parse_args(char * line, char ** arg_ary) {
	/*
	Args: Command string and arg array
	Return: Struct of chosen token locations
	Use Case: Goes through the command string and parses into tokens by spaces and finds locations of '<' and '>' operators
	*/
    struct parse_info ret;
    ret.rout_idx = ret.rin_idx = -1;
	int index = 0;
	char * curr = line;
	char * token;
	while((token = strsep(&curr, " "))) {
		arg_ary[index] = token;
        if (ret.rout_idx == -1 && !strcmp(token, ">")) arg_ary[ret.rout_idx = index] = NULL;
        else if (ret.rin_idx == -1 && !strcmp(token, "<")) arg_ary[ret.rin_idx = index] = NULL;
		index++;
	}
	arg_ary[index] = NULL;
    return ret;
}
