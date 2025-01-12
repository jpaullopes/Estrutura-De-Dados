#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

//Crianção da lista
Lista* criarLista(void){
    Lista *li = (Lista*) malloc(sizeof(Lista)); //ponteiro pra ponteiro
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
//Libera a lista
void liberarLista(Lista *li){
    if(li != NULL && *li != NULL){//siginifica que ela não está vazia
        Lista auxiliar, no = *li;
        while((*li) != no->prox){//enquanto o proximo elemento for diferente do primeiro
            auxiliar = no;
            no = no->prox;
            free(auxiliar);

        }
        free(no);
        free(li);
    }
}
//tamanho da lista
int tamanhoLista(Lista *li){
    if(li == NULL || (*li) == NULL) return 0; //se a lista for nula ou vazia
    int contador = 1;
    Lista no = *li; //criação deponteiro auxiliar
    while(no->prox != *li){//enquanto o proximo elemento for diferente do primeiro
        contador++;
        no = no->prox;
    }
    return contador;
}
//lista cheia
int listaCheia(Lista *li){
    return 0;
}
//lista vazia
int listaVazia(Lista *li){
    if(li == NULL || (*li) == NULL) return 1; //se a lista for nula ou vazia
    return 0;
}
//Inserção no inicio da lista
int insereInicio(Lista *li, Aluno al){
    if(li == NULL) return 0;
    Lista no = (ListaCircular*)malloc(sizeof(ListaCircular));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){//caso a lista esteja vazia
        *li = no;
        no->prox = no;
    }
    else{
        Lista auxiliar = *li;
        while(auxiliar->prox != *li){//enquanto o proximo elemento for diferente do primeiro
            auxiliar = auxiliar->prox;
        }
    auxiliar->prox = no;
    no->prox = *li;
    *li = no;
    }
    return 1;
}
//inserçã no final da lista
int insereFinal(Lista *li, Aluno al){
    if(li == NULL) return 0;
    Lista no = (ListaCircular*)malloc(sizeof(ListaCircular));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){ //caso a lista esteja vazia
        no->prox = no;
        *li = no;
    }
    else{
        Lista auxiliar = *li;
        while(auxiliar->prox != *li){//enquanto o proximo elemento for diferente do primeiro
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = no;
        no->prox = *li; //no passa a apontar para o começo da lista
    }
    return 1;
}
//inserção ordenada com base na matricula
int insereOrdenado(Lista *li, Aluno al){
    if(li == NULL) return 0;
    Lista no = (ListaCircular*)malloc(sizeof(ListaCircular));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){ //caso a lista esteja vazia
        no->prox = no;
        *li = no;
    }
    else{
        if((*li)->dados.matricula > al.matricula){//inserçã no inicio
            Lista auxiliar = *li;
            while(auxiliar->prox != *li){//enquanto o proximo elemento for diferente do primeiro
                auxiliar = auxiliar->prox;
            }
            no->prox = *li;
            auxiliar->prox = no;
            *li = no;
        }
        else{
            Lista anterior = *li, atual = (*li)->prox;
            while(atual != *li && atual->dados.matricula <al.matricula){
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = no;
            no->prox = atual;
        }
    }
    return 1;
}
//temoção no incio da lista
int removeInicio(Lista *li){
    if(listaVazia(li)) return 0;
    if((*li) == (*li)->prox){//caso tenha apenas um elemento
        free(*li);
        *li = NULL;
        return 1;
    }
    Lista auxiliar = *li, no = *li;
    while(auxiliar->prox != *li){//enquanto o proximo elemento for diferente do primeiro
        auxiliar = auxiliar->prox;
    }
    auxiliar->prox = no->prox; // fazer o ultimo apontar para o segundo 
    *li = no->prox; //fazer o primeiro apontar para o segundo
    free(no);
    return 1;
}
//remoção no final da lista
int removeFinal(Lista *li){
    if(listaVazia(li)) return 0;
    if((*li) == (*li)->prox){//caso tenha apenas um elemento
        free(*li);
        *li = NULL;
        return 1;
    }
    Lista auxilar, no = *li;
    while(no->prox != (*li)){//enquanto não chegar no ultimo
        auxilar = no;//auxiliar sempre atrás de no
        no = no->prox;
    }
    auxilar->prox = no->prox; //auxiliar aponta para o primeiro
    free(no);
    return 1;
}
//remoção de um elemento qualquer | baseado na matricula
int removeQualquer(Lista *li, int matricula){
    if(listaVazia(li)) return 0;
    Lista no = *li;
    if((*li)->dados.matricula == matricula){//remoção no inicio
        if((*li) == (*li)->prox){//caso tenha apenas um elemento
            free(*li);
            *li = NULL;
            return 1;
        }
        Lista auxiliar = *li;
        while(auxiliar->prox != *li){//enquanto o proximo elemento for diferente do primeiro
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = no->prox; // fazer o ultimo apontar para o segundo
        *li = no->prox; //fazer o primeiro apontar para o segundo
        free(no);
        return 1;
    }
    Lista anterior = no;
    no = no->prox;
    while(no != *li && no->dados.matricula != matricula){
        anterior = no;
        no = no->prox;
    }
    if(no == *li) return 0; //não encontrado
    anterior->prox = no->prox;
    free(no);
    return 1;
}
//conulta com base na posição
int consultaPosicao(Lista *li, int posicao, Aluno *al){
    if(listaVazia(li) || posicao <= 0) return 0;
    Lista no = *li;
    int contador = 1;
    while(no->prox != (*li) && contador < posicao){
        no = no->prox;
        contador++;
    }
    if(contador != posicao) return 0; //posição não encontrada
    *al = no->dados;
    return 1;
}
//consulta com base em critério(matricula)
int consultaMatricula(Lista *li, int matricula, Aluno *al){
    if(listaVazia(li)) return 0;
    Lista no = *li;
    while (no->prox != (*li) && no->dados.matricula != matricula){
        no = no->prox;
    }
    if(no->dados.matricula != matricula) return 0; //não encontrado
    *al = no->dados;
    return 1;
}