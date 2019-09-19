#include <iostream>
#include <stdlib.h>
using namespace std;

struct ARVORE{
char info;
ARVORE *direita;
ARVORE *esquerda;
};

ARVORE *criavazia(){
return NULL;
}
ARVORE *cria(char c, ARVORE *e, ARVORE *d){
ARVORE *temp=(ARVORE*)malloc(sizeof(ARVORE));
temp->direita= d;
temp->esquerda= e;
temp->info=c;
return temp;
}

ARVORE *libera(ARVORE *a){

}

int  vazia(ARVORE *a){

}
int pertence(ARVORE *a, char c){
a->info=c;

}

void imprime(ARVORE *a){
    cout<<a->info<<endl;
    if(a->direita) imprime(a->direita);
    else imprime(a->esquerda);
    }

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
