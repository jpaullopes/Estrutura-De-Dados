struct aluno { // Estrutura de dados do aluno
    int matricula;
    char nome[30];
    float n1, n2, n3;
};	
typedef struct aluno Aluno;

struct no{ // Estrutura de dados do nó
    Aluno dados;
    struct no *prox;
};

typedef struct no No;

typedef struct fila{ // Estrutura de dados da fila | uso de nó descritor
    No *inicio;
    No *fim;
    int qtd;
}Fila;

//criação da fila
Fila *criaFila();
//liberação da fila
void liberaFila(Fila *fi);
//tamanho da fila
int tamanhoFila(Fila *fi);
//Verificar se a fila está vazia
int filaVazia(Fila *fi);
//verificar seestá cheia
int filaCheia(Fila *fi);
//inserção na fila
int insereFila(Fila *fi, Aluno al);
//remoção da fila
int removeFila(Fila *fi);
//consulta do início da fila
int consultaFila(Fila *fi, Aluno *al);
//impressão da fila
void imprimeFila(Fila *fi);