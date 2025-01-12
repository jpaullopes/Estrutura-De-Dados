#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Função para criar uma pilha
Pilha criarPilha(int max){
    Pilha pi = (Pilha)malloc(sizeof(struct pilha));// Aloca a pilha
    if(pi != NULL){
        pi->max = max; // Define o tamanho máximo da pilha
        pi->topo = -1; // Define o topo da pilha
        pi->item = (Itemp*)malloc(max*sizeof(Itemp));// Aloca o vetor de itens
    }
    return pi;
}
//função que confere se a pilha está vazia
int pilhaVazia(Pilha pi){
    if(pi->topo == -1) return 1;
    return 0;
}
//função que confere se a pilha está cheia
int pilhaCheia(Pilha pi){
    if(pi->topo == pi->max-1) return 1;
    return 0;
}
//função que insere um item na pilha
int empilha(Pilha pi, Itemp item){
    if(pilhaCheia(pi)) return 0;
    pi->topo++;
    pi->item[pi->topo] = item;
    return 1;
}
//função que remove um item da pilha e retorna ele
Itemp desempilha(Pilha pi){
    if(pilhaVazia(pi)){ 
    puts("Pilha vazia");
    abort();
    }
    Itemp item = pi->item[pi->topo];
    pi->topo--;
    return item;
}
//função que retorna o item do topo da pilha
Itemp topo(Pilha pi){
    if(pilhaVazia(pi)){
        puts("Pilha vazia");
        abort();
    }
    return pi->item[pi->topo];
}
//função que libera a pilha
void desimpilhar(Pilha pi){
    if(pi != NULL){
        free(pi->item);
        free(pi);
    }
    pi = NULL;
}