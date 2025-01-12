typedef struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;

struct elemento {
    Aluno dados;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;
typedef Elem* Lista;

//cria a lista
Lista* criarLista(void);
//liberar lista
void liberarLista(Lista* li);
//tamanho da lista
int tamanhoLista(Lista* li);
//lista cheia?
int listaCheia(Lista* li);
//lista vazia?
int listaVazia(Lista* li);
//inserção no inicio da lista
int insercaoInicio(Lista* li, Aluno al);
//inserção no final da lista
int insercaoFinal(Lista* li, Aluno al);
//inserção de forma ordenada
int insercaoOrdenada(Lista* li, Aluno al);
//remover inicio da lista
int removerInicio(Lista* li);
//remove final da lista
int removerFinal(Lista* li);
//remoção de um elemento específico com base na matricula
int removerElemento(Lista* li, int mat);
//consulta por base de posição
int consultaPosicao(Lista* li, int pos, Aluno *al);
//consulta por base de matricula
int consultaMatricula(Lista* li, int mat, Aluno *al);