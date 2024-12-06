.PHONY: clean run compile
compile: shell.o parse.o directory.o redirect.o error.o
	@gcc -o shell shell.o parse.o directory.o redirect.o error.o -lm
shell.o: shell.c
	@gcc -c -Wall shell.c
parse.o: parse.c parse.h
	@gcc -c -Wall parse.c
directory.o: directory.c directory.h
	@gcc -c -Wall directory.c
redirect.o: redirect.c redirect.h
	@gcc -c -Wall redirect.c
error.o: error.c error.h
	@gcc -c -Wall error.c
clean:
	@rm -f shell
	@rm -f *.o

run:
	@./shell
