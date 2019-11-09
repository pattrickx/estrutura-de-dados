#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

string receber_arquivo(string str){
    ifstream caminho_arquivo(str.c_str());
    string line, value;
      if (caminho_arquivo.is_open()){
        while (! caminho_arquivo.eof() ){
          getline (caminho_arquivo,line);

          value+=line+'\n';
        }
        caminho_arquivo.close();
      }
      else cout << "Unable to open file";

    return value;
}
int main () {
cout<<receber_arquivo("C:\\Users\\pattr\\OneDrive - Fundação Edson Queiroz - Universidade de Fortaleza\\Área de Trabalho\\projetos av3 estruturas.txt");


  return 0;
}
