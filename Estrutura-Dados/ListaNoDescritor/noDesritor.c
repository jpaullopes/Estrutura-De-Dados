#include <stdio.h>
#include <stdlib.h>
#include "noDescritor.h"

//criação do nó descritor
NO_DESCRITOR *criaDescritor(){
    NO_DESCRITOR *li = (NO_DESCRITOR *)malloc(sizeof(NO_DESCRITOR));
    if(li != NULL){
        li->inicio = NULL;
        li->fim = NULL;
        li->qtd = 0;
    }
    return li;
}
//liberar nó descritor
void liberaDescritor(NO_DESCRITOR *li){
    if(li != NULL){
        NO *no;//criando um no auxiliar para percorrer a lista
        while(li->inicio != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}
//lista cheia
int listaCheia(NO_DESCRITOR *li){
    return 0;
}
//lista vazia
int listaVazia(NO_DESCRITOR *li){
    if(li == NULL || li->inicio == NULL) return 1; //se a lista for nula ou vazia
    return 0;
}
//tamanho da lista
int tamanhoLista(NO_DESCRITOR *li){
    if(li == NULL){
        return 0;
    }
    return li->qtd;
}
//insere no início
int insereInicio(NO_DESCRITOR *li, Aluno al){
    if(li = NULL) return 0;
    NO *no = (NO *)malloc(sizeof(NO));
    if(no == NULL) return 0; //alocação falha
    no->dados = al;
    no->prox = li->inicio;//no proximo aponta para o inicio da lista
    if(li->inicio == NULL){//caso lista vazia
        li->fim = no;
    }
    li->inicio = no;
    li->qtd++;//incremento de quantidade
    return 1;
}
//insero no final
int insereFinal(NO_DESCRITOR *li, Aluno al){
    if(li == NULL) return 0;
    NO *no = (NO*)malloc(sizeof(NO));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL; //o proximo do no é NULL
    if(li->inicio == NULL){//caso lista vazia
        li->inicio = no;
    }
    else{
        li->fim->prox = no;
    }
    li->fim = no;
    li->qtd++;
    return 1;
}
//insere ordenado
int insereOrdenado(NO_DESCRITOR *li, Aluno al){
    if(li == NULL) return 0;
    NO *no = (NO *)malloc(sizeof(NO));
    if(no == NULL) return 0;
    no->dados = al;
    if(listaVazia(li)){//se a lista for vazia
        no->prox = NULL;
        li->inicio = no;
        li->fim = no;
        li->qtd++;
        return 1;
    }
    else{
        NO *anterior, *atual = li->inicio;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == li->inicio){//se for o primeiro
            no->prox = li->inicio;
            li->inicio = no;
        }
        else{
            no->prox = anterior->prox;
            anterior->prox = no;
        }
        if(atual == NULL){//se for o ultimo
            li->fim = no;
        }
        li->qtd++;
        return 1;
    }
}
//remove do início
int removeInicio(NO_DESCRITOR *li){
    if(li == NULL)return 0;
    if(li->inicio == NULL) return 0;//lista vazia
    NO *no = li->inicio;//no auxiliar que recebe o 1° elemento
    li->inicio = no->prox;//inicio aponta para o proximo
    fre(no);
    if(li->inicio == NULL){//só tinha um elemento na lista
        li->fim = NULL;
    }
    li->qtd--;
    return 1;
}
//remoção do final
int removeFinal(NO_DESCRITOR *li){
    if(li == NULL) return 0;
    if(li->inicio == NULL) return 0;//lista vazia
    NO *anterior, *no = li->inicio;
    while(no->prox != NULL){//enquanto não chegar no ultimo elemento
        anterior = no;
        no = no->prox;
    }
    if(no == li->inicio){//se for o primeiro
        li->inicio = NULL;
        li->fim = NULL;
    }
    else{
        anterior->prox = no->prox;//mesma coisa de anterior->prox = NULL
        li->fim = anterior;
    }
    free(no);
    li->qtd--;
    return 1;
}
//remoção com base na matricula
int removeMatricula(NO_DESCRITOR *li, int mat){
    if(li == NULL) return 0;
    NO *anterior, *no = li->inicio;
    while(no != NULL && no->dados.matricula != mat){
        anterior = no;
        no = no->prox;
    }
    if(no == NULL) return 0;//não encontrado
    if(no == li->inicio){//se for o primeiro
        li->inicio = no->prox;
    }
    else{
        anterior->prox = no->prox;
    }
    if(no == li->fim){//se for o ultimo
        li->fim = anterior;
    }
    free(no);
    li->qtd--;
    return 1;
}
//consulta por matricula
int consultaMatricula(NO_DESCRITOR *li, int mat, Aluno *al){
    if(li == NULL) return 0;
    NO *no = li->inicio;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL) return 0;
    *al = no->dados;
    return 1;
}
//consulta por posição
int consultaPosicao(NO_DESCRITOR *li, int pos, Aluno *al){
    if(li == NULL || pos <= 0) return 0;
    NO *no = li->inicio;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL) return 0;
    *al = no->dados;
    return 1;
}
//imprimir lista
void imprimeLista(NO_DESCRITOR *li){
    if(li == NULL) return;
    NO *no = li->inicio;
    while(no != NULL){
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: [%.2f] [%.2f] [%.2f]\n", no->dados.n1, no->dados.n2, no->dados.n3);
        no = no->prox;
    }
}