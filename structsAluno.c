#include <stdio.h>

typedef struct {
    int matricula;
    char nome[50];
    float altura;
    char sexo;
} tAluno;

void printAluno(tAluno a){

    printf("Nome: %s\n", a.nome);
    printf("Matricula: %d\n", a.matricula);
    printf("Altura: %f\n", a.altura);
    printf("Sexo: %c\n", a.sexo);
    printf("\n");
}

void main(){

    int i, qtde;
    tAluno vAluno[999];

    printf("Quantos alunos: ");
    scanf("%d", &qtde);

    for(int i = 0; i < qtde; i++){

        printf("Aluno %d...\n", i+1);
        fflush(stdin);
        printf("Nome: ");
        gets(vAluno[i].nome);
        printf("Matricula: ");
        scanf("%d", &vAluno[i].matricula);
        printf("Altura: ");
        scanf("%f", &vAluno[i].altura);

        fflush(stdin);
        printf("Sexo: ");
        scanf("%c", &vAluno[i].sexo);
        printf("\n");
    }

    for(int i = 0; i < qtde; i++){
        printAluno(vAluno[i]);
    }

}
