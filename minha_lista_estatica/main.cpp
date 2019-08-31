#include <iostream>
#include <stdlib.h>

using namespace std;
const int MAX = 1000;
struct real{
int esquerda=0;
int direita=0;

};

struct PILHA{
real numero[MAX];
int tamanho;

};

PILHA *contrutor(){
PILHA *temp = (PILHA*)malloc(sizeof(PILHA));
temp->tamanho=0;
return temp;
}
bool cheia(PILHA *temp);

void add(PILHA *temp, int e, int d){



}
void remover(){}
void mostras(){}
void buscar(){}

int main()
{
    PILHA *pilha= contrutor();

    return 0;
}
