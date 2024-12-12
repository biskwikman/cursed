#include <ncurses.h>
#include "main.h"
#define MINIAUDIO_IMPLEMENTATION
#include "./miniaudio.h"

void InitMiniaudio(ma_engine *engine)
{
    ma_engine_init(NULL, engine);
//  if (result != MA_SUCCESS) {
//      return -1;
//  }
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
        napms(30);
    }
    wgetch(win);
    wclear(win);
}

int main(void)
{
    ma_engine engine;

    InitMiniaudio(&engine); 
    initscr();

    // window
    int half_lines = LINES / 2; 
    int half_cols = COLS / 2;
    int win_height = half_lines / 2;
    int win_width = half_cols / 2;
    WINDOW *dialog_win = newwin(half_lines, half_cols, win_height, win_width);
    WINDOW *status_win = newwin(1,COLS,LINES-1,1);
    
    waddstr(status_win,"scared"); 
    wrefresh(status_win);
    PrintChars(dialog_win, "\"Get in.\"");
    ma_engine_play_sound(&engine, "BabyElephantWalk60.wav", NULL);
    PrintChars(dialog_win, "\"Get in I said.\"");
    PrintChars(dialog_win, "\"I wornt hurt you if you jus get in.\"");

    ma_engine_uninit(&engine);
    endwin();
    return(0);
}
