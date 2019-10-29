#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <dirent.h> // para varrer os arquivos
using namespace std;

struct Arv
{
    int numero;
    string diretorio;
    string nome;
    struct Arv* esq;
    struct Arv* dir;
};

Arv* arv_criavazia (void)
{
    return NULL;
}

Arv* arv_cria (string nome, Arv* sae, Arv* sad)
{
    Arv* p=(Arv*)malloc(sizeof(Arv));
    //p->numero= numero;
    //p->diretorio=diretorio;
    p->nome=nome;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arv_vazia (Arv* a)
{
    return a==NULL;
}

Arv* arv_libera (Arv* a)
{
    if (!arv_vazia(a))
    {
        arv_libera (a->esq); /* libera sae */
        arv_libera (a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

bool arv_pertence (Arv* a, int c)
{
    if (arv_vazia(a))
        return false; /* árvore vazia: não encontrou */
    bool p = a->numero==c;
    if( p )
        return p;
    p = arv_pertence (a->esq,c);
    if( p )
        return p;
    return arv_pertence (a->dir,c);
}

int altura(Arv* a)
{
    if (a==NULL)
        return 0;
    int He = altura(a->esq);
    int Hd = altura(a->dir);
    return (He>Hd?He:Hd)+1;
}

int balanceamento(Arv* a)
{
    if (a==NULL)
        return 0;
    int He = altura(a->esq);
    int Hd = altura(a->dir);
    return He-Hd;
}

void arv_imprime (Arv* a)
{
    if (!arv_vazia(a))
    {
        arv_imprime(a->esq); /* mostra sae */
        cout<<a->nome<<"  "; /* mostra raiz */
        printf("Altura %d ", altura(a)); /* mostra raiz */
        printf("balancamento %d\n", balanceamento(a)); /* mostra raiz */
        arv_imprime(a->dir); /* mostra sad */
    }
}
/*
void adicona_arvore(Arv** a, int valor)
{
    if (arv_vazia(*a))
        *a = arv_cria(valor,arv_criavazia(),arv_criavazia());
    else if ((*a)->numero > valor)
        adicona_arvore(&((*a)->esq),valor);
    else if((*a)->numero < valor)
        adicona_arvore(&((*a)->dir),valor);
    else
    {
        cout << "Numero " << valor <<" ja existante";
    }
}*/
void adicona_arvores(Arv** a, string valor)
{
    if (arv_vazia(*a))
        *a = arv_cria(valor,arv_criavazia(),arv_criavazia());
    else if ((*a)->nome > valor)
        adicona_arvores(&((*a)->esq),valor);
    else if((*a)->nome < valor)
        adicona_arvores(&((*a)->dir),valor);
    else
    {
        cout << "Numero " << valor <<" ja existante";
    }
}

Arv* buscaRemoveMaior(Arv** a)
{
    if ((*a)->dir!=NULL)
        return buscaRemoveMaior(&(*a)->dir);
    Arv* aux = *a;
    *a = (*a)->esq;
    return aux;
}

Arv* buscaRemoveMenor(Arv** a)
{
    if ((*a)->esq!=NULL)
        return buscaRemoveMenor(&(*a)->esq);
    Arv* aux = *a;
    *a = (*a)->dir;
    return aux;

}

void remover_valor(Arv** a, int valor)
{
    if ((*a)->numero == valor)
    {
        if ((*a)->dir==NULL)
        {
            Arv* aux = *a;
            *a = (*a)->esq;
            free(aux);
        }
        else if ((*a)->esq==NULL)
        {
            Arv* aux = *a;
            *a = (*a)->dir;
            free(aux);
        }
        else
        {
            Arv* aux= buscaRemoveMaior(&(*a)->esq);
            //Arv* aux = buscaRemoveMenor(&(*a)->dir);
            aux->esq = (*a)->esq;
            aux->dir= (*a)->dir;
            free(*a);
            *a = aux;
        }
    }
    else if ((*a)->numero > valor)
    {
        remover_valor(&(*a)->esq, valor);
    }
    else if ((*a)->numero < valor)
    {
        remover_valor(&(*a)->dir, valor);
    }
    else
    {
        cout << "Nao encontrado...";
    }
}
#define pow2(n) (1 << (n))
void printGraph(Arv **raiz)
{
    char fmt[9];
    int dist = 0;
    Arv *root = *raiz;
    Arv **row1, **row2, **rowTemp;
    int rows, row, col;

    if (root==NULL)
    {
        return;
    }
    rows = altura(*raiz);
    row1 =(Arv**) malloc(sizeof(Arv*) * pow2(rows));
    row2 = (Arv**)malloc(sizeof(Arv*) * pow2(rows));
    row1[0] = root;
    for(row=0; row<rows; row++)
    {
        int col2 = 0, cols = pow2(row);
        sprintf(fmt,"%%%dd", pow2(rows-(row+1)));
        dist = pow2(rows-(row+1));
        for(col=0; col<cols; col++)
        {
            Arv *node = row1[col];
            if (node!=NULL)
            {
                printf(fmt, node->numero);
                row2[col2++] = node->esq;
                row2[col2++] = node->dir;
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


void RotDir(Arv **a)
{
    Arv *tmp1, *tmp2;
    tmp1 = (*a)->esq;
    tmp2 = tmp1->dir;
    tmp1->dir = *a;
    (*a)->esq = tmp2;
    *a=tmp1;

}

void RotEsq(Arv **a)
{
    Arv *tmp1, *tmp2;
    tmp1 = (*a)->dir;
    tmp2 = tmp1->esq;
    tmp1->esq = *a;
    (*a)->dir = tmp2;
    *a=tmp1;

}

Arv **Busca(Arv **a, int valor)
{
    if (*a==NULL)
        return NULL;
    if ((*a)->numero == valor)
        return a;
    if ((*a)->numero > valor)
        return Busca(&(*a)->esq, valor);
    return Busca(&(*a)->dir, valor);
}
/*void balancear(Arv **a){
    if(*a){
    if((*a)->esq)
        balancear(&(*a)->esq);
    if((*a)->dir)
        balancear(&(*a)->dir);

    int  valor = balanceamento(*a);
    if (valor > 1)
        RotDir(a);
    else if (valor < -1)
        RotEsq(a);
    }
}*/
void balanceard(Arv **a)
{
     if (!arv_vazia(*a)){

    if((*a)->esq)
        balanceard(&(*a)->esq);
    if((*a)->dir)
        balanceard(&(*a)->dir);

    int  valor = balanceamento(*a);
    if (valor > 1)
    {
        if(balanceamento((*a)->esq)<0)
        {
            RotEsq(&((*a)->esq));
        }
        RotDir(a);

    }
    if (valor < -1)
    {
        if(balanceamento((*a)->dir)>0)
        {

            RotDir(&((*a)->dir));
        }
        RotEsq(a);

    }
     }

}

int main()
{
    Arv* a = arv_criavazia();
    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("C:\\Users\\pattr\\OneDrive - Fundação Edson Queiroz - Universidade de Fortaleza\\Área de Trabalho\\redes neurais\\curso data science");
    //C:\\Users\\pattr\\OneDrive - Fundação Edson Queiroz - Universidade de Fortaleza\\Área de Trabalho\\redes neurais\\curso data science
    /* print all the files and directories within directory */
    string c="";
    int i=0;
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        cout<<lsdir->d_name<<endl;
        if(i>1)
            adicona_arvores(&a,lsdir->d_name);
        i++;
            balanceard(&a);
         arv_imprime (a);
        cout<<i<<endl;

    }



   closedir(dir);


    return 0;
}

/* Arv* a = arv_criavazia();
    adicona_arvore(&a,10);
    balanceard(&a);
    adicona_arvore(&a,8);
    balanceard(&a);
    adicona_arvore(&a,7);
    balanceard(&a);
    adicona_arvore(&a,15);
    balanceard(&a);
    adicona_arvore(&a,21);
    balanceard(&a);
    adicona_arvore(&a,12);
    balanceard(&a);
    arv_imprime(a);
    cout << endl;
    adicona_arvore(&a,23);
    balanceard(&a);
    adicona_arvore(&a,22);

    arv_imprime(a);
    cout << endl;
    printGraph(&a);
    cout << "Encontrar SubArvore desbalanceada" << endl;
    balanceard(&a);

    cout << endl;
    printGraph(&a);
    cout << endl;
    arv_imprime(a);

    cout << "Encontrar SubArvore desbalanceada" << endl;

Arv **TMP = Busca(&a,8);
    if (*TMP != NULL){
        cout << (*TMP)->numero << endl;
        int  valor = balanceamento(*TMP);
        if (valor > 1)
            RotDir(TMP);
        else if (valor < -1)
            RotEsq(TMP);
        cout << endl;
        printGraph(&a);
        cout << endl;
        arv_imprime(a);
    }else {
        cout << "Nao encontrador";
    }*/
// se positivo verificar a esquerda se negativo verificar a direita
