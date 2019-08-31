#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX =10;
struct RES{
int resistencia;
int quantidade;
};
struct FILA{
RES resistor[MAX];
int topo;
};
FILA *contrutor(){
FILA *temp=(FILA*)malloc(sizeof(FILA));
temp->topo=-1;
return temp;
}

bool Full(FILA *temp){
if(temp->topo<MAX-1) return true;
return false;
}
bool Empty(FILA *temp){
if(temp->topo>=0) return true;
return false;
}

void push(FILA *temp, int r, int q){
if(Full(temp)){
    temp->topo++;
    temp->resistor[temp->topo].resistencia=r;
    temp->resistor[temp->topo].quantidade=q;
}else cout<<"fila cheia"<<endl;
}
void realoc(FILA *temp,int r, int q, int c){
if(c<temp->topo){
    temp->resistor[c].resistencia=r;
    temp->resistor[c].quantidade=q;
    c++;
    realoc(temp,temp->resistor[c+1].resistencia,temp->resistor[c+1].quantidade ,c );
}

}

void pop(FILA *temp){
if(Empty(temp)){

    realoc(temp,temp->resistor[1].resistencia, temp->resistor[1].quantidade, 0);
    temp->topo--;
}else cout<<"fila vazia"<<endl;

}
void mostra(FILA *temp, int c){
if(c<=temp->topo){
    cout<<"posicao: "<<c<<" resistor: "<<temp->resistor[c].resistencia<<" quantidade: "<<temp->resistor[c].quantidade <<endl;
    mostra(temp,++c);
}
}
void mostra(FILA *temp){
mostra(temp,0);
}
int main()
{
    FILA *fila=contrutor();
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);
    push(fila,1,2);

    mostra(fila);
    pop(fila);
    cout<<endl;
    mostra(fila);
     pop(fila);
     pop(fila);
     pop(fila);
     pop(fila);
     pop(fila);
     pop(fila);
     pop(fila);
     pop(fila);
     pop(fila);
     pop(fila);
    cout<<endl;
    mostra(fila);

    return 0;
}
