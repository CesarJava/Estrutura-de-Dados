#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef enum {false,true} bool;

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} noDinCircSimpEnc;

noDinCircSimpEnc *prim = NULL;

noDinCircSimpEnc *ult= NULL;

int quant=0;

int primeiroListaDinDuplaEnc()
{
 if(prim == NULL)
    {
        return 0;
    }
 else {
    return prim->valor;
 }
}

int ultimoListaDinDuplaEnc()
{
    if(ult == NULL)
    return 0;
    else
        return ult->valor;
}

int quantListaDinCircSimpEnc()
{
    return quant;
}

void imprimeListaDinCircSimpEncCrescente()
{
    int i = 0;
    noDinCircSimpEnc *atual = prim;
    for(i=0;i<quant;i++){

            printf("[(%2d)%3d]",i,atual->valor);
            atual = atual->prox;

            if((i%5)==0)
                printf("\n");


   }

    printf("\n");


}

void imprimeListaDinCircSimpEncDecrescente()
{
    int i = MAX-1;
    noDinCircSimpEnc *atual = ult;

    for(i=quant-1;i>-1;i--){
            printf("[(%2d)%3d]",i,atual->valor);
            atual = atual->ant;

            if((i%5)==0)
                printf("\n");

    }
     printf("\n");

}

bool insereListaDinCircSimpEnc(int valor)
{
    noDinCircSimpEnc *aux = NULL;
    noDinCircSimpEnc *atual= prim;
    noDinCircSimpEnc *novo;


    novo=(noDinCircSimpEnc *) malloc(sizeof(noDinCircSimpEnc));


    if(prim==NULL)
    {
        prim=novo;
        ult=novo;
        novo->valor = valor;
        novo->prox = novo;
        novo->ant=novo;
    }else
    {
       while(atual->valor <valor)
       {
           aux=atual;
           atual = atual ->prox;
           if(atual == prim)
            break;
       }




    if(aux==NULL)
    {
        prim = novo;
        ult->prox = prim;
    }
    else{
        aux->prox = novo;
        atual->ant = novo;
    }



    novo->valor = valor;
    novo->prox = atual;
    novo->ant = aux;
    if(atual == prim)
    {
        ult = novo;

    }
    }
    quant ++;
    return true;





}



bool removeListaDinCircSimpEnc(int valor)
{
    noDinCircSimpEnc *aux = NULL;
    noDinCircSimpEnc *atual = prim;
    noDinCircSimpEnc *anterior = NULL;

    if(atual != NULL)
    {
       while(atual->valor != valor)
       {

           aux = atual;
           atual = atual->prox;
           if(atual == prim){
            break;
           }
       }
       if(atual->valor !=valor){
        return false;
       }
       else{
            if(atual == prim){
                prim = atual->prox;
                ult->prox = prim;
                prim->ant = ult;
                free(atual);
            }else{
                aux->prox=atual->prox;
                anterior = atual->prox;
                anterior->ant = atual->ant;
                if(atual == ult){
                    ult = aux;
                }
                free(atual);
            }

            free (atual);
            quant--;
            return true;

       }

    }
    else{
        return false;
    }
}



int pesqListaDinDuplaEnc(int valor)
{
    int i = 0;
    noDinCircSimpEnc *atual = prim;

    if(atual != NULL)
    {
        while(atual->valor != valor)
        {
            atual = atual->prox;
            i++;
            if(atual == prim)
            break;
        }

        if(atual->valor != valor)
            return -1;
        else
            return i;
    }else
    return -1;

}


void destroiListaDinCircSimpEnc()
{
    noDinCircSimpEnc *atual = prim;
    noDinCircSimpEnc *apaga;

        while(atual !=NULL){
            apaga = atual;
            atual = atual->prox;
            free(apaga);

        }

}



int main()
{
   int aux,i;
    for(i=0;i<MAX;i++){
        aux = rand() % (MAX*2);
        if(pesqListaDinDuplaEnc(aux) == -1)
        {
            insereListaDinCircSimpEnc(aux);
        }else{
            i--;
        }
    }
    imprimeListaDinCircSimpEncCrescente();
    printf("\n\n\n");
    imprimeListaDinCircSimpEncDecrescente();
    printf("Valor inteiro a ser procurado e removido:");
    scanf("%d",&aux);
    printf("Valor %d => Posicao %d \n",aux,pesqListaDinDuplaEnc(aux));
    removeListaDinCircSimpEnc(aux);
    //imprimeListaDinCircSimpEncCrescente();
       printf("\n\n\n");
    imprimeListaDinCircSimpEncDecrescente();


   return 0;
}


