#include <stdio.h>
#include <stdlib.h>

int main (){

    FILE *afp;
    FILE *dfp;
    char c;
    int cont=1, flag=0;

    afp=fopen("alunos.txt", "a+");
    dfp=fopen("disciplina.txt", "a+");

    printf("ALUNOS CADASTRADOS\n");
    printf("-----------------------\n");

    do{
        c = fgetc(afp);
        if(c != '\n'){
            if (cont!=flag && c != EOF){
                printf("%i - %c",cont, c);
                flag=cont; 
            }else{
                printf("%c",c);
            } 
        }else{
            cont++;
            printf("%c",c);
        }
      
    } while (c != EOF);

    cont = 1;
    flag = 0;
    printf("-----------------------\n");
    printf("\nDISCIPLINAS CADASTRADAS\n");
    printf("-----------------------\n");

    do{
        c = fgetc(dfp);
        if(c != '\n'){
            if (cont!=flag && c != EOF){
                printf("%i - %c",cont, c);
                flag=cont; 
            }else{
                printf("%c",c);
            } 
        }else{
            cont++;
            printf("%c",c);
        }
      
    } while (c != EOF);
    printf("-----------------------");
   
    fclose(afp);
    fclose(dfp);
    
    return 0;
}