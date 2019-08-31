#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int MAX = 10;
struct RES{
int resistencia;
int quatidade;
};
struct PILHA{
RES resistor[MAX];
int topo;

};
PILHA *construtor(){
PILHA *temp = (PILHA*)malloc(sizeof(PILHA));
temp->topo=-1;
return temp;
}
bool Full(PILHA *temp){
if(temp->topo<MAX-1)return true;
    return false;
}
bool Empty(PILHA *temp){
if(temp->topo>=0)return true;
    return false;
}
void push(PILHA *temp,int r, int q){
if(Full(temp)){
    temp->topo++;
    temp->resistor[temp->topo].quatidade=q;
    temp->resistor[temp->topo].resistencia=r;
}else cout<<"pilha cheia"<<endl;

}
void pop(PILHA *temp){
if(Empty(temp)){
    temp->resistor[temp->topo].quatidade=0;
    temp->resistor[temp->topo].resistencia=0;
    temp->topo--;
}else cout<<"pilha vazia"<<endl;

}
void mostrar(PILHA temp){
    if(temp.topo>=0){
      cout<<"posicao: "<<temp.topo<<" quantidade"<<temp.resistor[temp.topo].quatidade<<" resistencia: "<<temp.resistor[temp.topo].resistencia<<endl;
      temp.topo--;
        mostrar(temp);
    }
}
int main()
{
    PILHA *minhapilha= construtor();
    push(minhapilha,10, 100);
    push(minhapilha,10, 100);
    mostrar(*minhapilha);
    pop(minhapilha);
    mostrar(*minhapilha);
    return 0;
}
