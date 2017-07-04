#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALUNOS 69
#define TAM_NOME 30

typedef enum{false, true} bool;

typedef struct no{
char nome[30];
int matricula;
int fatBal;
struct no* esq;
struct no* dir;
} noAluno;

// Estrutura NoAluno
/*
    Inserir struct
*/

//------------------------------------------------------------------------------

void rotacionarParaDireita(noAluno** atual)
{
    /*
        Insira o codigo de rotação para a direita
    */

    noAluno *aux=*atual;

    *atual = aux->esq;
   *atual->dir = aux;


}




void rotacionarParaEsquerda(noAluno** atual)
{
    /*
        Insira o codigo de rotação para a esquerda
    */

    noAluno *aux=*atual;

    *atual = aux->dir;
   *atual->esq = aux;

}

int fatorBalanceamento(noAluno* atual)
{
    int lh,rh;

    if(atual == NULL)
        return(0);

    if(atual->esq == NULL)
        lh = 0;
    else
        lh = 1 + atual->esq->fatBal;

    if(atual->dir == NULL)
        rh = 0;
    else
        rh = 1 + atual->dir->fatBal;

    return (rh - lh);
}

// Insercao na árvore AVL
void inserirNoArvoreAVL(noAluno** noAtual , noAluno* novoNoAluno){

    if(*noAtual == NULL)
    {
        *noAtual = novoNoAluno;
    }
    else
    {
        if(novoNoAluno->matricula < (*noAtual)->matricula)
        {
            inserirNoArvoreAVL(&(*noAtual)->esq, novoNoAluno);

            if(fatorBalanceamento(*noAtual) == -2)
            {
                if(novoNoAluno->matricula < (*noAtual)->esq->matricula)
                    rotacionarParaDireita(noAtual);
                else
                {
                    rotacionarParaEsquerda(&(*noAtual)->esq);
                    rotacionarParaDireita(noAtual);
                }

            }
        }
        else
        {
            inserirNoArvoreAVL(&(*noAtual)->dir, novoNoAluno);

            if(fatorBalanceamento(*noAtual) == 2)
            {
                if(novoNoAluno->matricula > (*noAtual)->dir->matricula)
                    rotacionarParaEsquerda(noAtual);
                else
                {
                    rotacionarParaDireita(&(*noAtual)->dir);
                    rotacionarParaEsquerda(noAtual);
                }
            }
        }
    }

    (*noAtual)->fatBal = fatorBalanceamento(*noAtual);
}

// Insercao na árvore binária simples, desbalanceada
void inserirNoArvoreBinaria(noAluno** noAtual , noAluno* novoNoAluno)
{
    if(*noAtual == NULL)
    {
        *noAtual = novoNoAluno;
    }
    else
    {
        // insere na subárvore da esquerda ou direita
        if(novoNoAluno->matricula < (*noAtual)->matricula)
            inserirNoArvoreBinaria(&(*noAtual)->esq, novoNoAluno);
        else
            inserirNoArvoreBinaria(&(*noAtual)->dir, novoNoAluno);
    }
}

// Busca iterativa na árvore binária (AVL ou não)
noAluno* buscarMatricula(noAluno* raiz, int mat_chave)
{
    /*
        Encontre iterativamente (sem utilizar recursão)
        o aluno cuja matrícula está especificada em mat_chave.
        Percorra a árvore até encontra-lo, e, caso a matrícula
        não exista, retorne NULL.

        Não esqueça de imprimir a quantidade de passos até chegar ao
        aluno procurado ou ao final da árvore (caso não exista matricula
        igual a mat_chave).
    */
}


// Impressão de dados
void imprimeNoAluno(noAluno* no)
{
    printf("> Nome: %s\n", no->nome);
    printf("> Matricula: %d\n", no->matricula);
}

// Liberação de recursos
void libera_arvore(noAluno* atual)
{
    if (atual != NULL)
    {
        libera_arvore(atual->esq);
        libera_arvore(atual->dir);
        free(atual);
    }
}

void em_ordem(noAluno *raiz)
{
    if(raiz!=NULL)
    {
        em_ordem(raiz->esq);
        imprimeNoAluno(raiz);
        printf("\n");
        em_ordem(raiz->dir);
    }
}

