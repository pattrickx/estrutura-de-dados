#include <iostream>
#include <stdlib.h>
using namespace std;
struct t{int n;};
int main()
{
string *a, *b;
string c="abacate";
(*a) = (string*)malloc(sizeof(c));
(*b) = "uva";


   cout<<*a <<*b <<endl;
   cout<<a <<b <<endl;

    return 0;
}
