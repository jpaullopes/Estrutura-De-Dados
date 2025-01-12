#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

//criação da fila
Fila *criaFila(){
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){//Alocação aconteceu com sucesso
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->qtd = 0;
    }
    return fi;
}
//liberação da fila
void liberaFila(Fila *fi){
    if(fi != NULL){
        No *auxiliar;
        while(fi->inicio = NULL){
            auxiliar = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(auxiliar);
        }
        free(fi);
    }
}
//tamanho da fila
int tamanhoFila(Fila *fi){
    if(fi == NULL){
        return 0;
    }
    return fi->qtd;
}
//Verificar se a fila está vazia
int filaVazia(Fila *fi){
    if(fi == NULL){
        return 1;
    }
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;
}
//verificar seestá cheia
int filaCheia(Fila *fi){
    return 0;
}
int insereFila(Fila *fi, Aluno al){
    if(fi == NULL){
        return 0;
    }
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        return 0;
    }
    novo->dados = al;
    novo->prox = NULL;
    if(fi->fim == NULL){
        fi->inicio = novo;
    }else{
        fi->fim->prox = novo;
    }
    fi->fim = novo;
    fi->qtd++;
    return 1;
}
//remoção da fila
int removeFila(Fila *fi){
    if(fi == NULL){
        return 0;
    }
    if(fi->inicio == NULL){
        return 0;
    }
    No *auxiliar = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){
        fi->fim = NULL;
    }
    free(auxiliar);
    fi->qtd--;
    return 1;
}
//consulta do início da fila
int consultaFila(Fila *fi, Aluno *al){
    if(fi == NULL || fi->inicio == NULL){
        return 0;
    }
    *al = fi->inicio->dados;
    return 1;
}
//impressão da fila
void imprimeFila(Fila *fi){
    if(fi == NULL){
        return;
    }
    No *auxiliar = fi->inicio;
    while(auxiliar != NULL){
        printf("Matricula: [ %d ]\n", auxiliar->dados.matricula);
        printf("Nome: [ %s ]\n", auxiliar->dados.nome);
        printf("Notas: %.2f | %.2f | %.2f\n", auxiliar->dados.n1, auxiliar->dados.n2, auxiliar->dados.n3);
        auxiliar = auxiliar->prox;
    }
}