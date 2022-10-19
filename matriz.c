#include <stdio.h>
#include <locale.h>

#define COL 5
#define ROW 5


void main(){
    setlocale(LC_ALL, "Portuguese");
    int i = 0;

    int matriz[ROW][COL];

    for (int c = 0; c < ROW; c++){
        for (int r = 0; r < COL; r++){
            printf("[%02d - %02d] ", r, c);
        }
        printf("\n");
    }

}
