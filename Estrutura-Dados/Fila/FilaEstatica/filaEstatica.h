#define MAX 100 //tamanho maximo da fila

struct aluno{ //estrutura que define um aluno
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct aluno Aluno;

typedef struct fila{
    int inicio,final,quantidade;
    Aluno dados[MAX];
}Fila;

//criar fila
Fila* criarFila();
//liberar fila
void liberarFila(Fila* fi);
//tamanho da fila
int tamanho_fila(Fila* fi);
//se lista cheia
int verificarFilaCheia(Fila* fi);
//se fila vazia
int verificarFilaVazia(Fila* fi);
//inserir no final da fila
int inserirElementoFila(Fila* fi, Aluno al);
//remoção no inicio da fila
int removerElementoFila(Fila* fi);
//consultar inicio da lista
int consultarInicioFila(Fila* fi, Aluno* al);
//imprimir fila
void imprimirFila(Fila* fi);