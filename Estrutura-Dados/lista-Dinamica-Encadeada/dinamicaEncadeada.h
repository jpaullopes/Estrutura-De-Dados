
//prototipos das funções
//Tipos de dados a serem armazenadas na lista
//ponteiro para o próximo elemento da lista

typedef struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

struct elemento{
    Aluno dados;
    struct elemento *proximo;
};
typedef struct elemento *Lista;

//cria uma lista vazia
Lista* criarLista(void);
//Liberar Lista
void liberarLista(Lista* li);
//Saber o tamanho da lista
int tamanhoLista(Lista *li);
//Retornar o tamanho da lista(Usando recursividade)
int tamanhoListaRecursivo(Lista li);
//Saber se lista está vazia
int listaVazia(Lista *li);
//Saber se lista está cheia
int listaCheia(Lista *li);
//insere no inicio
int inserirComecoLista(Lista *li, Aluno al);
//insere no final
int inserirFinalLista(Lista *li, Aluno al);
//inserção ordenada
int inserirListaOrdenada(Lista *li, Aluno al);
//remoção no inicio da lista
int removerComecoLista(Lista *li);
//remoção no final da lista
int remocaoFinalLista(Lista *li);
//remoção lista ordenadamente com base na matricula
int remocaoListaOrdenada(Lista *li, int mat);
//consulta dados de um aluno com base na matricula
int consultaListaMatricula(Lista *li, int mat, Aluno *al);
//consulta dados de um aluno com base na posição
int consultaListaPosicao(Lista *li,int pos, Aluno *al);
//exibe a lista
void exibirLista(Lista li); //tratando sem ponteiro e sim como uma copia da lista
//Anexação de listas encadeadas
int anexarListas(Lista *lista1, Lista *lista2);