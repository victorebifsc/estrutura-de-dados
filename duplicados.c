#include <stdio.h>

#define MAX 999

void main(){

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
        printf("%d aparece %d vezes\n", uniqueNumbers[a], ocurrences);
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
