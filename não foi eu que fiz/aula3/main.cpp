#include <iostream>

using namespace std;
int n=0;
int v[5]={1,2,3,4,5};

int raiz(int n, int x){
if (x*x==n)return x;
return raiz(n,x+1);
}

float div(int x, int y){
if(x<y) return (div(x*10,y))/10;
if(x==y)return 1;
return 1+ div(x-y,y);
}

mdc(int x, int y){
//cout << x <<":"<< y<< endl;
if(x>y){
    if(x%y==0) return y;
    return mdc(x%y,y);
}
if(y>x){
    if(y%x==0) return x;
    return mdc(y%x,x);
}
return x;
}

void percorre(int v[], int t, int n){

if (v[t]==n) cout<<"tem o numero na posicao "<<t<<endl;
else if (v[t]!=n && t>=0) percorre(v,--t,n);
else cout<<"nao tem o numero"<<endl;
}
int dn(int n){
if (n>0) return 2*dn(--n);
else
return 1;
}
int xn(int x, int n){
if(n>0)return x*xn(x,--n);
return 1;
}
void fib(int n){

if(n>0)
    cout<<

}



int main()
{
    /*cout << "digite n" << endl;
    cin>>n;*/
    //cout << xn(3,2) << endl;
    // percorre(v,5,3);
    fib();
    return 0;
}
