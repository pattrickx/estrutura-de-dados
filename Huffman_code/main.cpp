#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
struct lno{

char caracter;
int frequencia;
lno *anterior;
lno *proximo;
lno *direita;
lno *esquerda;

};
struct lista{
lno *inicio;
};
lno* criar_no_vazio(){
return NULL;
}
lista *criar_vazia(){
    lista *a=(lista*)malloc(sizeof(lista));
    a->inicio=criar_no_vazio();
return a;
}
bool buscar_no(lno* a, char c){
    if(a){
        if(a->caracter==c)
            return true;
        buscar_no(a->proximo,c);
    }
    return false;
}
bool buscar(lista *a, char c){
    if(a->inicio)
return buscar_no(a->inicio,c);
    return false;
}
lno *criar_no(char c,int f,lno* an,lno* p,lno* e,lno* d){
    lno *a =(lno*)malloc(sizeof(lno));
    a->anterior=an;
    a->proximo=p;
    a->caracter=c;
    a->frequencia=f;
    a->esquerda=e;
    a->direita=d;

    return a;
}
void add(lno *a,lno *n){
    if(!a)
        a=n;
    else if(a->frequencia<n->frequencia){
        n->proximo=a;
        a->anterior=n;
        a=n;

    }
    add(a->proximo,n);


}
void add_em_ordem(lista *a, lno *n){
    if(!a->inicio)
        a->inicio=n;
    else if (a->inicio->frequencia>n->frequencia){
        n->proximo=a->inicio;
        a->inicio->anterior=n;
        a->inicio=n;
    }
    else
        add(a->inicio,n);

}
int quantidade(string s, char c){
    if (s[0]){
    char value[s.length()+1];
    strcpy(value, s.c_str());

    int p=0;

        for(int i = 0; i< sizeof(value);i++)
            if(value[i]==c)
                p++;
        return p;
    }
    return 0;
}
string receber_arquivo(string str){
    ifstream caminho_arquivo(str.c_str());
    string line,s;

      if (caminho_arquivo.is_open()){
        while (! caminho_arquivo.eof() ){
          getline (caminho_arquivo,line);

          s+=line+'\n';
        }
        caminho_arquivo.close();
      }
      else cout << "Unable to open file";


    return s;
}
void mostrar(lno *a){
if(a){
    cout<<a->caracter<<" quantidade: "<<a->frequencia<<endl;
    mostrar(a->proximo);
    }
}
void mostrarlista(lista *a){
mostrar(a->inicio);
}
void criar_arvore(lista *a){
 //   arvore(a->inicio);
}
int main () {
//string s =receber_arquivo("C:\\Users\\pattr\\OneDrive - Fundação Edson Queiroz - Universidade de Fortaleza\\Área de Trabalho\\projetos av3 estruturas.txt");
string s =receber_arquivo("teste.txt");
lista *l=criar_vazia();

char value[s.length()];
    strcpy(value, s.c_str());
    for(int i =0; i<sizeof(value);i++)
        cout<<value[i]<<endl;
for(int i =0; i<sizeof(value)-1;i++){
        if(buscar(l,value[i])==false){
            add_em_ordem(l,criar_no(value[i],quantidade(s,value[i]),criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio()));
        }
}
mostrarlista(l);
//criar_arvore(l);
  return 0;
}
