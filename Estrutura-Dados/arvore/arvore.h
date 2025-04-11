#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
    int Item;
    struct arv *Esq;
    struct arv *Dir;
} *Arv;

Arv criarArv(Arv direita, int item, Arv esquerda);
void emOrdem(Arv arv);
void preOrdem(Arv arv);
void posOrdem(Arv arv);
void destroirArv(Arv *arv);
void insert(Arv *arv, int item);
int busca(Arv arv, int item);
int removerMaximo(Arv *arv);
void remover(Arv *arv, int item);
int nos(Arv arv);
int folhas(Arv arv);
int altura(Arv arv);
int tem(Arv arv, int item);
int ehArvBinaria(Arv arv);
int ehIgual(Arv arv1, Arv arv2);
void exibeDecrescente(Arv arv);
int valor(Arv arv);

#endif