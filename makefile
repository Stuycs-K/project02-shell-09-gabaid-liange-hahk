.PHONY: clean run compile
compile: shell.o parse.o directory.o redirect.o error.o pipes.o
	@gcc -o shell.out shell.o parse.o directory.o redirect.o error.o pipes.o -lm
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
pipes.o: pipes.c pipes.h
	@gcc -c -Wall pipes.c
clean:
	@rm -f shell.out
	@rm -f *.o

run:
	@./shell.out
