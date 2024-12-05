.PHONY: clean run compile
<<<<<<< HEAD
compile: shell.o parse.o directory.o redirect.o
	@gcc -o shell shell.o parse.o directory.o redirect.o -lm
=======
compile: shell.o parse.o directory.o
	@gcc -o shell.out shell.o parse.o directory.o -lm
>>>>>>> 7e5d956fa6649ea5417a037d7c8ee2f2f8f9d6f0
shell.o: shell.c
	@gcc -c -Wall shell.c
parse.o: parse.c parse.h
	@gcc -c -Wall parse.c
directory.o: directory.c directory.h
	@gcc -c -Wall directory.c
redirect.o: redirect.c redirect.h
	@gcc -c -Wall redirect.c
clean:
	@rm -f shell.out
	@rm -f *.o
run:
<<<<<<< HEAD
	@./shell
=======
	@./shell.out
>>>>>>> 7e5d956fa6649ea5417a037d7c8ee2f2f8f9d6f0
