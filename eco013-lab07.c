#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// ----------------- >>> definição do tipo modoCaminhamento
typedef enum {preordem,emordem,posordem} modoCaminhamento;




typedef struct no
{
    char cep[9];
    char uf[3];
    char cidade[31];
    char logradouro[61];
    struct no* esq;
    struct no* dir;
} noCEP; //estrutura das cédulas

noCEP *arvBinaria;

int quant;

void inserirNoArvoreBinaria(FILE *arq)
{
    char linha[200];
    char *substring;
    int i;
    noCEP *ant = NULL;
    noCEP *atual = arvBinaria;
    noCEP * novo;

    // aloco o novo na memória
    novo = (noCEP *) malloc(sizeof(noCEP));

    // lê a linha completa e preenche os dados no novo cep
    fgets(linha, 200, arq);
    // separa os tokens pelo delimitador \t
    substring = strtok(linha, "\t");

    // obtem o cep
    if(substring!= NULL)
    {
        strcpy(novo->cep, substring);
    }
    substring = strtok(NULL, "\t");

    // obtem a uf
    if(substring!= NULL) strcpy(novo->uf, substring);
    substring = strtok(NULL, "\t");

    // obtem a cidade
    if(substring!= NULL) strcpy(novo->cidade, substring);
    substring = strtok(NULL, "\t");
    // obtem o logradouro
    if(substring!= NULL) strcpy(novo->logradouro, substring);

    // incializa com null os ponteiros esq e dir de novo
    novo->esq = NULL;
    novo->dir = NULL;

    //printf("\nLido os dados de um cep: \n");
    //imprimeNoCEP(novo);


    // ----------------- >>> COMPLETE!
    // ----------------- >>> código para inserção de novo na árvore
    // ----------------- >>> veja as implementações de arvoreBinBuscaString.c

    while(atual!=NULL && (novo->cep!=atual->cep))
    {
        ant = atual;

        if(strcmp(novo->cep,atual->cep) == 1 )
            atual = atual->esq;
        else
            atual = atual->dir;

    }

    if(ant==NULL)
        arvBinaria = novo;
        quant++;
    else
    {
        if(atual==NULL)
        {
            quant++;
            if(strcmp(novo->cep,ant->cep)== 1)
                ant->esq = novo;
            else
                ant->dir = novo;
        }

    }





}


void imprimeNoCEP(noCEP *arvore)
{
    printf("CEP:%s  UF:%s  Cidade:%s Logradouro:%s",arvore->cep,arvore->uf,arvore->cidade,arvore->logradouro);
}



void imprimePreOrdem(noCEP **arvore)
{
    while(arvore!=NULL)
    {
    imprimeNoCEP(arvore);
    imprimePreOrdem(arvore->esq);
    imprimePreOrdem(arvore->dir);

    }
}

void imprimeEmOrdem(noCEP **arvore)
{

    while(arvore!=NULL)
    {
    imprimePreOrdem(arvore->esq);
    imprimeNoCEP(arvore);
    imprimePreOrdem(arvore->dir);

    }
}



void imprimePosOrdem(noCEP **arvore)
{
    while(arvore!=NULL)
    {
    imprimePreOrdem(arvore->esq);
    imprimePreOrdem(arvore->dir);
    imprimeNoCEP(arvore);
    }

}
// ----------------- >>> código das funções imprimeNoCEP, imprimePreOrdemArvBB,
// ----------------- >>> imprimeEmOrdemArvBB, imprimePosOrdemArvBB e
// ----------------- >>> buscarArvoreBinaria
// ----------------- >>> veja as implementações de arvoreBinBuscaString.c


// função principal: já está TODA IMPLEMENTADA
int main()
{
    FILE *arq;
    int opcaoMenu;
    char cepProcurado[9];
    noCEP *cepEncontrado;

    // inicializa a árvore
    arvBinaria = NULL;

    // o arquivo é lido e inserido os elementos na árvore
    arq = fopen("baseCep.txt", "r");

    if(!arq)
    {
        printf("O arquivo nao pode ser aberto.\n");
        exit(1);
    }

    printf("\nInserindo elementos na arvore... \n");
    while(!feof(arq))
    {
        // para cada linha do arquivo pe chamada
        // a função de inserção na árvore binária
        inserirNoArvoreBinaria(arq);
    }
    fclose(arq);

    // menu para caminhamento na árvore de ceps
    opcaoMenu = 1;
    while(opcaoMenu != 4)
    {
        quant = 0;

        printf("|Selecione uma das opcoes do menu: |\n");
        printf("|1 - Pre-ordem                |\n");
        printf("|2 - Em-ordem                 |\n");
        printf("|3 - Pos-ordem                |\n");
        printf("|4 - Sair                     |\n\n");
        printf(">");

        scanf("%d", &opcaoMenu);
        switch(opcaoMenu)
        {
        case 1:
            printf("Imprime em pre-ordem: \n");
            imprimePreOrdemArvBB(arvBinaria);
            printf("\n");
            break;

        case 2:
            printf("Imprime em in-ordem: \n");
            imprimeEmOrdemArvBB(arvBinaria);
            printf("\n");
            break;

        case 3:
            printf("Imprime em pos-ordem: \n");
            imprimePosOrdemArvBB(arvBinaria);
            printf("\n");
            break;

        case 4:
            printf("Saindo do menu impressoes: ");
            break;
        }

    }// fecha while

    // chamada à busca por um cep
    printf("\n>>> Busca por um cep: \n");
    printf(">> Digite um cep: ");
    scanf("%s", cepProcurado);
    buscarArvoreBinaria(arvBinaria,cepProcurado);

    printf("Encerrando o programa...\n");

    free(arvBinaria);

    system("PAUSE");

    return 0;
}
