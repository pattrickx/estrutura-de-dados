


#include <iostream>
#include <stdlib.h>
using namespace std;
struct RES{
int quantidade;
int resistencia;
RES *proximo;
};
struct LISTA{
int topo;
RES *inicio;
};
LISTA *construtor(){
LISTA *temp = (LISTA*)malloc(sizeof(LISTA));
temp->topo=0;
temp->inicio=NULL;
return temp;
}


void setfim(RES *temp, int r, int q){
        cout << "Valor TMP: " << temp << endl;
    //cout << "Valor *TMP: " << *temp << endl;

   if(temp==NULL){
        cout << "entrou"<< endl;
    RES *re = (RES*)malloc(sizeof(RES));
    re->quantidade=q;
    re->resistencia=r;
    re->proximo=NULL;
    temp = re;

    cout << "Valor TMP qt: " << temp->quantidade << endl;
    cout << "Valor TMP re: " << temp->resistencia << endl;
   }
   else(setfim(temp->proximo,r,q));
}
void setinicio(LISTA *temp, int r, int q){
RES *re = (RES*)malloc(sizeof(RES));
re->quantidade=q;
re->resistencia=r;
if(temp->inicio==NULL){
temp->inicio=re;
re->proximo=NULL;
}else{

re->proximo=temp->inicio;
temp->inicio=re;
}



}
void removerfim(RES *temp,RES *anterior){
if(temp->proximo){

    removerfim(temp->proximo,temp);
   }else if(anterior){
   free(temp);
   anterior->proximo=NULL;
    }else{temp=NULL;
    free(temp);
    cout<<"ultimo"<<endl;}

}
void removerelemento(RES *temp,int valor ){

if (temp->proximo->resistencia==valor){


}
}

void buscar(RES *temp, int valor){
//if()

}
void removerinicio(LISTA *temp){
RES *re=temp->inicio->proximo;
free(temp->inicio);
temp->inicio=re;

}

void mostrarlista(RES *temp){
    //cout << "Valor TMP: " << temp << endl;
   if(temp->proximo){
    cout<<temp->resistencia<<"  "<<temp->quantidade<<endl;
    mostrarlista(temp->proximo);
   }else
    cout<<temp->resistencia<<"  "<<temp->quantidade<<endl;

}


int main()
{
    LISTA *lista=construtor();
    setinicio(lista,10,20);
    setinicio(lista,10,2);
    setinicio(lista,10,2);
    setinicio(lista,10,2);
    mostrarlista(lista->inicio);
    //setfim(lista->inicio,110,2);
    //setfim(lista->inicio,110,2);
    //mostrarlista(lista->inicio);
    removerfim(lista->inicio,NULL);
    removerfim(lista->inicio,NULL);
    removerfim(lista->inicio,NULL);
    removerfim(lista->inicio,NULL);
    mostrarlista(lista->inicio);
    return 0;
}

/*#include <iostream>
#include <stdlib.h>

using namespace std;
struct TIPO_RES {
    int codigo;
    int resistencia;
    int qtde;
    int posicao; // 20 x 20
    TIPO_RES *proximo;
};

#define MAX_COL 10
#define MAX_LIN 10
struct TIPO_LISTA {
    int contador; // 4bytes
    int codigo; // 4bytes
    TIPO_RES *inicio;
};

TIPO_LISTA *novaLista(){
    TIPO_LISTA *tmp=(TIPO_LISTA*)malloc(sizeof(TIPO_LISTA));
    cout << "Endereco LISTA: " << tmp << endl;
    tmp->contador = 0;
    tmp->codigo = 0;
    tmp->inicio = NULL;
    return tmp;
}

void adiciona(TIPO_RES **tmp, TIPO_RES *novo){
    cout << "Valor TMP: " << tmp << endl;
    cout << "Valor *TMP: " << *tmp << endl;
    if (*tmp==NULL){
        *tmp = novo;
    }else (adiciona(&((*tmp)->proximo), novo));
}

void adiconaNaLista(TIPO_LISTA *lista, TIPO_RES *novo){
    lista->contador++;
    adiciona(&(lista->inicio), novo);
}


TIPO_RES *novoRes(int resistencia, int codigo){
    TIPO_RES *tmp = (TIPO_RES*)malloc(sizeof(TIPO_RES));
    cout << "Endereco: " << tmp << endl;
    tmp->codigo = codigo;
    tmp->qtde = 0;
    tmp->resistencia = resistencia;
    tmp->proximo = NULL;
    return tmp;
}
void mostrarlista(TIPO_RES *tmp ){
if(tmp->proximo==NULL)
{
    cout<<"codigo: "<<tmp->codigo<<endl;

}else{
cout<<"codigo: "<<tmp->codigo<<endl;
mostrarlista(tmp->proximo);
}
}
int main()
{
    TIPO_LISTA *minhaLista = novaLista();
    adiconaNaLista(minhaLista,novoRes(1000, ++minhaLista->codigo));
    adiconaNaLista(minhaLista,novoRes(2000, ++minhaLista->codigo));
    adiconaNaLista(minhaLista,novoRes(3600, ++minhaLista->codigo));
mostrarlista(minhaLista->inicio );
    return 0;
}
*/
