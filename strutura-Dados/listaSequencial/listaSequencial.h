#define MAX 100

// Estrutura do aluno
// Contém a matrícula, nome e notas do aluno
typedef struct aluno{
    // Matrícula do aluno
    int matricula;
    // Nome do aluno
    char nome[30];
    // Notas do aluno
    float nota1,nota2,nota3;
}Aluno;

// Estrutura da lista
typedef struct lista Lista;
// Cria uma nova lista
Lista* criarLista();

// Libera a memória alocada para a lista
void liberarLista(Lista *l);

// Retorna a quantidade de alunos na lista
int tamanhoLista(Lista *li);

//Retorna 1 se a lista estiver cheia e 0 se não estiver
int listaCheia(Lista *li);

//Retorna 1 se a lista estiver vazia e 0 se não estiver
int listaVazia(Lista *li);

//Inserção de um aluno no final da lista
int inserirFinalLista(Lista *li, Aluno al);

//Inserção de um aluno no inicio da lista
int  inserirInicioLista(Lista *li, Aluno al);
//Inserção de um aluno de forma ordenada
int insercaoOrdenada(Lista* li, Aluno al);
//Remoção de um aluno do final da lista
int removerFinalLista(Lista* li);
//Remoção de um aluno do inicio da lista
int removerInicioLista(Lista* li);
//Remoção de um aluno do meio da lista
int removerOrdenadamenteLista(Lista* li,int matricula);

//Busca sequencial de um aluno na lista
int buscaSequencialLista(Lista* li,int matricula,Aluno *al);

//Busca por posição de um aluno na lista
int buscaPosicaoLista(Lista *li, int pos, Aluno *al);