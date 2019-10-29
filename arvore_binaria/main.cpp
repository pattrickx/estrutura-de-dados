#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct arv
{
    int value;
    arv *direita;
    arv *esquerda;
};
arv *criarvazia()
{

    return NULL;
}
arv *criar(int a,arv *e,arv *d)
{
    arv *temp=(arv*)malloc(sizeof(arv));
    temp->value=a;
    temp->direita=d;
    temp->esquerda=e;
    return temp;

}
void add(arv **temp, int a)
{
    if(*temp==NULL)
    {
        *temp=criar(a,criarvazia(),criarvazia());
        // cout<<temp->value<<endl;
    }
    else
    {
        if (a>(*temp)->value)
            add(&(*temp)->direita,a);
        else if(a<(*temp)->value)
            add(&(*temp)->esquerda,a);
        else
            cout<<"valor ja existe"<<endl;

    }
}
void rotesq(arv **temp)
{
    arv *a, *b;
    a=(*temp)->direita;
    b=a->esquerda;
    a->esquerda=(*temp);
    (*temp)->direita=b;
    (*temp)=a;


}
void rotdir(arv **temp)
{
    arv *a, *b;
    a=(*temp)->esquerda;
    b=a->direita;
    a->direita=(*temp);
    (*temp)->esquerda=b;
    (*temp)=a;


}
int altura(arv *a)
{
    if(!a)
        return 0;
    int he=altura(a->esquerda);
    int hd=altura(a->direita);
    if (he>hd)
        return he+1;
    else
        return hd+1;

}
int balanceamento(arv *a)
{
    if (a)
        return altura(a->esquerda)-altura(a->direita);
    return 0;
}
void balancear(arv **a)
{
    if(*a)
    {
        if((*a)->esquerda)
            balancear(&(*a)->esquerda);
        if((*a)->direita)
            balancear(&(*a)->direita);
        int b = balanceamento((*a));
        if(b>1)
        {
            if(balanceamento((*a)->esquerda)<0)
                rotesq(&(*a)->esquerda);
            rotdir(a);
        }
        if(b<-1)
        {
            if(balanceamento((*a)->direita)>0)
                rotdir(&(*a)->direita);
            rotesq(a);

        }


    }
}
void mostrapreordem(arv* temp )
{
    if(temp!=NULL)
    {
        cout<<temp->value<<"    "<<balanceamento(temp)<<endl;
        mostrapreordem(temp->esquerda);
        mostrapreordem(temp->direita);
    }

}
void mostraordem(arv* temp)
{
    if(temp!=NULL)
    {
        mostrapreordem(temp->esquerda);
        cout<<temp->value<<"    ";
        mostrapreordem(temp->direita);
    }

}
void mostraposordem(arv* temp)
{
    if(temp!=NULL)
    {
        mostrapreordem(temp->esquerda);
        mostrapreordem(temp->direita);
        cout<<temp->value<<"    ";
    }

}
void ad(arv **a,int v)
{
    add(a,v);
    balancear(a);
}
void limpararvore(arv **a)
{
    if(*a)
    {
        limpararvore(&(*a)->esquerda);
        limpararvore(&(*a)->direita);
        free(*a);
    }


}
void buscar(arv *a, int v)
{
    if(a)
    {
        buscar(a->esquerda,v);
        buscar(a->direita,v);
        if(v==a->value)
            cout<<"valor encontrado"<<endl;

    }

}
int menorvalor(arv *a)
{
    if(!a->esquerda)
    {
        return a->value;
    }
    return menorvalor(a->esquerda);
}
int maiorvalor(arv *a)
{
    if(!a->direita)
    {
        return a->value;
    }
    return maiorvalor(a->direita);
}
arv *fimesq(arv *a)
{
    if(!a)
        return NULL;
    if(!a->esquerda)
    {
        return a;
    }
    return fimesq(a->esquerda);
}
arv *fimdir(arv *a)
{
    if(!a)
        return NULL;
    if(!a->direita)
    {
        return a;
    }
    return fimdir(a->direita);
}
void removermaior(arv **a)
{
    if((*a)->direita==NULL)
    {
        free(*a);
        *a=NULL;
        cout<<"aqui"<<endl;
    }
    else
        removermaior(&(*a)->direita);

}
void removermenor(arv **a)
{
    if(!(*a)->esquerda)
    {
        free(*a);
        *a=NULL;
    }
    else
        removermenor(&(*a)->esquerda);

}
void removervalor(arv **a, int v)
{
    if(*a)
    {

        if((*a)->value==v)
        {
            if(!(*a)->direita)
            {
                arv *b=(*a);
                *a=(*a)->esquerda;
                free(b);
            }
            else if(!(*a)->esquerda)
            {
                arv *b=(*a);
                *a=(*a)->direita;
                free(b);
            }
            else
            {

                if(fimdir((*a)->esquerda)==(*a)->esquerda)
                {
                    (*a)->esquerda->direita=(*a)->direita;
                    arv *b=(*a)->esquerda;
                    free(*a);
                    *a=b;
                }
                else
                {
                    arv *b= fimdir((*a)->esquerda);
                    b->esquerda= (*a)->esquerda;
                    b->direita= (*a)->direita;
                    free(*a);
                    *a=b;

                }
            }
        }
        else if(v>(*a)->value)
            removervalor(&(*a)->direita,v);
        else if(v<(*a)->value)
            removervalor(&(*a)->esquerda,v);
        else
            cout<<"nao encontrado"<<endl;
    }

}
arv *buscarno(arv *a, int v)
{
    return buscarno(a->esquerda,v);
    return buscarno(a->direita,v);
    if(v==a->value)
        return a;

}
#define pow2(n) (1 << (n))
void printGraph(arv **raiz)
{
    char fmt[9];
    int dist = 0;
    arv *root = *raiz;
    arv **row1, **row2, **rowTemp;
    int rows, row, col;

    if (root==NULL)
    {
        return;
    }
    rows = altura(*raiz);
    row1 =(arv**) malloc(sizeof(arv*) * pow2(rows));
    row2 = (arv**)malloc(sizeof(arv*) * pow2(rows));
    row1[0] = root;
    for(row=0; row<rows; row++)
    {
        int col2 = 0, cols = pow2(row);
        sprintf(fmt,"%%%dd", pow2(rows-(row+1)));
        dist = pow2(rows-(row+1));
        for(col=0; col<cols; col++)
        {
            arv *node = row1[col];
            if (node!=NULL)
            {
                printf(fmt, node->value);
                row2[col2++] = node->esquerda;
                row2[col2++] = node->direita;
            }
            else
            {
                for (int i=0; i<dist; i++)
                {
                    printf(" ");
                }
                row2[col2++] = NULL;
                row2[col2++] = NULL;
            }
            if (col==0)
            {
                dist = pow2(rows-(row+0));
                sprintf(fmt,"%%%dd", pow2(rows-(row+0)));
            }
        }
        printf("\n");
        rowTemp = row1;
        row1=row2;
        row2=rowTemp;
    }
    free(row1);
    free(row2);
}


int main()
{
    arv* a=criarvazia();
    ad(&a,5);
    ad(&a,6);
    ad(&a,4);
    ad(&a,7);
    ad(&a,3);
    ad(&a,8);
    cout<<maiorvalor(a)<<endl;
    cout<<menorvalor(a)<<endl;
    //limpararvore(&a);
    mostrapreordem(a);

   // removermaior(&a);
    cout<<"hh"<<endl;
//
   // mostrapreordem(a);
    cout<<"hh"<<endl;
   // removermenor(&a);
    mostrapreordem(a);
    printGraph(&a);
    removervalor(&a,7);
    balancear(&a);
    printGraph(&a);

//    mostraordem(a);
//    cout<<endl;
//    mostraposordem(a);
//    cout<<endl;

    return 0;
}
