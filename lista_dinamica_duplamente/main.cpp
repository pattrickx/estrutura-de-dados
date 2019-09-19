#include <iostream>
#include <stdlib.h>
using namespace std;
struct RES{
int valor;
RES *proximo;
RES *anterior;
};
struct LISTA{
RES *inicio;
};
RES *rconstrutor(int r){
RES *temp= (RES*)malloc(sizeof(RES));
temp->anterior=NULL;
temp->proximo=NULL;
temp->valor=r;
return temp;
}
LISTA *construtor(){
LISTA *temp = (LISTA*)malloc(sizeof(LISTA));
temp->inicio=NULL;
return temp;
}
void addinicio(LISTA *temp, RES *r){
    if(temp->inicio!=NULL){
        temp->inicio->anterior=r;
        r->proximo=temp->inicio;
        temp->inicio=r;
    }else{
    temp->inicio= r;
    }
}
void addfim(RES *temp, RES *r){
if(temp->proximo==NULL){
    temp->proximo=r;
    r->anterior=temp;
}else addfim(temp->proximo,r);

}
void mostrar(RES *temp){
if(temp->proximo==NULL){
    cout<<temp->valor<<endl;
}else{
cout<<temp->valor<<endl;
mostrar(temp->proximo);
}

}
void buscar(RES *temp, int x){
if(temp->valor==x){
    cout<<"tem"<<endl;
}else if(temp->proximo!=NULL){
buscar(temp->proximo,x);
}
else{
    cout<<"nao tem"<<endl;

}

}
void removerfim(RES *temp){
if(temp->proximo==NULL){
    temp->anterior->proximo=NULL;
    free(temp);
}else removerfim(temp->proximo);

}
void removerinicio(LISTA *temp){
if(temp->inicio!=NULL){
        if(temp->inicio->proximo!=NULL){
          temp->inicio=temp->inicio->proximo;
          free(temp->inicio->anterior);
        }
        else{
            free(temp->inicio);

        }
}

}
addpos(RES *temp, RES *r, int q){
if(temp->proximo==NULL && q>1 ){}

}
addp(RES *temp, RES *r, int q){}

int main()
{
        LISTA *lista= construtor();

        addinicio(lista,rconstrutor(12));
        addinicio(lista,rconstrutor(11));
        addinicio(lista,rconstrutor(10));
        addfim(lista->inicio,rconstrutor(13));
        buscar(lista->inicio,12);
        mostrar(lista->inicio);
        removerinicio(lista);
        removerfim(lista->inicio);
        cout<<endl;
        mostrar(lista->inicio);
        buscar(lista->inicio,12);

    return 0;
}
