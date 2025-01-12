#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

//criar pilha
Pilha* criarPilha(){
    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo = NULL;
    }
    return pi;
}
//liberar pilha
void liberarPilha(Pilha *pi){
    if(pi != NULL){
        No *no;
        while((pi->topo) != NULL){
            no = pi->topo;
            pi->topo = pi->topo->prox;
            free(no);
        }
        free(pi);
    }
}
//tamanho da pilha
int tamanhoPilha(Pilha *pi){
    if(pi == NULL) return -1;
    int count = 0;
    No* no = pi->topo;//criando auxilar para percorrer a pilha
    while(no != NULL){
        count++;
        no = no->prox;
    }
    return count;
}
//pilha vazia
int pilhaVazia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->topo == NULL);
}
//inserir na pilha
int push(Pilha *pi, Aluno al){
    if(pi == NULL) return 0;
    No *no = (No*) malloc(sizeof(No));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = pi->topo;
    pi->topo = no;
    return 1;
}
//remover da pilha
int pop(Pilha *pi){
    if(pi == NULL || pilhaVazia(pi)) return 0;
    No *no = pi->topo;
    pi->topo = pi->topo->prox;
    free(no);
    return 1;
}
//consultar elemento do topo
int consultaTopoPilha(Pilha *pi, Aluno *al){
    if(pi == NULL || pilhaVazia(pi)) return 0;
    *al = pi->topo->dados;
    return 1;
}
//imprimir pilha
void imprimirPilha(Pilha *pi){
    if(pi == NULL) return;
    No *no = pi->topo;
    while(no != NULL){
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Nota 1: %.2f\n", no->dados.n1);
        printf("Nota 2: %.2f\n", no->dados.n2);
        printf("Nota 3: %.2f\n", no->dados.n3);
        printf("\n");
        no = no->prox;
    }
}
