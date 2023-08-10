#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>



typedef enum{

    BLACK, BLUE, GREEN, RED, MAGENTA, BROWN, GRAY

    } COLORS;

static int _BACKGROUND = 2;
static int _CORDOTEXTO = GREEN;

void TextColor(int letra, int fundo);
void gotoxy(int eixoX, int eixoY);


class Menu{

    public:
      void MostrarMenu(int t);
    protected:
     int teste;
};

void Menu::MostrarMenu(int t){

    int pos = 10;
    std::string menu[4];

    menu[0] = "LOGIN";
    menu[1] = "CADASTRAR";
    menu[2] = "OPCOES";
    menu[3] = "FECHAR";


    for(int i = 0; i < 4; i ++){
        gotoxy(40, pos);
        if(t == pos){
            TextColor(4, 6);
        }else{
            TextColor(3, 0);
        }
        std::cout << menu[i] << std::endl;
        pos++;
    }
}


int main(){

    int pos = 10, mov;

    Menu *menu = new Menu();


    while(1){

        menu->MostrarMenu(pos);

        mov = getch();

        if(mov == 115){
            if(pos < 13){
                pos ++;
            }
        }if(mov == 119){
            if(pos > 10){
                pos--;
            }
        }
    }

    return 0;
}




void TextColor(int letra, int fundo){

    _CORDOTEXTO = letra;
    _BACKGROUND = fundo;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + (_BACKGROUND << 4));

}


void gotoxy(int eixoX, int eixoY){

    COORD coord;
        coord.X = eixoX;
        coord.Y = eixoY;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}




































