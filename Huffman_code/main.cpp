#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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
void mostrar(lno *a){
if(a){
    cout<<"caractere: "<<a->caracter<<" quantidade: "<<a->frequencia<<endl;
    mostrar(a->proximo);

    }
}
void mostrarlista(lista *a){
    if(a->inicio)
    mostrar(a->inicio);
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
    if(a->inicio->proximo){

        lno *temp=criar_no('+',a->inicio->frequencia+a->inicio->proximo->frequencia,criar_no_vazio(),criar_no_vazio(),a->inicio,a->inicio->proximo);
        remover_primeiro(a);
        remover_primeiro(a);
        add_em_ordem(a,temp);
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
void novos_valores(lno *r,lista *l,string numero){
       if(r){
       if(!r->direita&&!r->esquerda){
            int  novoValor = 0;
            for (int i = numero.length()-1; i >= 0; i--)
                if (numero[i] == '1')
                    novoValor += pow(2,numero.length()-1-i);
            lno *t=criar_no(r->caracter,novoValor,criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio());
            add_em_ordem(l,t);
       }
       numero+='0';
       novos_valores(r->esquerda,l,numero);
       numero+='1';
       novos_valores(r->direita,l,numero);
       }


}
int busca_int(char c,lno *n){
if(n){
    if(n->caracter==c)
        return n->frequencia;
    busca_int(c,n->proximo);
}

}
busca_char(int i, lno *n){
if(n){
    if(n->frequencia==i)
        return n->caracter ;
    busca_char(i,n->proximo);
}
}
string novo_dado(string s,lista *novos){
    string n="";
    char value[s.length()];
    strcpy(value, s.c_str());
    for(int i =0; i<sizeof(value)-1;i++){

        int num=busca_int(value[i],novos->inicio);
        string bin="";
        for (int i = 7; i >= 0; i--) {
            if (num % 2 == 0) {
                bin+= '0';
                num = num / 2;
            }
            else {
                bin+= '1';
                num = num / 2;
            }
        }
        n+=bin;

}
return n;
}
string codificador(string novodado){
string codificado="";
string numero="";
int j=0;
int novoValor=0;

for(int i=0;i<novodado.length();i++){

    if(j<8){
        numero+=novodado[i];
        j++;
    }
    if(j==8){
    //cout<<numero<<"  ";
    for (int k = numero.length()-1 ; k >= 0; k--) {
		//printf("%c|", numero[i]);
		if (numero[k] == '1') {
			novoValor += pow(2,numero.length()-1-k);
		}
	}
	//cout<<(char)(novoValor+'0')<<"  "<<novoValor<<"  ";

    codificado+=novoValor;
    novoValor=0;
    numero="";
    j=0;
    }
}

return codificado;
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

cout<<"######################################### Lista iniciar de caracteres e quantidades"<<endl;
mostrarlista(l);
criar_arvore(l,0);
cout<<"######################################### Arvore de valores"<<endl;
mostrar_arvore(l->inicio);
lista *novos=criar_vazia();
novos_valores(l->inicio,novos,"");
cout<<"######################################### Lista de novos valores"<<endl;
mostrarlista(novos);
string novodado= novo_dado(s,novos);
cout<<novodado<<endl<<endl<<endl;

string codificado=codificador(novodado);


cout<<codificado<<endl;

ofstream out("codificado.txt");
    out << codificado;
    out.close();


  return 0;
}
