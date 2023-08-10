#include <iostream>
#include <graphics.h>
#include <unistd.h>
#include <time.h>
#include <vector>
#include <windows.h>
#include <conio.h>

#define TELA_X 1890
#define TELA_Y 1050
#define VELOCIDADE 1


class Bolha{
public:
    int posX;
    int posY;
    int color;
    int raio;
    Bolha(int px, int py, int cr, int r);
    void Movimento(int x, int y, int cor, int radius);
private:
};

Bolha::Bolha(int px, int py, int cr, int r){
    posX = px;
    posY = py;
    color = cr;
    raio = r;
    Movimento(posX, posY, color, raio);
}

void Bolha::Movimento(int x, int y, int cor, int radius){

    setfillstyle(SOLID_FILL, cor);
    fillellipse(x, y, radius, radius);

}

//----------------------------------------------------------------------------------------------------------------------------------------------------//

int main(){

int quantidade;
int raio = 40;


std::cout << " DIGITE QUANTAS BOLINHAS EXIBIRAM NA TELA: "<< std::endl;
std::cin >>quantidade;

std::cout << " CARREGANDO.....";

sleep(3);

srand((unsigned)time(NULL));

initwindow(TELA_X, TELA_Y, " ");

int vetor[quantidade];
int contVelocidade[quantidade];

for(int i = 0 ; i < quantidade; i++){
    vetor[i] = 30 + rand()%TELA_Y;
    contVelocidade[i] = rand() % 8;
}

    int controlex[quantidade];
    int controley[quantidade];
    int eixoX[quantidade];
    int eixoY[quantidade];

    for(int i = 0; i < quantidade; i++){
        eixoY[i] = vetor[i];
        eixoX[i] = vetor[i];
        controlex[i] = rand()% 2;
        controley[i] = rand() % 2;
    }

    std::vector<Bolha> bola;

    int color[quantidade];

    for(int i = 0; i < quantidade; i++){
        color[i] = rand()%7400000;
    }
//------------------------------------------------------------------------------------------------------------------------------------------------//
    while(true){
            delay(1);
            cleardevice();

             for(int q = 0; q < quantidade; q++){
                Bolha *p = new Bolha(eixoX[q], eixoY[q], color[q], raio);
                bola.push_back(*p);
            }

             for(int i = 0; i < quantidade; i++){
               if((eixoX[i]+raio <= TELA_X || eixoX[i]-raio <= TELA_X) && controlex[i] == 0){
                    eixoX[i] += VELOCIDADE*contVelocidade[i];
               }
               if(eixoX[i]+raio >= TELA_X || eixoX[i]-raio >= TELA_X){
                    controlex[i] = 1;
               }
               for(int j = 0; j < quantidade; j++){
                    if((eixoY[j]+raio <= TELA_Y || eixoY[j]-raio <= TELA_Y) && controley[j] == 0){
                        eixoY[j] += VELOCIDADE;
                    }
               }
               for(int j = 0; j < quantidade; j++){
                    if(eixoY[j]+raio >= TELA_Y || eixoY[j]-raio >= TELA_Y){
                        controley[j] = 1;
                    }
               }
               for(int j = 0; j < quantidade; j++){
                    if((eixoY[j]+raio >= 0 || eixoY[j]-raio >= 0)&& controley[j] == 1){
                        eixoY[j] -= VELOCIDADE;
                    }
               }
               for(int j = 0; j < quantidade; j++){
                    if(eixoY[j]+raio <= 0 || eixoY[j]-raio <= 0){
                        controley[j] = 0;
                    }
               }
             }
//=============================================================================================================================================//
//==============================================================================================================================================//
            for(int i = 0; i < quantidade; i++){
               if((eixoX[i]+raio >= 0 || eixoX[i]-raio >= 0)  && controlex[i] == 1){
                    eixoX[i] -= VELOCIDADE*contVelocidade[i];
               }
               if(eixoX[i]+raio <= 0 || eixoX[i]-raio <=0){
                    controlex[i] = 0;
               }
             }
            for(int i = 0; i < bola.size(); i++){
                    bola[i];
            }
    }

closegraph();

return EXIT_SUCCESS;
}

























