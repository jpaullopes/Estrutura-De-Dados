#include <stdio.h>
#include <stdlib.h>
#include "duplamenteEncadeada.h"

//cria a lista
Lista* criarLista(void){
    Lista *li = (Lista*)malloc(sizeof(Lista)); //ponteiro para ponteiro o li é mais como **li
    if(li != NULL){
        *li = NULL; //fazendo o conteudo de lista receber nulo
    }
    return li;
}
//liberar lista
void liberarLista(Lista* li){
    if(li != NULL){
        Elem* no;//cria um ponteiro para elemento
        while((*li) != NULL){
            no = *li;//no recebe o endereço de li
            *li = (*li)->prox;//li recebe o proximo elemento
            free(no);//libera o espaço de memoria
        }
        free(li);//libera o ponteiro
    }
}
//tamanho da lista
int tamanhoLista(Lista* li){
    if(li == NULL) return 0;
    int cont = 0;
    Elem *no = *li;//cria um ponteiro para elemento e recebe o endereço de li
    while(no != NULL){
        cont++;//incrementa o contador
        no = no->prox;//no recebe o proximo elemento
    }
    return cont;
}
//lista cheia?
int listaCheia(Lista* li){
    return 0;
}
//lista vazia?
int listaVazia(Lista* li){
    if(li == NULL) return 1; //verificando se o ponteiro é nulo
    if(*li == NULL) return 1; //verificando se o conteudo do ponteiro é nulo
    return 0;
}
//inserção no inicio da lista
int insercaoInicio(Lista* li, Aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li); //no->prox aponta para o primeiro elemento da lista
    no->ant = NULL; 
    if((*li) != NULL){//se a lista não for vazia
        (*li)->ant = no;//o elemento anterior ao primeiro elemento aponta para no
    }
    *li = no;
}
//inserção no final da lista
int insercaoFinal(Lista* li, Aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    no->ant = NULL;
    if((*li) == NULL){//caso lista vazia
        *li = no;
    }
    else{ //caso lista não vazia
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no; //o ultimo elemento aponta para no
        no->ant = aux; //no(anterior) aponta para o penultimo elemento
    }
    return 1;
}
//inserção de forma ordenada com base na matricula
int insercaoOrdenada(Lista* li, Aluno al){
    if(li == NULL) return 0;
    Lista no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if(listaVazia(li)){//se lista estiver vazia insere no inicio
            no->prox = NULL; 
            no->ant = NULL; 
            *li = no;
            return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere no inicio caso a matricula seja menor que a do primeiro elemento
            no->prox = (*li); 
            no->ant = NULL; 
            (*li)->ant = no;
            *li = no;
        }
        else{
            no->prox = ant->prox;//no->prox aponta para o proximo elemento(atual)
            no->ant = ant;
            ant->prox = no;
            if(atual != NULL){//se atual não for nulo
                atual->ant = no;
            }
        }
    return 1;
    }
}
//remover inicio da lista
int removerInicio(Lista* li){
    if(listaVazia(li)) return 0;
    Elem *no = *li; //criação do auxiliar
    *li = no->prox;
    if(no->prox != NULL){
        no->prox->ant = NULL;
    }
    free(no);
    return 1;
}
//remover final da lista
int removerFinal(Lista* li){
    if(listaVazia(li)) return 0;
    Elem *no = *li;
    while(no->prox != NULL){
        no = no->prox;
    }
    if(no->ant == NULL){ //se for o primeiro elemento e unico
        *li = no->prox;
    }
    else{
        no->ant->prox = NULL;
    }
    free(no);
    return 1;
}
//remoção de um elemento específico com base na matricula
int removerElemento(Lista* li, int mat){
    if(li == NULL) return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL) return 0; //não encontrado
    if(no->ant == NULL){//se for o primeiro elemento
        *li = no->prox;
    }
    else{//se não for o primeiro elemento | altera o proximo do anterior para o proximo do no
        no->ant->prox = no->prox;
    }
    if(no->prox != NULL){//se não for o ultimo elemento | altera o anterior do proximo para o anterior do no
        no->prox->ant = no->ant;
    }
    free(no);
    return 1;
}
//consulta por base de posição
int consultaPosicao(Lista* li, int pos, Aluno *al){
    if(li == NULL || pos <= 0) return 0; //verifica se posição e listas validas
    Elem *no = *li;
    int i = 1;//comeaça a contar do 1
    while(no != NULL && i < pos){//enquanto no não for nulo e i for menor que pos
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0; //não encontrado
    }     
    *al = no->dados;
    return 1;
}
//consulta por base de matricula
int consultaMatricula(Lista* li, int mat, Aluno *al){
    if(li == NULL) return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){ //enquanto no não for nulo e a matricula for diferente
        no = no->prox;
    }
    if(no == NULL){
        return 0; //não encontrado
    }     
    *al = no->dados;
    return 1;
}