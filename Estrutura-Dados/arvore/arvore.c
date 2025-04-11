#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Criando uma arvore binaria
Arv criarArv(Arv direita, int item, Arv esquerda){
    // Não tem como tirar o sizeof de um ponteiro né kkk
    Arv novaArv = (Arv)malloc(sizeof(struct arv)); 
    if(novaArv == NULL){ // Caso não tenha memoria suficiente
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    // Atribuindo os valores para a nova arvore
    novaArv->Item = item;
    novaArv->Esq = esquerda;
    novaArv->Dir = direita;

    return novaArv;
}

void emOrdem(Arv arv){
    if(arv == NULL) return; // Se a arvore for nula, não faz nada
    emOrdem(arv->Esq);
    printf("%d",arv->Item);
    emOrdem(arv->Dir);
}


void preOrdem(Arv arv){
    if(arv == NULL) return; // Se a arvore for nula, não faz nada
    printf("%d",arv->Item);
    emOrdem(arv->Esq);
    emOrdem(arv->Dir);
}


void posOrdem(Arv arv){
    if(arv == NULL) return; // Se a arvore for nula, não faz nada
    emOrdem(arv->Esq);
    emOrdem(arv->Dir);
    printf("%d",arv->Item);
}

void destroirArv(Arv *arv){
    if(*arv == NULL) return; // Se a arvore for nula, não faz nada
    destroirArv(&(*arv)->Esq);
    destroirArv(&(*arv)->Dir);
    free(*arv); // Libera a memoria da arvore
    *arv = NULL; // Atribui NULL para o ponteiro da arvore
}

void insert(Arv *arv, int item){
    if(*arv == NULL){ // Se a arvore for nula, cria uma nova arvore
        *arv = criarArv(NULL, item, NULL);
        return;
    }
    if(item < (*arv)->Item){ // Se o item for menor que o item da arvore, insere na esquerda
        insert(&(*arv)->Esq, item);
    }else{ // Se o item for maior que o item da arvore, insere na direita
        insert(&(*arv)->Dir, item);
    }
}

int busca(Arv arv, int item){
    if(arv == NULL) return 0; // Se a arvore for nula, retorna 0
    if(arv->Item == item) return 1; // Se o item for encontrado, retorna 1
    if(item < arv->Item) return busca(arv->Esq, item); // Se o item for menor que o item da arvore, busca na esquerda
    return busca(arv->Dir, item); // Se o item for maior que o item da arvore, busca na direita
}

int removerMaximo(Arv *arv){
    if(*arv == NULL) abort(); // Se a arvore for nula, aborta o programa
    while((*arv)->Dir != NULL){ // Enquanto a arvore da direita não for nula, vai para a direita
        arv = &(*arv)->Dir;
    }
    Arv temp = *arv; // Cria uma arvore temporaria para armazenar o valor da arvore
    int item = (*arv)->Item; // Armazena o valor do item da arvore
    *arv = (*arv)->Esq; // Atribui a arvore da esquerda para a arvore atual
    free(temp); // Libera a memoria da arvore temporaria
    return item; // Retorna o valor do item
}

void remover(Arv *arv, int item){
    if(*arv == NULL) return; // Se a arvore for nula, não faz nada
    if(item == (*arv)->Item){ 
        Arv novaArv = *arv;
        if( novaArv->Esq == NULL) { // Se a arvore da esquerda for nula, atribui a arvore da direita para a arvore atual
            *arv = novaArv->Dir;
        }else if(novaArv->Dir == NULL){ // Se a arvore da direita for nula, atribui a arvore da esquerda para a arvore atual
            *arv = novaArv->Esq;
        }else{ // Se as duas arvores não forem nulas, atribui a arvore da direita para a arvore atual
            novaArv->Item = removerMaximo(&novaArv->Esq); // Remove o maximo da arvore da esquerda e atribui o valor para a arvore atual
        }
        if(novaArv != NULL) free(novaArv); // Libera a memoria da arvore temporaria
    }else if(item <= (*arv)->Item){ // Se o item for menor que o item da arvore, remove na esquerda
        remover(&(*arv)->Esq, item);
    }else{ // Se o item for maior que o item da arvore, remove na direita
        remover(&(*arv)->Dir, item);
    }
}

int nos(Arv arv){
    if(arv == NULL) return 0; // Se a arvore for nula, retorna 0
    return 1 + nos(arv->Esq) + nos(arv->Dir); // Retorna o numero de nos da arvore
}

int folhas(Arv arv){
    if(arv == NULL) return 0; // Se a arvore for nula, retorna 0
    if(arv->Esq == NULL && arv->Dir == NULL) return 1; // Se a arvore da esquerda e da direita forem nulas, retorna 1
    return folhas(arv->Esq) + folhas(arv->Dir); // Retorna o numero de folhas da arvore
}

int altura(Arv arv){
    if(arv == NULL) return -1; // Se a arvore for nula, retorna -1
    int alturaEsq = altura(arv->Esq); // Armazena a altura da arvore da esquerda
    int alturaDir = altura(arv->Dir); // Armazena a altura da arvore da direita
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1; // Retorna a maior altura entre as duas arvores
}

int tem(Arv arv, int item){
    if(arv == NULL) return 0; // Se a arvore for nula, retorna 0
    if(arv->Item == item) return 1; // Se o item for encontrado, retorna 1
    if(item < arv->Item) return tem(arv->Esq, item); // Se o item for menor que o item da arvore, busca na esquerda
    return tem(arv->Dir, item); // Se o item for maior que o item da arvore, busca na direita
}

int ehArvBinaria(Arv arv){
    if(arv == NULL) return 1; // Se a arvore for nula, retorna 1
    if(arv->Esq != NULL && arv->Esq->Item > arv->Item) return 0; // Se a arvore da esquerda for maior que o item da arvore, retorna 0
    if(arv->Dir != NULL && arv->Dir->Item < arv->Item) return 0; // Se a arvore da direita for menor que o item da arvore, retorna 0
    return ehArvBinaria(arv->Esq) && ehArvBinaria(arv->Dir); // Retorna se as duas arvores são binarias
}

int ehIgual(Arv arv1, Arv arv2){
    if(arv1 == NULL && arv2 == NULL) return 1; // Se as duas arvores forem nulas, retorna 1
    if(arv1 == NULL || arv2 == NULL) return 0; // Se uma das arvores for nula, retorna 0
    if(arv1->Item != arv2->Item) return 0; // Se os itens das arvores forem diferentes, retorna 0
    return ehIgual(arv1->Esq, arv2->Esq) && ehIgual(arv1->Dir, arv2->Dir); // Retorna se as duas arvores são iguais
}

void exibeDecrescente(Arv arv){
    if(arv == NULL) return; // Se a arvore for nula, não faz nada
    exibeDecrescente(arv->Dir); // Exibe a arvore da direita
    printf("%d ",arv->Item); // Exibe o item da arvore
    exibeDecrescente(arv->Esq); // Exibe a arvore da esquerda
}