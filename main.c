#include <ncurses.h>
#include "main.h"
#define MINIAUDIO_IMPLEMENTATION
#include "./miniaudio.h"

ma_engine InitMiniaudio()
{
    ma_engine engine;
    ma_engine_init(NULL, &engine);
//  if (result != MA_SUCCESS) {
//      return -1;
//  }
    return engine;
}

void PrintChars(WINDOW *win, char text[])
{
    char *t;
    t = text;
    while(*t)
    {
        waddch(win, *t);
        t++;
        wrefresh(win);
        napms(100);
    }
}

int main(void)
{
    char text[] = "\"Get in.\"";

    
    ma_engine engine = InitMiniaudio(); 
    initscr();
    refresh();

    // window
    int half_lines = LINES / 2; 
    int half_cols = COLS / 2;
    int win_height = half_lines / 2;
    int win_width = half_cols / 2;
    WINDOW *win = newwin(half_lines, half_cols, win_height, win_width);

    PrintChars(win, text);
    ma_engine_play_sound(&engine, "BabyElephantWalk60.wav", NULL);

    wrefresh(win);
    wgetch(win);

    getch();
    ma_engine_uninit(&engine);
    endwin();
    return(0);
}
