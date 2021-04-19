#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE *fp;
    char disciplina[50];

    fp=fopen("disciplina.txt", "a+");

    printf("Disciplina: ");
    gets(disciplina);

    fputs(disciplina,fp);
    fputs("\n",fp);
   
    fclose(fp);

    return 0;
}