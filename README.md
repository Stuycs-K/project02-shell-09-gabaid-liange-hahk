[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Tfg6waJb)
# Systems Project2 - MyShell

Members: Daniel Gabai, Edmund Liang, Keith Hah

Creative Team Name: Can't segfault if you can't read

Features implemented:

- User input
- Parsing the user input line to separate the command from its arguments
- Forking for each command and having the child execvp that command
- Waiting until the exec'd program exits before going back to user input
- Semicolons to separate commands
- Prompt includes the cwd path
- cd changes the current working directory
- Quitting the shell with exit or Ctrl+D
- Redirection and pipes with >, <, and |

Attempted features:

Bugs:

Function headers:
- directory.h
  - `void changeDirect(char * path);`
  - `void prompt();`
- error.h
  - `void err();`
- parse.h
  - `struct parse_info parse_args(char * line, char ** arg_ary);`
- pipes.h
  - `void pipeHandle(char * commandOne, char * commandTwo);`
- redirect.h
  - `void redirIn(char * input);`
  - `void undoIn(int save);`
  - `void redirOut(char * target);`
  - `void undoOut(int save);`
  - `void redirHandle(char ** args, struct parse_info info);`
- shell.c
  - `int main();`
