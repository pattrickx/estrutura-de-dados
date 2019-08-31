#include <iostream>
#include <stdlib.h>
using namespace std;


struct  TIPO_RES{
   int codigo;
   int precisao;
   int resistencia;
   int quantidade;
   int posicao;
};
#define MAX_LISTA 100
struct LISTA{
 TIPO_RES resistores[MAX_LISTA];
 int contador;
};

LISTA *novaLista(){
LISTA *temp= (LISTA*)malloc(sizeof(LISTA));
temp->contador=0;
return temp;

}
void novo_resistor(LISTA *temp,int cod, int pre,int res,int qua,int pos){
if( temp->contador>=MAX_LISTA){
cout<<"lista cheia"<<endl;
}else{
temp->resistores[temp->contador].codigo=cod;
temp->resistores[temp->contador].posicao=pos;
temp->resistores[temp->contador].precisao=pre;
temp->resistores[temp->contador].quantidade=qua;
temp->resistores[temp->contador].resistencia=res;
temp->contador++;
}
void exibir_lista(LISTA *temp){

for(int i =0 ; i< temp){
cout<<" codigo :"<<temp->resistores[i].codigo=cod;
cout<<" posicao :"<<temp->resistores[i].posicao=pos;
cout<<" precisao :"<<temp->resistores[i].precisao=pre;
cout<<" quantidade :"<<temp->resistores[i].quantidade=qua;
cout<<" resistencia :"<<temp->resistores[i].resistencia=res<<endl;


}

}
int main()
{
    cout << "Hello world!" << endl;
    LISTA *minhalista=novaLista();
    novo_resistor(minhalista,1,2,3,4,5);

    cout<<minhalista->resistores[0].codigo<<endl;
    cout<<minhalista->resistores[0].posicao<<endl;
    cout<<minhalista->resistores[0].precisao<<endl;
    cout<<minhalista->resistores[0].quantidade<<endl;
    cout<<minhalista->resistores[0].resistencia<<endl;
    cout<<minhalista->contador<<endl;
    return 0;
}
