#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef enum {false,true} bool;
typedef struct no{
    int elemento;
    struct no *ant;
    struct no*prox;
}noDinDuplaEnc;

noDinDuplaEnc *prim = NULL;

noDinDuplaEnc *ult = NULL;
int quant = 0;

int primeiroListaDinDuplaEnc()
{
    if(prim == NULL)
        return 0;
    else
        return prim->elemento;
}

int ultimoListaDinDuplaEnc()
{
    if(ult == NULL)
        return 0;
    else
        return ult->elemento;
}

int quantListaDinDuplaEnc()
{
    return quant;
}

void imprimeCrescenteListaDinDuplaEnc()
{
   int i = 0;
   noDinDuplaEnc *atual = prim;
   while(atual != NULL)
   {
       printf("[(%2s)%3d]",i,atual->elemento);
       atual=atual->prox;
       i++;
       if((i%5) == 0)
        printf("\n");
   }
   printf("\n");
}
void imprimeDecrescenteListaDinDuplaEnc()
{
    int i = 0;
   noDinDuplaEnc *atual = ult;
   while(atual != NULL)
   {
       printf("[(%2d)%3d]",i,atual->elemento);
       atual=atual->ant;
       i++;
       if((i%5) == 0)
        printf("\n");
   }
   printf("\n");
}
bool insereListaDinDuplaEnc(int valor)
{
    noDinDuplaEnc *aux = NULL;
    noDinDuplaEnc *atual = prim;
    noDinDuplaEnc *novo;

    novo = (noDinDuplaEnc *)malloc(sizeof(noDinDuplaEnc));

    while((atual!=NULL) && (atual->elemento < valor))
    {
    aux = atual;
    atual = atual->prox;
    }

    if(aux == NULL)
    {
    prim = novo;
    }
    else
        aux->prox = novo;

    if(atual == NULL)
        ult = novo;
    else
        atual->ant = novo;

    novo->elemento = valor;
    novo->prox = atual;
    novo->ant = aux;
    quant++;
    return true;
}
bool removeListaDinDuplaEnc(int valor)
{

}

int pesquisaListaDinDuplaEnc(int valor)
{
    int i=0;
    noDinDuplaEnc *atual = prim;

   if(atual != NULL )
   {

   }else return -1;
}

void destroiListaDinDuplaEnc()
{

}
int main()
{
   int aux,i;
   for(i==0;i<MAX;i++)
   {
       aux = rand() %(MAX*2);
       if(pesquisaListaDinDuplaEnc(aux)==-1)
       {
           insereListaDinDuplaEnc(aux);
       }else{
           i--;
       }
   }
   imprimeCrescenteListaDinDuplaEnc();
   imprimeDecrescenteListaDinDuplaEnc();
}
