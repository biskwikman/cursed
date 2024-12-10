#include <ncurses.h>

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
    int col, row;
    int centerCol;    
    char text[] = "Get in.";

    initscr();
    getmaxyx(stdscr,row,col);
    centerCol = col / 2;
    start_color();

    init_color(PINK,1000,750,750);
    init_pair(1,PINK,COLOR_BLACK);
    attrset(COLOR_PAIR(1));

    move(10,centerCol);
    printChars(text);

    getch();
    endwin();
    return(0);
}
