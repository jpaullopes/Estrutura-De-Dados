#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

//criar fila
Fila* criarFila(){
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->quantidade = 0;
    }
    return fi;
}
//liberar fila
void liberarFila(Fila* fi){
    free(fi);
}
//tamanho da fila
int tamanho_fila(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    return fi->quantidade;
}
//se lista cheia
int verificarFilaCheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->quantidade == MAX){
        return 1;
    }
    return 0;
}
//se fila vazia
int verificarFilaVazia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->quantidade == 0) return 1;
    return 0;
}
//inserir no final da fila
int inserirElementoFila(Fila* fi, Aluno al){
    if(fi == NULL) return 0;
    if(verificarFilaCheia(fi)) return 0;

    fi->dados[fi->final] = al;
    fi->final = (fi->final+1)%MAX;// garante que a fila seja circular, pois se o final for igual a MAX, ele volta para 0
    fi->quantidade++;
    return 1;
}
//remoção no inicio da fila
int removerElementoFila(Fila* fi){
    if(fi == NULL || verificarFilaVazia(fi)) return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->quantidade--;
    return 1;
}
//consultar inicio da lista
int consultarInicioFila(Fila* fi, Aluno* al){
    if(fi == NULL || verificarFilaVazia(fi)) return 0;
    *al = fi->dados[fi->inicio]; //passa o valor do inicio da fila para o ponteiro al
    return 1;
}
//imprimir fila
void imprimirFila(Fila* fi){
    if(fi == NULL) return;
    int i = fi->inicio;
    int contador;
    for(contador = 0; contador < fi->quantidade; contador++){
        printf("Matricula: [ %d ]\n", fi->dados[i].matricula);
        printf("Nome: [ %s ]\n", fi->dados[i].nome);
        printf("Notas: %.2f | %.2f | %.2f |\n", fi->dados[i].n1, fi->dados[i].n2, fi->dados[i].n3);
        i = (i+1)%MAX;
    }
}