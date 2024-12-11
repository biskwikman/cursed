all:
	gcc -lncurses -lpthread -lm -ldl main.c `pkg-config --cflags --libs sdl3`
