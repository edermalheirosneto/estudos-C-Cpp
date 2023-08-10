#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    char nome[60];
    int dia;
    int mes;
    int ano;
    char telefone[13];
}Contato;

void Escrever(char arq[]);
void Ler(char arq[]);
void AlterarContato(char arq[]);
void BuscarContato(char arq[]);
void Escolha(int num, char arq[]);

int main(){

    char arquivo[] = {"agenda.dat"};
    int esq;

    do{
        printf("\t\t AGENDA!! \n");
        printf("\t\t 01-ADICIONAR NOVO CONTATO \n");
        printf("\t\t 02-VER LISTA DE CONTATOS EXISTENTES\n");
        printf("\t\t 03-ALTERAR CONTATO EXISTENTE \n");
        printf("\t\t 04-SAIR \n");
        scanf("%d", &esq);

        setbuf(stdin, NULL);
        system("cls");

        Escolha(esq, arquivo);
    }while(esq != 4);


    return EXIT_SUCCESS;
}

void Escrever(char arq[]){

    FILE *file = fopen(arq, "ab");
    Contato contato;

    if(file){
        printf("PREENCHA OS DADOS A SEGUIR: \n");
        printf("DIGITE O NOME DO CONTATO \n");
        scanf("%59[^\n]", contato.nome);
        printf("DATA DE NASCIMENTO: (dd mm aaaa) \n");
        scanf("%d%d%d", &contato.dia, &contato.mes, &contato.ano);
        printf("TELEFONE: (xx)xxxxxxxxx \n");
        scanf("%s", contato.telefone);

        fwrite(&contato, sizeof(Contato), 1, file);
        fclose(file);

    }else{
        std::cout << "\n ERRO AO TENTAR ABRIR O ARQUIVO!!" << std::endl;
    }
}

void Ler(char arq[]){
    Contato contato;
    FILE *file = fopen(arq, "rb");

    if(file){
            while(!feof(file)){
                if(fread(&contato, sizeof(Contato), 1, file)){
                    printf("\n NOME: %s\n ANIVERSARIO: %d/%d/%d", contato.nome, contato.dia, contato.mes, contato.ano);
                    printf("\n TELEFONE: %s", contato.telefone);
                }
                printf("\n");
            }
            fclose(file);
    }else{
        std::cout << "ERRO AO TENTAR ABRIR O ARQUIVO" << std::endl;
    }
}

void AlterarContato(char arq[]){
    int i = 1;
    int id;
    Contato c;
    FILE *file = fopen(arq, "rb+");

    if(file){
        printf("\t LISTA DE CONTATOS: \n");
        printf("---------------------------------------- \n");

        while(fread(&c, sizeof(Contato), 1, file)){
            printf("\t %d =  %d/%d/%d \t %s \n",i, c.dia, c.mes, c.ano, c.nome);
            i++;
        }

        printf("DIGITE O INDICE DO CONTATO QUE IRA SER ALTERADO: \n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id <= 0 && id < i - 1){
            printf("DIGITE OS DADOS DO NOVO CONTATO: \n");
             printf("DIGITE O NOME DO CONTATO \n");
            scanf("%59[^\n]", c.nome);
            printf("DATA DE NASCIMENTO: (dd mm aaaa) \n");
            scanf("%d%d%d", &c.dia, &c.mes, &c.ano);
            printf("TELEFONE: (xx)xxxxxxxxx \n");
            scanf("%s", c.telefone);

            fseek(file, id * sizeof(Contato), SEEK_SET);
            fwrite(&c, sizeof(Contato), 1, file);
        }
        fclose(file);
    }else{
        std::cout << "O ARQUIVO NAO PODE SER CARREGADO:" << std::endl;
    }
}

void Escolha(int num, char arq[]){
    if(num == 1){
        Escrever(arq);
    }else if(num == 2){
        std::cout << "------------------------------------------------------------------------" << std::endl;
        std::cout << "                           CONTATOS SALVOS " << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;
        Ler(arq);
    }else if(num == 3){
        AlterarContato(arq);
    }else{
        std::cout << "OPCAO INVALIDA!!" << std::endl;
    }
}











