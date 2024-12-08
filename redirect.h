#ifndef REDIRECT_H
#define REDIRECT_H

#include "parse.h"

int redirIn(char * input);
int undoIn(int save);
int redirOut(char * target);
int undoOut(int save);
void redirHandle(char ** args, struct parse_info info);

#endif
