#include <iostream>
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
    TIPO_LISTA tmp=(TIPO_LISTA)malloc(sizeof(TIPO_LISTA));
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
    TIPO_RES tmp = (TIPO_RES)malloc(sizeof(TIPO_RES));
    cout << "Endereco: " << tmp << endl;
    tmp->codigo = codigo;
    tmp->qtde = 0;
    tmp->resistencia = resistencia;
    tmp->proximo = NULL;
    return tmp;
}
void mostrarlista(TIPO_RES *temp ){
if(tmp->proximo==NULL)
{
    cout<<"codigo: "<<tmp->codigo<<endl;

}else{
cout<<"codigo: "<<tmp->codigo<<endl;
mostrarlista(*tmp->proximo);
}
}
int main()
{
    TIPO_LISTA *minhaLista = novaLista();
    adiconaNaLista(minhaLista,novoRes(1000, ++minhaLista->codigo));
    adiconaNaLista(minhaLista,novoRes(2000, ++minhaLista->codigo));
    adiconaNaLista(minhaLista,novoRes(3600, ++minhaLista->codigo));
mostrarlista(minhaLista->inicio )
    return 0;
}

