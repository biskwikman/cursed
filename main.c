#include <ncurses.h>
#define MINIAUDIO_IMPLEMENTATION
#include "./miniaudio.h"

#define PINK 1


void printChars(char text[])
{
    char *t;
    t = text;
    while(*t)
    {
        addch(*t);
        t++;
        refresh();
        napms(100);
    }
}

int main()
{
    char text[] = "Get in.";

    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }
    
    initscr();
    refresh();

    // window
    int half_lines = LINES / 2; 
    int half_cols = COLS / 2;
    int win_height = half_lines / 2;
    int win_width = half_cols / 2;
    WINDOW *win = newwin(half_lines, half_cols, win_height, win_width);
    box(win, 0, 0);

    start_color();
    init_color(PINK,1000,750,750);
    init_pair(1,PINK,COLOR_BLACK);
    attrset(COLOR_PAIR(1));

    printChars(text);
    wmove(win,1,1);
    waddstr(win, "windowwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
    ma_engine_play_sound(&engine, "BabyElephantWalk60.wav", NULL);

    wrefresh(win);
    wgetch(win);

    getch();
    ma_engine_uninit(&engine);
    endwin();
    return(0);
}
