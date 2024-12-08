#ifndef PARSE_H
#define PARSE_H
struct parse_info {
    int rin_idx;
    int rout_idx;
    int pipe_idx;
};

struct parse_info parse_args(char * line, char ** arg_ary);
#endif
