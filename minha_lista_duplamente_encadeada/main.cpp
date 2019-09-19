#include <iostream>
#include <stdlib.h>

using namespace std;
struct RES{
int resistencia;
RES *proximo;
RES *anterior;
};

struct  LISTA{

RES *inicio;

};
RES *resconstrutor(int n){
RES *temp = (RES*)malloc(sizeof(RES));
temp->anterior=NULL;
temp->proximo=NULL;
temp->resistencia=n;
return temp;
}
LISTA *construtor(){
LISTA  *temp =(LISTA*)malloc(sizeof(LISTA));
temp->inicio=NULL;
return temp;
}

void setinicio(LISTA *temp, RES *re){
if(temp->inicio==NULL)
    temp->inicio=re;
else{

    temp->inicio->anterior=re;
    re->proximo=temp->inicio;
    temp->inicio=re;
   // cout<<temp->inicio<<"  "<<temp->inicio->proximo<<endl;
    }

}
void setfim(RES **temp,RES *n){
if((*temp)==NULL){
    *temp=n;
}
else if((*temp)->proximo==NULL){
    n->anterior=*temp;
    (*temp)->proximo= n;
}
else setfim(&((*temp)->proximo),n);
}
void setposicao(LISTA *temp, int p, int c){}

void removerinicio(LISTA *temp){
if(temp->inicio){
   if(temp->inicio->proximo){
    temp->inicio=temp->inicio->proximo;
    temp->inicio->anterior=NULL;
   } else free(temp->inicio);

}
}

void removerfim(RES *temp){
if(temp){
    if(temp->proximo==NULL){
        temp->anterior->proximo=NULL;
        free(temp);
    }else removerfim(temp->proximo);
}
}
void removerpossicao(){}

void getinicio(){}
void getfim(){}
void getposicao(){}

void buscar(RES *temp, int r){}

void mostrar(RES *temp){
if(temp->proximo==NULL)
    cout<<temp<<"  "<<temp->resistencia<<endl;
else{
cout<<temp<<"  "<<temp->resistencia<<endl;
mostrar(temp->proximo);
}

}
int main()
{
    LISTA *lista=construtor();
    cout<<"setinicio"<<endl;
    setinicio(lista, resconstrutor(100));
    cout<<"setfim"<<endl;
    setfim(&(lista->inicio),resconstrutor(2));
    cout<<"mostrar"<<endl;
    mostrar(lista->inicio);
    cout<<"setinicio"<<endl;
    setinicio(lista, resconstrutor(100));
    cout<<"setfim"<<endl;
    setfim(&(lista->inicio),resconstrutor(2));
    cout<<"mostrar"<<endl;
    mostrar(lista->inicio);
    cout<<"remover inicio"<<endl;
    removerinicio(lista);
    cout<<"mostrar"<<endl;
    mostrar(lista->inicio);
    cout<<"remover fim"<<endl;
    removerfim(lista->inicio);
    cout<<"mostrar"<<endl;
    mostrar(lista->inicio);
    //cout << "Hello world!" << endl;
    return 0;
}
