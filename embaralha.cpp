#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int verifica_palavra(char palavra[]){

    for (int i = 0; palavra[i] != '\0'; ++i)
    {
        if (!isalpha(palavra[i]) || palavra[i] == ' ')
        {
            return 0;
        }
    }
    return 1;
}

void le_palavra(char palavra[],int tam_min, int tam_max){

    do
    {
        printf("\nDigite a palavra desejada: ");
        gets(palavra);

        if ((strlen(palavra) < tam_min || strlen(palavra) > tam_max) && palavra[0] != '\0')
            printf("Quantidade minima 5 letras e maxima 50 letras.\n");
    }
    while((strlen(palavra) < tam_min || strlen(palavra) > tam_max) && palavra[0] != '\0');
}

void embaralha(char palavra[])
{
    int r, l = strlen(palavra);
    srand(time(NULL));

    for (int i = 0; i < l; i++)
    {
        r = rand()%(l-i);
        putchar(palavra[r]);
        memmove(palavra+r,palavra+r+1,l-r);
    }
}

int main(){

    char palavra[51];

    do{
        if(verifica_palavra(palavra))
        {
            if(palavra[0] != '\0'){
            printf("%s\n", palavra);
            embaralha(palavra);
            }
        }
        else
        {
            printf("Nao e uma palavra, Digite Novamente.\n");
        }
    le_palavra(palavra,5, 50);
    }while(palavra[0] != '\0');

    return 0;
}
