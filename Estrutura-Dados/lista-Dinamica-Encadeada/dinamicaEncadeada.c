#include <stdlib.h>
#include <stdio.h>
#include "dinamicaEncadeada.h"
//implementação das funções
//cria uma lista vazia

//cria uma lista vazia
Lista* criarLista(void){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}
//Liberar Lista
void liberarLista(Lista* li){
    if(li != NULL){//verifica se a lista é valida para ser liberada e se não está vazia
        struct elemento *no; //cria um ponteiro auxiliar para percorrer a lista
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->proximo;
            free(no);
        }
        free(li);     
    }
}
//calcular tamanho
int tamanhoLista(Lista *li){
    if(li == NULL) return 0;
    int count = 0;
    Lista no = *li; // o no é um auxiliar para não perder a referencia do inicio da lista
    while (*li != NULL)
    {
        count++;
        no = no->proximo;
    }
    return count;  
}
//Retornar o tamanho da lista(Usando recursividade)
int tamanhoListaRecursivo(Lista li){
    if(li == NULL) return 0;//Se lista estiver vazia ou se chegar no final da lista(NULL)
    return 1 + tamanhoListaRecursivo(li->proximo);//chama a função recursivamente até que a lista seja NULL
}
//Saber se lista está vazia
int listaVazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}
//Saber se lista está cheia
int listaCheia(Lista *li){
    return 0;
}
//insere no inicio
int inserirComecoLista(Lista *li, Aluno al){
    if(li == NULL) return 0;
    struct elemento *no = (struct elemento*)malloc(sizeof(struct elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->proximo = (*li);    *li = no;
    return 1;
}
int inserirFinalLista(Lista *li, Aluno al){
    if(li == NULL) return 0;
    struct elemento *no = (struct elemento*)malloc(sizeof(struct elemento));
    if(no == NULL) return 0;
    no->dados = al;
    no->proximo = NULL;
    if((*li) == NULL){//caso o primeiro elemento seja NULL, segnifica que a lista está vazia
        *li = no;
    }
    //caso não esteja
    else{
        struct elemento *aux = *li; //cria um auxiliar para percorrer a lista, pois eu não posso trabalhar com a cabeça real da lista
        while(aux->proximo != NULL){//enquanto o proximo elemento não for NULL
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
    return 1;
}
//inserção ordenada
int inserirListaOrdenada(Lista *li, Aluno al){
    if(li == NULL) return 0;
    struct elemento *no = (struct elemento*)malloc(sizeof(struct elemento));
    if(no == NULL) return 0;
    no->dados = al;
    //verificar se lista é vazia
    if(listaVazia(li)){
        no->proximo = (*li);
        *li = no; // Corrigido aqui
        return 1;
    }
    else{
        struct elemento *atual = *li, *anterior = NULL;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if(atual == *li){
            no->proximo = (*li);
            *li = no;
        }
        else{
            no->proximo = anterior->proximo;
            anterior->proximo = no;
        }
    }
    return 1;
}
//remoção no inicio da lista
int removerComecoLista(Lista *li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;
    struct elemento *no = *li;
    *li = no->proximo;
    free(no);
    return 1;
}
//remoção no final da lista
int remocaoFinalLista(Lista *li){
    if(listaVazia(li))return 0;
    struct elemento *anterior, *no = *li;
    while(no->proximo != NULL){ //até que proximo de no seja NULL
        anterior = no;
        no = no->proximo;
    }
    if(no == (*li)){ //caso seja o primeiro elemento que vá ser removido
        *li = no->proximo;
    }
    else{
        anterior->proximo = no->proximo; //anterior passa a apontar para NULL
    }
    free(no);
    return 1;
}
//remoção lista ordenadamente com base na matricula
int remocaoListaOrdenada(Lista *li, int mat){
    if(li == NULL) return 0;
    struct elemento *anterior, *no = *li;
    while (no->proximo != NULL && no->dados.matricula != mat)
    {
        anterior = no;
        no = no->proximo;
    }
    if(no == NULL) return 0; //caso a matricula não exista ou a lista esteja vazia
    if(no == *li){ //caso seja o primeiro elemento
        *li = no->proximo;
    }
    else{ //remove do meio ou do final
        anterior->proximo = no->proximo; //anterior passa a apontar para o proximo de no
    }
    free(no);
    return 1;
}
//consulta dados de um aluno com base na matricula
int consultaListaMatricula(Lista *li, int mat, Aluno *al){
    if(li == NULL) return 0;//verifica se a lista é valida
    struct elemento *no = *li;
    while (no != NULL && no->dados.matricula != mat)
    {
        no = no->proximo;
    }
    if(no == NULL) return 0; //a matricula não existe ou a lista está vazia
    *al = no->dados;
    return 1;
}
//consulta dados de um aluno com base na posição
int consultaListaPosicao(Lista *li,int pos, Aluno *al){ //considerando posição começando de 01
    if(li == NULL || pos <= 0) return 0;
    struct elemento *no = *li;
    int contador = 1;
    while(no != NULL && contador < pos){
        no = no->proximo;
        contador++;
    }
    if(no == NULL) return 0; //posição não existe ou a lista está vazia
    *al = no->dados;
    return 1;
}
//exibe a lista
void exibirLista(Lista li){
    if(li == NULL) printf("Lista Vazia\n");
    while (li->proximo != NULL)
    {
        printf("Matricula: %d\n", li->dados.matricula);
        printf("Nome: %s\n", li->dados.nome);
        li = li->proximo;
    }
}
//Anexação de listas encadeadas
int anexarListas(Lista *lista1, Lista *lista2){
    if(lista1 == NULL || lista2 == NULL) return 0;
    //verificar se as listas estão vazias
    if(listaVazia(lista1)) return 0;
    if(listaVazia(lista2)) return 0;
    struct elemento *no = *lista1;
    while (no->proximo != NULL)
    {
        no = no->proximo;
    }
    no->proximo = *lista2; //o proximo do ultimo elemento da lista1 passa a apontar para o primeiro elemento da lista2
    return 1;
}
