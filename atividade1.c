#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE *fp;
    char nome[50];

    fp=fopen("alunos.txt", "a+");

    printf("Aluno: ");
    gets(nome);
    
    fputs(nome,fp); 
    fputs("\n",fp);
    
    fclose(fp);

    return 0;
}