int main()
{
    int i, opcao = 0, mat;
    noAluno *novo, *novoAvl;

    // Declaração das árvores
    /*

        Declare aqui e atribua NULL
    */
    noAluno *arvBinaria = NULL;
    noAluno *arvAVL = NULL;

    char listaNomes[NUM_ALUNOS][TAM_NOME] = {"Adrielle", "Anderson", "Andressa", "Antonio", "Arno",
                                            "Augusto", "Barbara", "Bruno", "Calebe", "Cesar", "Cleiton",
                                            "Cynthia", "Daniel", "Daniel", "David", "Denilza", "Drauzio",
                                            "Edson", "Efraim", "Enrico", "Felipe Caetano", "Felipe Ventura",
                                            "Felipe Silva", "Felipe Coelho", "Fernando", "Gabriel Ferreira",
                                            "Gabriel Krupa", "Gabriel Moreira", "Glauber Oliveira", "Guilherme Lopes",
                                            "Guilherme Yamamura", "Gustavo", "Henrique", "Hugo", "Isaac","Italo Guimarães",
                                            "Italo Rosa", "Jacqueline", "Jose", "Lucas Vinci", "LucasMassari", "Lucas Silva",
                                            "Luiz Fernando", "Luiz Guilherme", "Marcelo", "Marcos", "Matheus Ferreira",
                                            "Matheus Silva", "Mauricio", "Michell", "Nicholas", "Paloma", "Paulo", "Pedro Henrique",
                                            "Pedro Miguel", "Rafael", "Renan", "Renato", "Rodrigo", "Saulo", "Silvio", "Tiago",
                                            "Udo", "Victor", "Vinicius Barros", "Vinicius Silva", "William", "Wu","Yan"};

    int listaMatriculas[NUM_ALUNOS]={24962, 26633, 28282, 18690, 25646, 28554, 27157, 26661, 28455, 28926, 26665, 24969,
                                    28774, 28966, 25784, 22150, 28235, 28227, 25478, 23654, 26904, 28008, 24359, 25150,
                                    26581, 27969, 27845, 21444, 28085, 27143, 21731, 28910, 21459, 27106, 27425, 22880,
                                    27583, 27370, 25768, 24034, 27918, 24648, 24736, 28782, 27012, 26680, 27253, 27021,
                                    24528, 26641, 16931, 27536, 27576, 28155, 27895, 26771, 27649, 24844, 26620, 27586,
                                    28741, 27354, 26588, 28095, 27190, 18741, 28152, 23840, 26579};

    // para cada elemento do vetor listaNomes
    for(i = 0; i < NUM_ALUNOS; i++)
    {
        // é alocado um ponteiro para cada noAluno
        novo = (noAluno*) malloc(sizeof(noAluno));
        novoAvl = (noAluno*) malloc(sizeof(noAluno));

        // são preenchidos o nome e a matrícula
        strcpy(novo->nome, listaNomes[i]);
        novo->matricula = listaMatriculas[i];
        novo->dir = NULL;
        novo->esq = NULL;

        // são preenchidos o nome e a matrícula do no da AVL
        strcpy(novoAvl->nome, listaNomes[i]);
        novoAvl->matricula = listaMatriculas[i];
        novoAvl->dir = NULL;
        novoAvl->esq = NULL;

        // é chamado o método de inserção na árvore binária e arvore AVL
        inserirNoArvoreBinaria(&arvBinaria, novo);
        inserirNoArvoreAVL(&arvAVL, novoAvl);
    }

    printf("Arvores completamente montadas...\n");
    system("pause");
    em_ordem(arvAVL);
    system("pause");

    while(opcao != 2)
    {
        system("cls");
        printf("Busca: \n");
        printf("----------------------\n");
        printf("Numero de matricula: ");
        scanf("%d", &mat);

        printf("\n");
        printf("Utilizando a arvore binaria simples:\n");
        printf("------------------------------------------\n");
        noAluno* resp = buscarMatricula(arvBinaria, mat);

        if(resp == NULL)
            printf("Aluno nao encontrado");
        else
        {
            printf("Aluno Encontrado:\n");
            imprimeNoAluno(resp);
        }

        printf("\n\nUtilizando a arvore AVL:\n");
        printf("------------------------------------------\n");
        resp = buscarMatricula(arvAVL, mat);

        if(resp == NULL)
            printf("Aluno nao encontrado");
        else
        {
            printf("Aluno Encontrado:\n");
            imprimeNoAluno(resp);
        }

        printf("\n\n");
        printf("Digite 1 para continuar ou 2 para sair: ");
        scanf("%d", &opcao);

    }

    // Liberando Memória
    printf("Encerrando o programa...\n");
    libera_arvore(arvBinaria);
    libera_arvore(arvAVL);

    return 0;
}
