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
      string t="";
      for (int i = 0;i<s.length()-1;i++)
        t+=s[i];
      return t;
}
lista *criar_lista_frequencia(string s){
    lista* l=criar_vazia();
char value[s.length()];
    strcpy(value, s.c_str());
for(int i =0; i<sizeof(value);i++){
        if(!buscar(l,value[i])){
            lno *t=criar_no(value[i],"00000000",quantidade(s,value[i]),criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio());
            //cout<<t->caracter <<"  "<<t->frequencia<<endl;
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
        //if(!a->esquerda&& !a->direita)
        cout<<s<<"  caractere: "<<a->caracter<<" quantidade: "<<a->frequencia<<endl;
        mostrar_arvore(a->esquerda,s+'0');
        mostrar_arvore(a->direita,s+'1');

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
                char value[numero.length()+1];
                strcpy(value, numero.c_str());
                lno *t=criar_no(r->caracter,value,0,criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio());
                add_em_ordem(l,t);
            }
            novos_valores(r->esquerda,l,numero+'0');
            novos_valores(r->direita,l,numero+'1');

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

if(novodado.length()%8!=0)
    for(int i= 0;i<(novodado.length()%8);i++)
        novodado+='0';
//cout<<novodado<<endl;
for(int i=0;i<novodado.length();i++){

    if(j<8){
        numero+=novodado[i];
        j++;
    }
    if(j==8){
        //cout<<numero<<endl;
        int novoValor=0;
        int l=0;
        for (int k = 7 ; k >=0; k--)
                novoValor += pow(2, l++) * (numero[k] - '0');
        //cout<< novoValor<<endl;
        codificado+=novoValor;

        numero="";
        j=0;
    }
}

return codificado;
}
string str_bin(string codificado){
 string decodificar="";
 for(int i=0;i<codificado.length();i++){
    int num = codificado[i]+256;
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
        //cout<<bin<<endl;
    decodificar+=bin;

 }
 return decodificar;
}
string int_bin_protobuf(int num){
    string bin="";
    while(num>0)
    if(num<=127){
        string n="00000000";
        for (int j = 7; j>=0; j--) {
            if (num % 2 == 0) {
                n[j]= '0';
                num = num / 2;
            }
            else {
                n[j]= '1';
                num = num / 2;
            }
        }
    bin+=n;
    }
    else{
        num-=127;
        bin+="11111111";

    }

return bin;
}
string salvar_lista(lno *a){
if(a){
    return a->caracter+codificador(int_bin_protobuf(a->frequencia))+salvar_lista(a->proximo);
}
return "";

}
int bin_protobuf_int(string n){
    int dec=0;
    for(int i=0;i<n.length();i+=8){
        int l=0;
        for(int j=i+7;j>i;j--)
                dec += pow(2, l++) * (n[j] - '0');
        if(n[i]=='0')
            break;
    }
    return dec;
}
lista* ler_dicionario(string d){
    lista * l=criar_vazia();
    int n=0;
    string y="";
    y+=d[n];
    string bin = str_bin(y);
    int k=0;
    int num=0;
    while(bin[k]=='1'){
        y="";
        y+=d[++n];
        bin+=str_bin(y);
        k+=8;
    }
    num+=bin_protobuf_int(bin);
    for(int i =n+1; i<num+n+1;i++){
        int x=i;
        y="";
        y+=d[++x];
        string bin = str_bin(y);
        int j=0;
        int numero=0;
        while(bin[j]=='1'){
            y="";
            y+=d[++x];
            bin+=str_bin(y);
            j+=8;
        }
        numero+=bin_protobuf_int(bin);
        add_em_ordem(l,criar_no(d[i],"00000000",numero,criar_no_vazio(),criar_no_vazio(),criar_no_vazio(),criar_no_vazio()));
        i=x;

    }
    return l;
}
string ler_arquivo(string d){

    int n=0;
    string y="";
    y+=d[n];
    string bin = str_bin(y);
    int k=0;
    int num=0;
    while(bin[k]=='1'){
        y="";
        y+=d[++n];
        bin+=str_bin(y);
        k+=8;
    }
    num+=bin_protobuf_int(bin);
    /*
    cout<<"numero brotobuf: "<<bin<<endl;
    cout<<"inicio do dado: "<<n+1<<endl;
    cout<<"tamanho do dado: "<<num<<endl;
    */
    n+=num+1;
    y="";
    y+=d[n];
    //cout<<y<<endl;
    bin = str_bin(y);
    k=0;
    num=0;
    while(bin[k]=='1'){
        y="";
        y+=d[++n];
        bin+=str_bin(y);
        k+=8;
    }
    num+=bin_protobuf_int(bin);
    /*
    cout<<"numero brotobuf: "<<bin<<endl;
    cout<<"inicio do dado: "<<n+1<<endl;
    cout<<"tamanho do dado: "<<num<<endl;
        */
    string decodificar="";
    string binario="";

    //cout<<"binario total: "<<str_bin(d)<<endl;
    for(int i =n+1; i<d.length();i++){
        binario+=d[i];
     }
     //cout<<"antes do binario: "<<binario<<endl;
     binario=str_bin(binario);
     cout<<"tamanho do binario bruto final: "<<binario.length()<<endl;
     //cout<<"depois do binario: "<<binario<<endl;
     for(int i=0; i<num;i++){
        decodificar+=binario[i];
     }

     return decodificar;

}
string decodificador(string decodificar,lno * raiz ,lno * a,int i,string decodificado){
/*
    if(i<decodificar.length()){
        if (!a->esquerda&&!a->direita){
            decodificado+=a->caracter;
            decodificador(decodificar, raiz,raiz,i,decodificado);
        }
        else if(decodificar[i]=='0')
            decodificador(decodificar, raiz,a->esquerda,i+1,decodificado);
        else if(decodificar[i]=='1')
            decodificador(decodificar, raiz,a->direita,i+1,decodificado);
    }
*/

    for(int j = 0; j<decodificar.length();j++){

        if(decodificar[j]=='0')
            a= a->esquerda;
        if(decodificar[j]=='1')
            a= a->direita;
        if (!a->esquerda&&!a->direita){
            decodificado+=a->caracter;
            a=raiz;
        }
    }
    return decodificado;

}
int main(){
string s =receber_arquivo("tested.txt");
lista *l=criar_vazia();
//cout<<s<<endl;
cout<<"tamanho do arquivo inicial: "<<s.length()<<endl;
l=criar_lista_frequencia(s);
string dicionario=salvar_lista(l->inicio); /// salvando lista para dicionario
//cout<<"######################################### Lista iniciar de caracteres e quantidades"<<endl;
//mostrarlista(l);
criar_arvore(l,0);
//cout<<"######################################### Arvore de valores"<<endl;
//mostrar_arvore(l->inicio,"");
lista *novos=criar_vazia();
novos_valores(l->inicio,novos,"");
//cout<<"######################################### Lista de novos valores"<<endl;
//mostrarlista(novos);
//cout<<"######################################### Novo dado"<<endl;
string novodado= binario(s,novos);
//cout<<novodado<<endl;
cout<<"tamanho do binario inicial: "<<novodado.length()<<"  "<<bin_protobuf_int(int_bin_protobuf(novodado.length())) <<endl;
//cout<<"######################################### Dicionario"<<endl;
//cout<<dicionario.length()<<endl;
string tamanho_dicionario=codificador(int_bin_protobuf(dicionario.length()));
string tamanho_arquivo_bin=codificador(int_bin_protobuf(novodado.length()));
string dicionario_completo=tamanho_dicionario+dicionario+tamanho_arquivo_bin;
//cout<<"dicionario_completo: "<<dicionario_completo<<endl;
//cout<<"tamanho do dado: "<<novodado.length()<<endl;

//cout<<"######################################### Codificado"<<endl;
string codificado=codificador(novodado);
cout<<"tamanho do codificado inicial: "<<dicionario_completo.length()+codificado.length()<<endl;
//cout<<codificado<<endl;


ofstream out("codificado.txt");
    out << dicionario_completo+codificado;
    out.close();
///////////////////////////////////////////////////////////
//cout<<"######################################### Recebendo arquivo com dados codificados"<<endl;

codificado=receber_arquivo("codificado.txt");
cout<<"tamanho do codificado final: "<<codificado.length()<<endl;
//cout<<codificado<<endl;
/// refazer lista e arvore
lista * dici= ler_dicionario(codificado);
//mostrarlista(dici);
criar_arvore(dici,0);
//mostrar_arvore(dici->inicio,"");


//cout<<"######################################### Binario re feito"<<endl;
string decodificar=ler_arquivo(codificado);
cout<<"tamanho do binario final: "<<decodificar.length()<<endl;
//cout<<decodificar<<endl;
//cout<<"######################################### Decodificado"<<endl;
string decodificado=decodificador(decodificar,dici->inicio,dici->inicio,0,"");
//cout<<decodificado;
cout<<"tamanho do arquivo final: "<<decodificado.length()<<endl;
ofstream out1("decodificado.txt");
    out1 << decodificado;
    out1.close();
cout<<"fim";
  return 0;
}
