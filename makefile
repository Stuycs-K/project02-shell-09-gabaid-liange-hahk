.PHONY: clean run compile
compile: shell.o parse.o directory.o
	@gcc -o shell shell.o parse.o directory.o -lm
shell.o: shell.c
	@gcc -c -Wall shell.c
parse.o: parse.c parse.h
	@gcc -c -Wall parse.c
directory.o: directory.c directory.h
	@gcc -c -Wall directory.c
clean:
	@rm -f shell
	@rm -f *.o
run:
	@./shell