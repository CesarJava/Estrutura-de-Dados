#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define TAM_NOME 50
#define NUM_ALUNOS 69

typedef enum {false,true} bool;
typedef struct no {
    int valor;
   // struct no *ant;
    struct no *prox;
} noDinCircSimpEnc;



// Inicializando a lista encadeada
noAluno* inicializaListaAlunos(char nomes[NUM_ALUNOS][TAM_NOME], int matriculas[NUM_ALUNOS])
{
    int i;
    noAluno* primeiro;
    noAluno* atual, *anterior;

    primeiro = (noAluno*) malloc(sizeof(noAluno));
    primeiro->matricula = matriculas[0];
    strcpy(primeiro->nome, nomes[0]);
    primeiro->prox=NULL;

    anterior = primeiro;

    for(i = 0; i < NUM_ALUNOS; i++)
    {
        atual = (noAluno*) malloc(sizeof(noAluno));
        atual->matricula = matriculas[i];
        strcpy(atual->nome, nomes[i]);

        atual->prox = NULL;
        anterior->prox = atual;
        anterior = atual;
    }

    return primeiro;
}

// Impressão de dados
void imprimeLista(noAluno* primeiro)
{
    noAluno* atual;
    atual = primeiro;

    while(atual != NULL)
    {
        printf("%d - %s\n", atual->matricula, atual->nome);
        atual = atual->prox;
    }
}

// Realiza Pesquisa
noAluno* pesquisaMatricula(noAluno* primeiro, int matriculaBuscada)
{
    noAluno* atual;
    atual = primeiro;

    while(atual != NULL)
    {
        if(atual->matricula == matriculaBuscada)
            return atual;
        atual = atual->prox;
    }

    return NULL;

}

// Imprimindo dados do aluno
void imprimeDadosDoAluno(noAluno* aluno)
{
    if(aluno != NULL)
        printf(">>> Aluno encontrado: \n%d - %s\n", aluno->matricula, aluno->nome);
    else
        printf(">>> Aluno nao encontrado\n");
}


int main(){

    char matrizNomes[NUM_ALUNOS][TAM_NOME] = {
        "Adrielle Messias Gerez",
        "Anderson Carvalho Pereira",
        "Andressa Couto Camargo",
        "Antonio Luiz Bueno",
        "Arno Teixeira Soares Junior",
        "Augusto Cesar Rossi de Mattos",
        "Barbara do Prado Souza",
        "Bruno de Jesus Braga",
        "Calebe Leme Silverio",
        "Cesar Luiz Javaroni Filho",
        "Cleiton dos Santos",
        "Cynthia Yassuko Shibasaki",
        "Daniel Arthur Silveira Tapia",
        "Daniel Dias Gomes",
        "David dos Anjos Bovolenta",
        "Denilza Lopes Nanjunga",
        "Drauzio Ramos Oppenheimer",
        "Edson Beltrane Junior",
        "Efraim Rabelo de A. Vaciloto",
        "Enrico Salemi Faria",
        "Felipe Caetano Castilho",
        "Felipe de Lima Ventura",
        "Felipe Farias da Silva",
        "Felipe Vieira Coelho",
        "Fernando Henrique S. Abolafio",
        "Gabriel Gonçalves Ferreira",
        "Gabriel Pedro Krupa",
        "Gabriel Rodrigues Puci Moreira",
        "Glauber Almeida de Oliveira",
        "Guilherme Braga Lopes",
        "Guilherme Silva Yamamura",
        "Gustavo Felipe Penedo",
        "Henrique Fernandes Saura",
        "Hugo Uchoas Borges",
        "Isaac Beuren Silva",
        "Italo Pereira Guimarães",
        "Italo Rosa",
        "Jacqueline Sayuri M. Kiko",
        "Jose Eduardo Marques Silva",
        "Lucas Eduardo Vital Vinci",
        "Lucas Grunewald Massari",
        "Lucas Vilela Silva",
        "Luiz Fernando C. Castrizana",
        "Luiz Guilherme Ferreira",
        "Marcelo Moreira Nicoletti",
        "Marcos Vinicius de O. Duque",
        "Matheus Lourenco Ferreira",
        "Matheus Rodrigues da Silva",
        "Mauricio Jornada Bastos",
        "Michell Fernandes de P. Piazza",
        "Nicholas Augusto da S. Ribeiro",
        "Paloma Gouvea Leandro",
        "Paulo Roberto Borim",
        "Pedro Henrique Bertao Matos",
        "Pedro Miguel N. Oliveira",
        "Rafael Fischer Viola",
        "Renan Zanin Oliveira",
        "Renato Quintanilha dos Passos",
        "Rodrigo Toshiaki Horie",
        "Saulo Antunes Silva",
        "Silvio Paulo Rennó Filho",
        "Tiago Alves Dulce",
        "Udo de Lima Andrade",
        "Victor Duarte de Oliveira",
        "Vinicius Barros Moura",
        "Vinicius F.p.nogueira da Silva",
        "William Almeida Suzukayama",
        "Wu Liang Kuan",
        "Yan Yamamura"
    };

    int vetorMatriculas[NUM_ALUNOS]={24962, 26633, 28282, 18690, 25646, 28554, 27157, 26661, 28455, 28926, 26665, 24969,
                                    28774, 28966, 25784, 22150, 28235, 28227, 25478, 23654, 26904, 28008, 24359, 25150,
                                    26581, 27969, 27845, 21444, 28085, 27143, 21731, 28910, 21459, 27106, 27425, 22880,
                                    27583, 27370, 25768, 24034, 27918, 24648, 24736, 28782, 27012, 26680, 27253, 27021,
                                    24528, 26641, 16931, 27536, 27576, 28155, 27895, 26771, 27649, 24844, 26620, 27586,
                                    28741, 27354, 26588, 28095, 27190, 18741, 28152, 23840, 26579 };

    noAluno* listaAlunos = inicializaListaAlunos(matrizNomes, vetorMatriculas);

    printf("***** Dados da lista de alunos\n");
    imprimeLista(listaAlunos);
    printf("\n\n");

    printf("***** Pesquisa por um aluno\n");
    printf("Informe o numero de matricula: ");
    int matricula;
    scanf("%d", &matricula);
    noAluno* encontrado = pesquisaMatricula(listaAlunos, matricula);
    imprimeDadosDoAluno(encontrado);

    return 0;

}

