#include <stdlib.h>
#include <stdio.h>

//Snake game field size
#define COLS 63
#define ROWS 30

int main(){

    //Hide cursor
    printf("\e[?25l");

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

            printf("\e[%iA", ROWS + 2);
    }

    return 0;
}