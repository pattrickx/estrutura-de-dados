/*

Esse Ã© o Labirinto '2.0'
W - Cima
A - Esquerda
S - Baixo
D - Direita
Q - Sair

Como todo bom labirinto , esse pode gerar mapas em que vocÃª fica impossibilitado de Chegar AtÃ© o # (O Boneco Ã© o @)(QUASE IMPOSSÃVEL)

DefiniÃ§Ãµes

Parede = (=)(VocÃª NÃ£o Pode Passar );
Grama = (.)(VocÃª Pode Passar);
ChÃ£o = (EspaÃ§o em Branco) (VocÃª Pode Passar)

A Biblioteca <graphics.h> aqui foi usado apenas para o getChar();, mas caso vocÃªs nÃ£o tenham , apenas modifique de getChar(); para getCharar();

VersÃ£o 2.0 ; VersÃ£o 3.0 Com o Uso Das Setas do Teclado (Ou NÃ£o ...)

*/
#include <stdio.h>
#include <time.h>
#include <windows.h>
#ifdef __cplusplus__
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}
#else
#include <conio.h>
#endif

#include <iostream>

using namespace std;
int getChar(){
    while(!kbhit());
    int c = getchar();
    return c;
}

/* Definicoes, para facilitar o uso da funcao para desenhar o mapa */
#define CHAO 0
#define PAREDE 1
#define VOCE 2
#define GRAMA 3
#define SAIDA 4

#define ACIMA 119
#define ABAIXO 115
#define DIREITA 100
#define ESQUERDA 97

#define Q 113
/*Outras definiÃ§Ãµes para tratamento de erros*/
#define OK 1
#define ERRO 2

int coluna_atual = 1, linha_atual = 1, key, passos;

int mapa[10][20] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int mapa2[10][20] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int automov(){
    int d = rand() % 4;
    //cout<<d<<endl;
    if(d==0&& mapa[linha_atual-1][coluna_atual]!=1  ){//cima
           // cout<<"cima"<<endl;
        return ACIMA;
    }
    if(d==1 && mapa[linha_atual+1][coluna_atual]!=1){//baixo
       // cout<<"baixo"<<endl;
        return ABAIXO;
    }
    if(d==2&& mapa[linha_atual][coluna_atual+1]!=1){//direita
        //cout<<"direita"<<endl;
        return DIREITA;
    }
    if(d==3&& mapa[linha_atual][coluna_atual-1]!=1){//esquerda
        //cout<<"esquerda"<<endl;
        return ESQUERDA;
    }
     return automov();

    }


void gera_mapa()
{
    int m, n, x, y, teste, Parede = 0, MaxParede = 40;
    system("cls");
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 20; y++)
        {
            mapa[x][y] = 0;
            mapa[x][y] = mapa2[x][y];
        }
    }

    for (m = 0; m < 10; m++)
    {
        for (n = 0; n < 20; n++)
        {
            teste = rand() % 4;
            if (((mapa[m][n] == 0) && (teste == 1) && (Parede < MaxParede)))
            {
                mapa[m][n] = teste;
                Parede = Parede + 1;
            }
            else if ((teste == 0) && (mapa[m][n] == 0))
            {
                mapa[m][n] = 3;
            }
        }
    }
    mapa[9][18] = 4;
}

int desenhar_mapa()
{
    int linha, coluna;
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 20; coluna++)
        {
            if ((linha == linha_atual) && (coluna == coluna_atual))
            {
                printf("&");
                continue;
            }
            if (mapa[linha][coluna] == CHAO)
                printf(".");
            if (mapa[linha][coluna] == PAREDE)
                printf("@");
            if (mapa[linha][coluna] == GRAMA)
                printf(".");
            if (mapa[linha][coluna] == SAIDA)
                printf("#");
        }
        printf("\n");
    }
    return OK;
}

#define wait 50
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

#define FALSE   0
#define TRUE    1
char mover(int level, int DIRECAO){
    char PROC = FALSE;
    switch (DIRECAO){
        case ACIMA:
            linha_atual -= 1;
            passos += 1;
            if (mapa[linha_atual][coluna_atual] == PAREDE)
            {
                linha_atual += 1;
            }else{
                PROC = TRUE;
            }
            system("cls");
            desenhar_mapa();
        break;
        case ABAIXO:
            linha_atual += 1;
            passos += 1;
            if ((mapa[linha_atual][coluna_atual] == PAREDE))
            {
                linha_atual -= 1;
            }else{
                PROC = TRUE;
            }
            system("cls");
            desenhar_mapa();
        break;
        case DIREITA:
            coluna_atual += 1;
            passos += 1;
            if ((mapa[linha_atual][coluna_atual] == PAREDE))
            {
                coluna_atual -= 1;
            }else{
                PROC = TRUE;
            }
            system("cls");
            desenhar_mapa();
        break;
        case ESQUERDA:
            coluna_atual -= 1;
            passos += 1;
            if ((mapa[linha_atual][coluna_atual] == PAREDE))
            {
                coluna_atual += 1;
            }else{
                PROC = TRUE;
            }
            system("cls");
            desenhar_mapa();
        break;
        case Q:
            printf("\n\nLevel %i Incompleto\nTotal de Passos Level %i: %i\nPrecione Qualquer Para Sair . .\n", level, level, passos);
            getChar();
            exit(2);
        break;
        default:
        system("cls");
        desenhar_mapa();
    }
    if (PROC) delay(wait);
    return PROC;
}



#define VISITADO        -1
int procura(int M[10][20]){
    char proc=FALSE;
    if (mapa[linha_atual][coluna_atual] == SAIDA) return TRUE;
    M[linha_atual][coluna_atual] = VISITADO;

}


int main()
{
    srand((unsigned)time(NULL));
    system("cls");
    int level = 1;

    int M[10][20]; // MATRIZ para tentativas ja percorridas

    do
    {
        gera_mapa();
        desenhar_mapa();

        // 0 em toda matriz de tentativas
        for (int i = 0; i < 10*20; i++)
            *((int*)M + i) = 0;

        if (procura(M)) {
            printf("\n\nAchei!!!");
        }else {
            printf("\n\nNao consegui!!!");
        }
        printf("\n\nTentar Manual!!!");
        getChar();
        system("cls");

        desenhar_mapa();
        coluna_atual = 1;
        linha_atual = 1;

        do
        {
            //key = getChar();
           key = automov();

            mover(level, key);
        } while (mapa[linha_atual][coluna_atual] != SAIDA);

        coluna_atual = 1;
        linha_atual = 1;
        int level2 = level + 1;

        printf("\n\nLevel %i Concluido\nTotal de Passos Level %i: %i\nPrecione Qualquer Tecla Para ir Ao Level %i\n", level, level, passos, level2);
        getChar();
        passos = 0;
        system("cls");
        level += 1;
    } while (key != Q);
    exit(2);
}
