#include <stdio.h>
#include <stdlib.h>

void cadastrarAlunos();
void cadastrarDisciplina();
void visualizarAlunosDisciplinas();
void matricularAluno();
void visualizarMatriculas();
void flush_in();

int main (){
    int op;
    do{ 
        printf("------------------------------------------\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Cadastrar Disciplina\n");
        printf("3 - Visualizar Alunos e Disciplinas\n");
        printf("4 - Matricular Aluno\n");
        printf("5 - Visualizar Matriculas\n");
        printf("0 - Sair\n");
        printf("------------------------------------------\n-> ");
        scanf("%i", &op);
        flush_in();

        switch(op){
            case 1:
                cadastrarAlunos();
                break;
            case 2:
                cadastrarDisciplina();
                break;
            case 3:
                visualizarAlunosDisciplinas();            
                break;
            case 4:
                matricularAluno();
                break;
            case 5:
                visualizarMatriculas();
                break;
            case 0:
                printf("[TCHAU]");
                break;
            default:
                printf("Comando invalido\n\n");
        }
    } while (op != 0);
}

void cadastrarAlunos(){
    FILE *fp;
    char nome[50];

    fp=fopen("alunos.txt", "a+");
    printf("Aluno: ");
    
    gets(nome);
    
    fputs(nome,fp); 
    fputs("\n",fp);
    
    fclose(fp);
}

void cadastrarDisciplina(){
    FILE *fp;
    char disciplina[50];

    fp=fopen("disciplina.txt", "a+");

    printf("Disciplina: ");
    gets(disciplina);

    fputs(disciplina,fp);
    fputs("\n",fp);
   
    fclose(fp);
}

void visualizarAlunosDisciplinas(){
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
    printf("-----------------------\n");
   
    fclose(afp);
    fclose(dfp);
}

void matricularAluno(){
    FILE *mfp, *afp, *dfp;
    char c;
    int aluno, disciplina, cont = 1, flag = 0;

    afp=fopen("alunos.txt", "r");
    dfp=fopen("disciplina.txt", "r");
    mfp=fopen("matriculas.txt", "a+");

    printf("Digite a linha do aluno: ");
    scanf("%i", &aluno);
    
    printf("Digite a linha da disciplina: ");
    scanf("%i", &disciplina);
    
    do{
        c = fgetc(afp);
        if(c != '\n'){
            if (cont!=flag && c != EOF){
                if(cont == aluno && c != "\n"){
                    fputc(c, mfp);
                }
                flag=cont; 
            }else{
                if(cont == aluno && c != "\n"){
                    fputc(c, mfp);
                }
            } 
        }else{
            cont++;
        }
      
    } while (c != EOF);

    cont = 1;
    flag = 0;     
    
    fputs(" <=> ",mfp);

    do{
        c = fgetc(dfp);
        if(c != '\n'){
            if (cont!=flag && c != EOF){
                if(cont == disciplina && c != "\n"){
                    fputc(c, mfp);
                }
                flag=cont; 
            }else{
                if(cont == disciplina && c != "\n"){
                    fputc(c, mfp);
                }
            } 
        }else{
            cont++;
        }
      
    } while (c != EOF);
    fputs("\n",mfp);
    
    fclose(afp);
    fclose(dfp);
    fclose(mfp);
}

void visualizarMatriculas(){
    FILE *fp;
    char nome[50];
    char c;
    int cont=1, flag=0;

    fp=fopen("matriculas.txt", "a+");

    printf("MATRICULAS EFETUADAS\n");
    printf("-----------------------\n");

    do{
        c = fgetc(fp);
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
    printf("-----------------------\n");
   
    fclose(fp);
}

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}