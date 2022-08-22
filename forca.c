#include <stdio.h>
#include <string.h>

int main(){
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;
    do {
        //começo do jogo;
        for(int i = 0; i < strlen(palavrasecreta); i++){
            int achou = 0;

            printf("Estou vendo a letra secreta %d = %c\n",i, palavrasecreta[i]);

            for(int j = 0; j<tentativas; j++){

                printf("-> Chute %d = %c\n",j);

                if(chutes[j] == palavrasecreta[i]){
                    printf("---> chute correto!\n");
                    achou = 1;
                    break;
                }
            }

            if(achou){
                printf("%c", palavrasecreta[i]);
            }   else {
                printf("_ ");
            }
            printf("_");
        }
        printf("\n");
        char chute;
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;        

    }   while (!acertou && !enforcou);
    
}