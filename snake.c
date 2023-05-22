#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

//Snake game field size
#define COLS 63
#define ROWS 30

int main(){

    //Hide cursor
    printf("\e[?25l");

    //Switch to cannonical mode, disable echo
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_cflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);


    int x[1000], y[1000];
    int quit = 0;
    while(!quit){
        //Game box/field
        printf("┌");
        for(int i=0; i<COLS; i++){
            printf("─");
        }
        printf("┐\n");

        for (int j=0; j<ROWS; j++){
            printf("│");
            for(int i=0; i<COLS; i++){
                printf(" ");
            }
            printf("│\n");
        }

        printf("└");
        for(int i=0; i<COLS; i++){
            printf("─");
        }
        printf("┘\n");

        //Move cursor to top
        printf("\e[%iA", ROWS + 2);

        int head = 0, tail = 0; 
        x[head] = COLS / 2;
        y[head] = ROWS / 2;
        int gameover = 0;
        int xdir = 1, ydir = 0;

        while(!quit && !gameover){
            //Clear snake tail(check for errors here later)
            printf("\e[%iB\e[%iC ", y[tail] + 1, x[tail] + 1);
            printf("\e[%iF",y[tail] + 1);

            tail = (tail + 1) % 1000;
            int newhead = (head +1) % 1000;
            x[newhead] = (x[head] + xdir + COLS) % COLS;
            y[newhead] = (y[head] + ydir + ROWS) % ROWS;
            head = newhead;

            //Draw snake head
            printf("\e[%iB\e[%iC▓", y[head] + 1, x[head] + 1);
            printf("\e[%iF", y[head] + 1);

            usleep(5 * 10000000 / 60);

            //Read keyboard input
            int ch = getchar();
        }
    }

    //Show cursor
    printf("\e[?25h");

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}