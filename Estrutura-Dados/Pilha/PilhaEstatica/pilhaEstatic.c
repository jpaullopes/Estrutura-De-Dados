#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"

//função responsável por criar uma pilha
Pilha* criarPilha(void){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->qtd = 0;
    }
}
//função responsável por liberar a pilha
void liberarPilha(Pilha *pi){
    free(pi);
}
//função responsável por verificar se a pilha está cheia
int pilhaCheia(Pilha *pi){
    if(pi == NULL){
        return -1;
    }
    return (pi->qtd == MAX); //verificando se qauntidade de elementos é igual ao tamanho máximo
}
//verificar se pilha está vazia
int pilhaVazia(Pilha *pi){
    if(pi == NULL) return -1;
    return (pi->qtd == 0); //verificando se a quantidade de elementos é igual a 0
}
//verificar quantidade de elementos na pilha
int tamanhoPilha(Pilha *pi){
    if(pi == NULL) return -1;
    return pi->qtd; //retornando a quantidade de elementos
}
//inserir elemento na pilha
int inserirPilha(Pilha *pi, Aluno al){
    if(pi == NULL || pilhaCheia(pi)) return 0;
    pi->dados[pi->qtd] = al; //elemento é inserido na pilha na posição qtd
    pi->qtd++;
    return 1;
}
//remover elemento da pilha
int removerPilha(Pilha *pi){
    if(pi == NULL || pilhaVazia(pi)) return 0;
    pi->qtd--; //diminuindo a quantidade de elementos
    return 1;
}
//consultar elemento do topo da pilha
int consultarTopoPilha(Pilha *pi, Aluno *al){
    if(pi == NULL || pilhaVazia(pi)) return 0;
    *al = pi->dados[pi->qtd-1]; //pegando o elemento do topo da pilha
    return 1;
}
//função responsável por imprimir a pilha
void imprimirPilha(Pilha *pi){
    if(pi == NULL) return;
    for(int i = 0; i < pi->qtd; i++){
        printf("Matricula: %d\n", pi->dados[i].matricula);
        printf("Nome: %s\n", pi->dados[i].nome);
        printf("Nota 1: %.2f\n", pi->dados[i].n1);
        printf("Nota 2: %.2f\n", pi->dados[i].n2);
        printf("Nota 3: %.2f\n", pi->dados[i].n3);
        printf("\n");
    }
}