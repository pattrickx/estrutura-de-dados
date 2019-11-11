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
char *novo_caracter;
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
lno *criar_no(char c,char *no,int f,lno* an,lno* p,lno* e,lno* d){
    lno *a =(lno*)malloc(sizeof(lno));
    a->anterior=an;
    a->proximo=p;
    a->caracter=c;
    a->frequencia=f;
    a->esquerda=e;
    a->direita=d;
    a->novo_caracter= (char*)malloc(sizeof(char)*(strlen(no)+1));
    strcpy(a->novo_caracter, no);

    return a;
}
void add(lno *a,lno *n){

    if(a->frequencia>n->frequencia){
        n->proximo=a;
        n->anterior=a->anterior;
        a->anterior->proximo=n;
        a->anterior=n;


    }else if(!a->proximo){
        a->proximo=n;
        n->anterior=a;
        }
    else add(a->proximo,n);


}
void add_em_ordem(lista *a, lno *n){

    if(!a->inicio)
        a->inicio=n;
    else if (a->inicio->frequencia>n->frequencia){

        n->proximo=a->inicio;
        a->inicio->anterior=n;
        a->inicio=n;
    }
    else if(!a->inicio->proximo){
        a->inicio->proximo=n;
            n->anterior=a->inicio;
    }
    else add(a->inicio->proximo,n);

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
lista *criar_lista_frequencia(string s){
    lista* l=criar_vazia();
char value[s.length()];
    strcpy(value, s.c_str());
for(int i =0; i<sizeof(value)-1;i++){
        if(!buscar(l,value[i])){
            lno *t=criar_no(value[i],"00000000",quantidade(s,value[i]),criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio());
            cout<<t->caracter <<"  "<<t->frequencia<<endl;
            add_em_ordem(l,t);
            }

}
return l;

}


void mostrar(lno *a){
if(a){
    cout<<"caractere: "<<a->caracter<<" novo_caracter: "<<a->novo_caracter<<" quantidade: "<<a->frequencia<<endl;
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

        lno *temp=criar_no('+',"+",a->inicio->frequencia+a->inicio->proximo->frequencia,criar_no_vazio(),criar_no_vazio(),a->inicio,a->inicio->proximo);
        remover_primeiro(a);
        remover_primeiro(a);
        add_em_ordem(a,temp);
        criar_arvore(a,++i);
    }
}
void mostrar_arvore(lno *a,string s){
    if(a){
        if(!a->esquerda&& !a->direita){
        cout<<s<<"  caractere: "<<a->caracter<<" quantidade: "<<a->frequencia<<endl;
        }
        if(a->esquerda){
        s+='0';
        mostrar_arvore(a->esquerda,s);
        }
        if(a->esquerda){
            s+='1';
            mostrar_arvore(a->direita,s);
        }
    }

}
string remove_ultimo(string numero){
    if(numero.length()>0){
            string aux= numero;
            numero="";
            for(int i=0;i<aux.length()-2;i++)
            numero+=aux[i];
            return numero;
        }

}
void novos_valores(lno *r,lista *l,string numero){
    if(r){

            if(!r->direita&&!r->esquerda){
                   // numero=remove_primeiro(numero);
            char value[numero.length()+1];
            strcpy(value, numero.c_str());
            lno *t=criar_no(r->caracter,value,0,criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio());
            add_em_ordem(l,t);


            }else{

            string numero2=numero+'0';
            novos_valores(r->esquerda,l,numero2);
            string numero3=numero+'1';
            novos_valores(r->direita,l,numero3);
            }

    }


}
char* buscar_novo(char c,lno *n){
if(n){
    if(n->caracter==c)
        return n->novo_caracter ;
    buscar_novo(c,n->proximo);
}

}
string binario(string s,lista *novos){
    string n="";
    char value[s.length()];
    strcpy(value, s.c_str());
    for(int i =0; i<sizeof(value);i++)
         n+=buscar_novo(value[i],novos->inicio);
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
    //cout<<numero<<"->";
    for (int k = numero.length()-1 ; k >=0; k--) {
		//printf("%c|", numero[i]);
		if (numero[k] == '1') {
			novoValor += pow(2,numero.length()-1-k);
		}
	}
	//cout<<(char)(novoValor)<<"->"<<novoValor<<"  ";

    codificado+=novoValor;
    novoValor=0;
    numero="";
    j=0;
    }
}

return codificado;
}
string str_bin(string codificado){
 string decodificar="";
 for(int i=0;i<codificado.length();i++){
    int num = codificado[i];
    string bin="00000000";
    //cout<<codificado[i]<<"->"<<num<<"->";
        for (int j = 7; j>=0; j--) {
            if (num % 2 == 0) {
                bin[j]= '0';
                num = num / 2;
            }
            else {
                bin[j]= '1';
                num = num / 2;
            }
        }
    //cout<<bin<<" ";
    decodificar+=bin;

 }
 return decodificar;
}

string decodificador(string decodificar,lno * raiz ,lno * a,int i,string decodificado){
    if(a){


        if(decodificar[i]=='0'&& a->esquerda)
            decodificador(decodificar,raiz,a->esquerda,++i,decodificado);

        if(decodificar[i]=='1'&& a->direita)
            decodificador(decodificar,raiz,a->direita,++i,decodificado);
            if(!a->direita && !a->esquerda){
            decodificado += a->caracter;
            decodificador(decodificar,raiz,raiz,++i,decodificado);
            }
            if(i==decodificar.length()-1)
            return decodificado;

    }
}
int main () {
//string s =receber_arquivo("C:\\Users\\pattr\\OneDrive - Fundação Edson Queiroz - Universidade de Fortaleza\\Área de Trabalho\\projetos av3 estruturas.txt");
string s =receber_arquivo("teste.txt");
lista *l=criar_vazia();
cout<<s;
l=criar_lista_frequencia(s);

cout<<"######################################### Lista iniciar de caracteres e quantidades"<<endl;
mostrarlista(l);
criar_arvore(l,0);
cout<<"######################################### Arvore de valores"<<endl;
mostrar_arvore(l->inicio,"");
lista *novos=criar_vazia();
novos_valores(l->inicio,novos,"");
cout<<"######################################### Lista de novos valores"<<endl;
mostrarlista(novos);
cout<<"######################################### Novo dado"<<endl;
string novodado= binario(s,novos);
cout<<novodado<<endl;
string codificado=codificador(novodado);
cout<<"#########################################Codificado"<<endl;

cout<<codificado<<endl;

ofstream out("codificado.txt");
    out << codificado;
    out.close();


///////////////////////////////////////////////////////////

cout<<"#########################################Binario re feito"<<endl;
string decodificar=str_bin(codificado);

cout<<decodificar<<endl;

string decodificado=decodificador(decodificar,l->inicio,l->inicio,0,"");
cout<<decodificado<<endl;

ofstream out1("decodificado.txt");
    out1 << decodificado;
    out1.close();

  return 0;
}
