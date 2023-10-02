#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

#define true 1
#define false 0

typedef struct Carro{
    char modelo[50];
    char fabricante[50];
    struct Carro *proxCarro;
}Carro;

void MostrarVeiculo(Carro *p){
    if(p != NULL){
        char nome[50];
        char marca[50];

        strcpy(nome, p->modelo);
        strcpy(marca, p->fabricante);

        for(int i = 0; i < sizeof(nome); i++)
            nome[i] = toupper(nome[i]);

        for(int i = 0; i < sizeof(marca); i++)
            marca[i] = toupper(marca[i]);


        printf("VEICULO: \n");
        printf("\t MODELO:      %s \n",nome);
        printf("\t FABRICANTE:  %s \n",marca);
        MostrarVeiculo(p->proxCarro);
    }
    else{
        printf("------------------------------------------------------ \n");
    }


}

void CadastrarVeiculo(Carro *p){
    Carro *veiculo;
    char nome[50];
    char marca[50];
    veiculo = malloc(sizeof(Carro));

    printf("CADASTRO DE NOVO VEICULO \n");
    printf("DIGITE O MODELO DO VEICULO: \n");
    gets(nome);
    printf("DIGITE A FABRICANTE DO VEICULO: \n");
    gets(marca);

    strcpy(veiculo->modelo, nome);
    strcpy(veiculo->fabricante, marca);

    veiculo->proxCarro = p->proxCarro;
    p->proxCarro = veiculo;
}

void ExcluirVeiculo(Carro *p){
    Carro *procura;
    Carro *apaga;
    char opcao[50];

    procura = p;
    apaga = p->proxCarro;

    printf("QUAL VEICULO DEVE SER ESCLUIDO DA LISTA?? (modelo) \n");
    gets(opcao);

    printf(" O VEICULO A SER EXCLUIDO SERA:   %s \n", opcao);

    while(apaga != NULL && apaga->modelo != opcao){
        procura = apaga;
        apaga = apaga->proxCarro;
    }
    if(apaga != NULL){
        procura->proxCarro = apaga->proxCarro;

        free(apaga);
    }
}

int main(){

    int opcao;
    Carro *carro;
    carro = malloc(sizeof(Carro));
    carro->proxCarro = NULL;

    while(true){
        system("cls");
        printf("MENU \n");
        printf("01 - MOSTRAR VEICULOS CADASTRADOS: \n");
        printf("02 - CADASTRAR NOVO VEICULO: \n");
        printf("03 - EXCLUIR VEICULO: \n");
        printf("04 - SAIR \n");
        scanf("%d", &opcao);

        setbuf(stdin, NULL);



        switch(opcao){
            case 01:
                system("cls");
                MostrarVeiculo(carro->proxCarro);
                system("pause");
                break;
            case 02:
                system("cls");
                CadastrarVeiculo(carro);
                break;
            case 03:
                system("cls");
                MostrarVeiculo(carro->proxCarro);
                ExcluirVeiculo(carro);
                break;
            case 04:
                return false;
            default:
                printf("ESSA OPCAO NAO E VALIDA \n");
        }
    }

    return 0;
}



















