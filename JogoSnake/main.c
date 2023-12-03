#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


int gameOver;
const int width = 20;
const int height = 20;
int x;
int y;
int tailX[100];
int tailY[100];
int nTail = 0;
int foodPosX, foodPosY;

enum eDirection{
    STOP = 0, LEFT, RIGHT, UP, DOWN
};
enum eDirection dir;



void Setup(){
    gameOver = 0;
    dir = STOP;
    x = width/2;
    y = height/2;
    foodPosX = rand()%width;
    foodPosY = rand()%height;
}

void Draw(){
    system("cls");

    for(int i = 0; i < width+1; i++){
        printf("#");
    }
     printf("\n");

     for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j == 0){
                printf("#");
            }
            if(i == y && j == x){
                printf("O");
            }
            else if(i == foodPosY && j == foodPosX){
                printf("f");
            }
            else{
                int print = 0;
                for(int k = 0; k < nTail; k++){
                    if(tailX[k] == j && tailY[k] == i){
                        printf("o");
                        print = 1;
                    }
                }
                if(!print){
                        printf(" ");
                    }
            }
            if(j == width-1){
                printf("#");
            }
        }
        printf("\n");
     }

    for(int i = 0; i < width+1; i++){
        printf("#");
    }
    printf("\n");
}

void Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case  'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void Logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X;
    int prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i =1; i < nTail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if(x > width || x < 0 || y > height || y < 0){
        gameOver = 1;
    }
    if(x == foodPosX && y == foodPosY){
        foodPosX = rand()%width;
        foodPosY = rand()%height;
        nTail++;
    }
}



int main()
{
    Setup();

    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(100);
    }

    return 0;
}
