#include <stdio.h>
#include <string.h>

int main(){
    char palavrasecreta[20];

    sprintf(palavrasecreta, "MELANCIA");

    palavrasecreta[8] = '\0';

    int acertou = 0;
    int enforcou = 1;

    do {
        //começo do jogo;

        char chute;
        scanf("%c", &chute);

        for(int i = 0; i < strlen(palavrasecreta); i++){
            if(palavrasecreta[i] == chute) {
                printf("A posicao %d tem essa letra!\n", i);
            }
        }

    }   while (!acertou && !enforcou);
    
}