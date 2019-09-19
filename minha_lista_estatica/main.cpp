#include <iostream>
#include <stdlib.h>

using namespace std;
const int MAX = 10;
struct RES{
int quantidade;
int resistencia;

};
struct LISTA{
    int topo;
    RES resistor[MAX];
};
LISTA *construtor(){
LISTA *temp =(LISTA*)malloc(sizeof(LISTA));
temp ->topo=-1;
return temp;
}
bool Full(LISTA *temp){
    if(temp->topo<MAX) return true;
    return false;
}
bool Empty(LISTA *temp){
if(temp->topo>=0) return true;
    return false;
}
void setInicio(LISTA temp, int r, int q){}
void setFim(LISTA temp, int r, int q){}
void setPossicao(LISTA temp, int r, int q){}
RES getFim(LISTA temp){}
RES getInicio(LISTA temp){}
RES getPossicao(LISTA temp, int p){}
void buscar(LISTA temp,int r){}
void mostrar(LISTA temp){}


int main()
{
    LISTA *lista= construtor();

    return 0;
}
