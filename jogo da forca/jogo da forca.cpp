#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//JOGO DA FORCA

int main(){

    char palavraSecreta[50];
    char palavraDescobre[50];
    char letra = '*';
    int tamanho;
    int tentativas = 3;

    printf("DIGITE UMA PALAVRA:  \n");
    scanf("%s[^49\n]", palavraSecreta);

    setbuf(stdin, NULL);
    tamanho = strlen(palavraSecreta);

    printf("%d \n", tamanho);

    for(int i = 0; i < tamanho; i++){
            palavraDescobre[i] = letra;
    }

    printf("%s \n", palavraDescobre);

    system("cls");

    do{
        printf("DIGITE UMA LETRA: \t\t TENTATIVAS RESTANTES: %d \n %s\n", tentativas, palavraDescobre);
        letra = getchar();
        printf("%s \n", palavraDescobre);

        for(int i = 0; i < tamanho; i++){
            if(palavraSecreta[i] == letra){
                palavraDescobre[i] = letra;
            }
        }

        printf("%s \n", palavraDescobre);

        system("cls");


    }while(strcmp(palavraSecreta, palavraDescobre) > 0 && tentativas > 0);

    return 0;
}







