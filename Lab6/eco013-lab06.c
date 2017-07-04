#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FILAS 3
#define TAM_NOME 50

typedef enum {false, true} bool;

//estrutura de um processo
typedef struct no
{
    float tamanho;
    char nome[TAM_NOME];
    int prioridade;
    struct no* prox;
} noProcesso;

//fila de processos a serem executados na CPU
noProcesso * filaDeProcessos[NUM_FILAS];

void inicializaFila()
{
    int i;
    for(i=0;i<3;i++)
    {
        filaDeProcessos[i] = NULL;
    }
}

// vetor que indica a exist�ncia de pelo menos um processo dessa prioridade
bool prioridadesProcessos[10];

void inicializaVetorPrioridades()
{
    int i;
     for (i=0;i<10;i++)
     {
         prioridadesProcessos[i] = false;
     }
}




void insereFila(float tamanho, char nome[TAM_NOME], int prioridade)
{
    int i;
    int pos; // posi��o da fila a ser inserido o processo
    noProcesso * novo, * atual;

    // de acordo com a prioridade do processo novo
    // � definida a fila onde ser� inserido
    switch(prioridade)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        pos=0;
        break;
    case 4:
    case 5:
    case 6:
        pos=1;
        break;
    case 7:
    case 8:
    case 9:
        pos=2;
        break;
    default :
        printf("valor de prioridade inv�lido\n");
    }

    // atualiza para true o vetor prioridadeProcessos
    prioridadesProcessos[prioridade] = true;

    // criar novo elemento do tipo noProcesso na mem�ria
    novo = (noProcesso *) malloc(sizeof(noProcesso));
    // preencher os dados de prioridade e tamanho processo
    novo->tamanho = tamanho;
    novo->prioridade = prioridade;
    // preencher os nome do processo
    strcpy(novo->nome,nome);
    // inicializa o ponteiro prox com null
    novo->prox = NULL;
    // adiciona como �ltimo elemento da fila correspondente
    // verifico se a fila est� vazia
    if(filaDeProcessos[pos] == NULL)
    {
        filaDeProcessos[pos] = novo;
    }
    else    // a fila n�o est� vazia
    {
        // tenho que achar o �ltimo elemento da fila
        atual = filaDeProcessos[pos];
        while(atual->prox!=NULL)
        {
            // aponta para o pr�ximo
            atual = atual->prox;
        }
        // o �ltimo elemento passa a ser o que adicionei mais recentemente
        atual->prox = novo;
    }
} // fecha fun��o insereFila

void imprimeDadosListasDeProcessos()
{
    noProcesso * atual;
    int i, contProcessos;
    float somaTamanhos;
    // para cada fila
    for(i=0; i<NUM_FILAS; i++)
    {
        printf("\n>> Fila %d:", i);
        // em atual armazeno o primeiro da fila
        atual = filaDeProcessos[i];
        // inicializo o contador e somaTamanhos dessa fila
        contProcessos  = 0 ;
        somaTamanhos = 0;
        //percorre cada fila
        while(atual!=NULL)
        {
            printf("\n> Processo %d= nome: %s;  tamanho %f; prioridade %d", contProcessos+1, atual->nome, atual->tamanho, atual->prioridade);
            // incremento o n�mero de processos
            contProcessos++;
            //acumulando a soma dos tamanhos
            somaTamanhos+= atual->tamanho;
            //proximo elemento
            atual = atual->prox;
        }
        printf("\n>>> Numero processos= %d - > Tamanho total= %f \n",contProcessos, somaTamanhos);
    }

}// fecha fun��o imprimeDadosListasDeProcessos



bool retiraPrimeiroDaFila(int indiceFila)
{

    noProcesso * atual;

    // em atual armazeno o primeiro da fila
    atual = filaDeProcessos[indiceFila];

    // se a fila n�o estiver vazia
    if(atual !=NULL)
    {
        // o primeiro elemento da fila � retirado
        filaDeProcessos[indiceFila] = atual->prox;

        return true;
    }
    return false;
}// fecha fun��o retiraPrimeiroDaFila


bool retiraMaiorPrioridadeDaFila(int indiceFila)
{
    int i;
    noProcesso * atual, *ant;

    // determina a prioridade maior daquela fila
    switch(indiceFila)
    {
    case 0:
        for(i=3; i>=0; i--)
        {
            if(prioridadesProcessos[i]) break;
        }
        break;
    case 1:
        for(i=6 ;i>=4; i--)
        {
            if(prioridadesProcessos[i]) break;
        }
        break;
    case 2:
        for(i=9; i>=7; i--)
        {
            if(prioridadesProcessos[i]) break;
        }
        break;
    default:
        return false;
    }

    // em atual e em ant armazeno o primeiro da fila
    atual = filaDeProcessos[indiceFila];
    ant = filaDeProcessos[indiceFila];
    // se a fila n�o estiver vazia
    while(atual!=NULL)
    {
        // se o elemento que estou visitando tem a maior prioridade
        // da fila, ent�o esse elemento � retirado
        if(atual->prioridade == i )
        {
            // se � o primeiro da fila, atualizo o no cabe�a
            if(atual == ant)
            {
                filaDeProcessos[indiceFila] = ant->prox;
            }
            else
            {
                // atualizo o pr�ximo do elemento anterior
                ant->prox = atual->prox;
            }
            // atualizando o booleando de prioridades
            prioridadesProcessos[i] = false;
            return true;
        }
        // atualizo o anterior
        ant = atual;
        // aponto para o pr�ximo
        atual = atual->prox;
    }// fecha while
    return false;
}// fecha fun��o retiraMaiorPrioridadeDaFila

int main(int argc, char** argv)
{
inicializaFila();
inicializaVetorPrioridades();
insereFila(1, "BrOfficeCalc", 3);
insereFila(2.3, "CodeBlocks", 9);
insereFila(0.5, "Calculadora", 1);
insereFila(6.4, "Firefox", 7);
insereFila(3.1, "PhpMyAdmin", 2);
insereFila(2.9, "Kile", 4);
insereFila(4.5, "Gimp", 9);
insereFila(5.5, "BrOfficeWriter", 6);
insereFila(5.8, "GCC", 2);
imprimeDadosListasDeProcessos();
printf("\n\t===================================================================\n");
retiraPrimeiroDaFila(2);
imprimeDadosListasDeProcessos();


while(retiraMaiorPrioridadeDaFila(1))
{
 printf("\n\t=================================================================\n");
 imprimeDadosListasDeProcessos();
}
printf("A fila 1 est� vazia!");


return 0;
}
