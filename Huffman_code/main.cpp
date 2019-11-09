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
    }else return false;
}
bool buscar(lista *a, char c){

return buscar_no(a->inicio,c);

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
    if(!a->proximo){
        a->proximo=n;
        n->anterior=a;
        }
    else if(a->frequencia>n->frequencia){
        n->proximo=a->proximo;
        a->proximo=n;
        n->anterior=a;
    }else add(a->proximo,n);


}
void add_em_ordem(lista *a, lno *n){

    if(!a->inicio)
        a->inicio=n;
    else if (a->inicio->frequencia>n->frequencia){
        n->proximo=a->inicio;
        a->inicio->anterior=n;
        a->inicio=n;
    }
    else add(a->inicio,n);

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
void mostrar(lno *a,int i){
if(a){
    cout<<"caractere: "<<a->caracter<<" quantidade: "<<a->frequencia<<" numero: "<<i++<<endl;
    mostrar(a->proximo,i);

    }
}
void mostrarlista(lista *a){
    if(a->inicio)
    mostrar(a->inicio,0);
}
void remover_primeiro(lista *a){
    if(!a->inicio->proximo)
    a->inicio=NULL;
    else{
        a->inicio=a->inicio->proximo;
        a->inicio->anterior=NULL;
   }

}
void criar_arvore(lista *a,int i){
    //cout<<i<<endl;
    if(a->inicio->proximo){

        lno *temp=criar_no('+',a->inicio->frequencia+a->inicio->proximo->frequencia,criar_no_vazio(),criar_no_vazio(),a->inicio,a->inicio->proximo);
        remover_primeiro(a);
        //cout<<"teste"<<endl;
        remover_primeiro(a);
        add_em_ordem(a,temp);
       // mostrarlista(a);
        criar_arvore(a,++i);
    }
}
void mostrar_arvore(lno *a){
    if(a){
        cout<<"caractere: "<<a->caracter<<" quantidade: "<<a->frequencia<<endl;
        mostrar_arvore(a->esquerda);
        mostrar_arvore(a->direita);
    }

}
int main () {
string s =receber_arquivo("C:\\Users\\pattr\\OneDrive - Fundação Edson Queiroz - Universidade de Fortaleza\\Área de Trabalho\\projetos av3 estruturas.txt");
//string s =receber_arquivo("teste.txt");
lista *l=criar_vazia();
cout<<s;
char value[s.length()];
    strcpy(value, s.c_str());
for(int i =0; i<sizeof(value)-1;i++){
        if(!buscar(l,value[i])){
            lno *t=criar_no(value[i],quantidade(s,value[i]),criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio());
            add_em_ordem(l,t);
            }

}

//mostrarlista(l);
criar_arvore(l,0);
mostrar_arvore(l->inicio);
  return 0;
}
