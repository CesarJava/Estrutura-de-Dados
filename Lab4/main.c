#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false,true} bool;

#define TAM_NOME 20
#define TAM_TELEFONE 10

typedef struct no
{
 char nome[TAM_NOME];
 char telefone[TAM_TELEFONE];
 struct no * prox;
 struct no * ant;
} noContato;

int quant = 0;

bool insereContatoNaAgenda(noContato *novo,noContato **lista)
{


    noContato *atual = *lista;
    noContato *aux = NULL;


    if (*lista==NULL)
    {

        *lista = novo;
        //prim = novo;
        //ult = novo;
        quant++;
        return true;
    }
    else
    {

        while((atual!=NULL)&& (strcmp(atual->nome,novo->nome) <0))
        {
            aux = atual;
            atual = atual->prox;
        }


        if(aux!=NULL)
        {

        aux->prox = novo;
        novo->prox = atual;
        novo->ant = aux;


        }else
        {
        printf("%s",novo->nome);
        novo->prox = atual;
        atual->ant = novo;
        *lista=novo;
        }
        quant++;
        return true;

    }
}

void imprimeAgenda(noContato **lista)
{
    noContato *atual = *lista;
    int i;
    for(i=0;i<quant;i++)
    {
        printf("%s  -  %s\n",atual->telefone,atual->nome);
        atual = atual->prox;
        if(atual == NULL)
            break;
    }

}

bool removeContatoDaAgenda(char nome[TAM_NOME],noContato** lista)
{
     noContato *atual = *lista;
     noContato *aux = NULL;
     int i;
      for(i=0;i<quant;i++)
    {
        if(strcmp(nome,atual->nome) == 0)
        {
            if(aux == NULL)
            {
                *lista = atual->prox;
                free(atual);

            }else
            {

                if(atual->prox != NULL)
                {

                aux->prox = atual->prox;
                atual->prox->ant = aux;
                free(atual);
                }else
                {

                free(atual);
                }

            }
            quant--;
            return true;
        }
        aux=atual;
        atual = atual->prox;
    }
    return false;

}

int main()
{
    noContato *novo = NULL;
    noContato *lista = NULL;

    novo = (noContato *) malloc(sizeof(noContato));
    strcpy(novo->nome,"Abreu Silva");
    strcpy(novo->telefone,"23456789");
    insereContatoNaAgenda(novo,&lista);

    novo = (noContato *) malloc(sizeof(noContato));
    strcpy(novo->nome,"Daniela SIla");
    strcpy(novo->telefone,"23456789");
    insereContatoNaAgenda(novo,&lista);

    novo = (noContato *) malloc(sizeof(noContato));
    strcpy(novo->nome,"Joao da Silva");
    strcpy(novo->telefone ,"12345678");
    insereContatoNaAgenda(novo,&lista);



    imprimeAgenda(&lista);
/*
    removeContatoDaAgenda("Joao da Silva",&prim);
    printf("\n\n\n");
    imprimeAgenda(&prim);*/
    return 0;
}
