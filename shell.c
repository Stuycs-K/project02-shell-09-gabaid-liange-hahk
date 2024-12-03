#include <stdio.h>
#include "parse.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "directory.h"

int main() {
	char buffer[500];
	char * args[50];
	int running = 1;
	pid_t execFork;
	int status;

	while (running) {
		prompt();
		char * readCommand = fgets(buffer, 499, stdin);
		if (readCommand == NULL) {
			running = 0;
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		if (!strcmp(buffer, "exit")) {
			running = 0;
		} else {
			parse_args(buffer, args);
			if (!strcmp(args[0], "cd")) {
				if (args[1] != NULL) {
					changeDirect(args[1]);
				} else {
					changeDirect("~");
				}
 			} else {
				execFork = fork();
				if (execFork < 0) {
					perror("fork failed\n");
					exit(1);
				} else if (execFork == 0) {
					execvp(args[0], args);
				} else {
					wait(&status);
				}
			}
		}
	}
	printf("exit\n");
	exit(0);	
}
