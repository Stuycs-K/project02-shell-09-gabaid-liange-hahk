#include <stdio.h>
#include "parse.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "directory.h"
#include "redirect.h"
#include "pipes.h"
#include "error.h"

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
			printf("\n");
			break; // tested - this gets rid of the duplicate prompts
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		if (!strcmp(buffer, "exit")) {
			running = 0;
			break; //added one here too just in case
		} else {
			char * token;
			char * buff = buffer;
			while ((token = strsep(&buff, ";"))) {
				if (!strcmp(token, "\0")) continue;
 				if (strchr(token, '|')) {
					char * t = strsep(&token, "|");
					pipeHandle(t, strsep(&token, "|") + 1);
				} else {
					struct parse_info info = parse_args(token, args);
					if (!strcmp(args[0], "cd")) {
						if (args[1] != NULL) {
							changeDirect(args[1]);
						} else {
							changeDirect(NULL);
						}
					} else redirHandle(args, info);
				}
			}
		}
	}
	printf("exit\n");
	exit(0);
}
