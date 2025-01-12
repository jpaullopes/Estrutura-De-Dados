#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#define MAX 100

typedef struct aluno{ // Estrutura de dados do aluno
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

typedef struct pilha{
    int qtd; //quantidade de elementos na pilha
    Aluno dados[MAX]; //quantidades de dados na pilha
}Pilha;

//função responsável por criar uma pilha
Pilha* criarPilha(void);
//função responsável por liberar a pilha
void liberarPilha(Pilha *pi);
//função responsável por verificar se a pilha está cheia
int pilhaCheia(Pilha *pi);
//verificar se pilha está vazia
int pilhaVazia(Pilha *pi);
//verificar quantidade de elementos na pilha
int tamanhoPilha(Pilha *pi);
//inserir elemento na pilha
int inserirPilha(Pilha *pi, Aluno al);
//remover elemento da pilha
int removerPilha(Pilha *pi);
//consultar elemento do topo da pilha
int consultarTopoPilha(Pilha *pi, Aluno *al);
//função responsável por imprimir a pilha
void imprimirPilha(Pilha *pi);


#endif // PILHAESTATICA_H