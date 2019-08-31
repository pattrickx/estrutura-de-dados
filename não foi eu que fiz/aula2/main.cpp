#include <iostream>

using namespace std;
int x[]={1,2,3};


int mul(int a , int b ){
    int soma= 0;

for (int i =0; i < b ; i ++)
    soma= soma + a;

    return soma;

}
int mulr(int a , int b ){

    int soma=0;

    if(b>0)
       soma = a + mulr(a,b-1);

    return soma;
}
int fac(int n){
 if(n==0) return 1;
 return n* fac(n-1);

}

void ar(int a[] ,int b){

if(b >= 0){
     ar(a,b-1);
     cout<< a[b]<<" ";
}


}
int main()
{
    ar(x,2);
    return 0;
}
