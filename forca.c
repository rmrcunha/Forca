#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"


char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void opening() {
    printf("***************************************\n");
    printf("*           Jogo da Forca             *\n");
    printf("***************************************\n");
}

void chuta() {

    char chute;
        scanf(" %c", &chute);

        chutes[chutesdados] = chute;
        chutesdados++;  
    
}

int jachutou(char letra) {
    int achou = 0;

    for(int j = 0; j<chutesdados; j++){

        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca(){
    for(int i = 0; i < strlen(palavrasecreta); i++){

            int achou = jachutou(palavrasecreta[i]);

            if(achou){
                printf("%c", palavrasecreta[i]);
            }   else {
                printf("_ ");
            }
            printf("_");
        }
        printf("\n");


}

void adicionapalavra(){

    char quer;

    printf("Voce deseja adicionar uma nova palavra ao jogo? (S/N)");
    scanf(" %c", &quer);

    if(quer == 'S'){

        char novapalavra[20];
        printf("Qual a nova palavra?");
        scanf("%s", novapalavra);


        FILE*f;

        f = fopen("palavra.txt", "r+");
        //r+ = leitura e escrita

        if(f == 0){
            printf("Desculpe, banco de dados não disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);
        
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra(){
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, banco de dados não disponivel\n\n");
        exit(1);
    }
    int qtddpalavras;
    fscanf(f, "%d", &qtddpalavras);

    srand(time(0));
    int randomico = rand() % qtddpalavras;

    for(int i = 0; i <= randomico; i++){
        fscanf(f,"%s", palavrasecreta);
    }

    fclose(f);
}


int acertou() {
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if (!jachutou(palavrasecreta[i])){
            return 0;
        }
    }

    return 1;
}

int enforcou() {

    int erros = 0;

        for (int i = 0; i < chutesdados; i++){
            int existe = 0;

            for(int j = 0; j < strlen(palavrasecreta); j++){
                if(chutes[i] == palavrasecreta[j]){
                    existe = 1;
                    break;
                }
            }

            if(!existe) erros++;
        }

        return erros >=5;
}


int main(){


    escolhepalavra();
    opening();

    
    do {
        //começo do jogo;
        desenhaforca();
        
        chuta();

    }   while (!acertou() && !enforcou());
    adicionapalavra();
}