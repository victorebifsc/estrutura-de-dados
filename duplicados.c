#include <stdio.h>
#include <stdlib.h>


#define MAX 999

void main(){
    system("");

    int number = 1;
    int numbers[MAX];
    int uniqueNumbers[MAX];

    int nSize = 0;
    int uSize = 0;

    while (number != 0){
        scanf("%d", &number);
        numbers[nSize] = number;
        if (number != 0){
            nSize++;
        }
    }
    system("cls");

    for(int a = 0; a < nSize; a++){
        int ocurrences = 0;
        for(int b = 0; b < uSize; b++){
            if (numbers[a] == uniqueNumbers[b]){
                ocurrences++;
            }
        }
        if (!ocurrences){
            uniqueNumbers[uSize] = numbers[a];
            uSize++;
        }
    }

    for (int a = 0; a < uSize; a++){
        int ocurrences = 0;
        for (int b = 0; b < nSize; b++){
            if (uniqueNumbers[a] == numbers[b]){
                ocurrences++;
            }
        }
        if (ocurrences > 1){
            printf("\e[1;91m");
        }
        else{
            printf("\e[1;92m");
        }
        printf("o valor %6d aparece %6d vezes", uniqueNumbers[a], ocurrences);
        printf("\e[0m\n");
    }


    /*
    for(int i = 0; i < uSize; i++){
        printf("%d ", uniqueNumbers[i]);
    }
    printf("\n");
    for(int i = 0; i < nSize; i++){
        printf("%d ", numbers[i]);
    }
    */
}
