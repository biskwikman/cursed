all:
	gcc -lncurses -lpthread -lm -ldl main.c
	./a.out
