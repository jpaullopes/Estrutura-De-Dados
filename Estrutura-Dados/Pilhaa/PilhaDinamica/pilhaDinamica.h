#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

typedef struct aluno{ // Estrutura de dados do aluno
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

typedef struct elemento{
    Aluno dados;
    struct elemento *prox;
}No;

typedef struct pilha{
    No *topo;
}Pilha;

//criar pilha
Pilha* criarPilha();
//liberar pilha
void liberarPilha(Pilha *pi);
//tamanho da pilha
int tamanhoPilha(Pilha *pi);
//pilha vazia
int pilhaVazia(Pilha *pi);
//inserir na pilha
int push(Pilha *pi, Aluno al);
//remover da pilha
int pop(Pilha *pi);
//consultar elemento do topo
int consultaTopoPilha(Pilha *pi, Aluno *al);
//imprimir pilha
void imprimirPilha(Pilha *pi);

#endif // PILHADINAMICA_H