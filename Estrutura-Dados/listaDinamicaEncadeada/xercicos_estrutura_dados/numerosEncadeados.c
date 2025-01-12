#include <stdio.h>
#include <stdlib.h>
#include "numerosEncadeados.h"

// Função que cria um nó
No criarNo(int num,No lista) {
    No novoNo = (No)malloc(sizeof(No));
    novoNo->num = num;
    novoNo->prox = lista;
    return novoNo;
}
// Função que libera uma lista
void liberarLista(No *lista){
    No aux = *lista;
    while(*lista != NULL){
        aux = *lista;
        *lista = aux->prox;
        free(aux);
    }
}
// exibe a lista
void exibirLista(No lista) {
    No aux = lista;
    while (aux != NULL) {
        printf("%d\n", aux->num);
        aux = aux->prox;
    }
}
// exibe a lista de forma recursiva invertida
void exibirListaInvertida(No lista) {
    if (lista != NULL) {
        exibirListaInvertida(lista->prox);
        printf("%d\n", lista->num);
    }
}
// contar occorencias no numero
int contarOcorrencias(No lista, int num){
    if(lista == NULL) return 0;
    int count = 0;
    while (lista != NULL)
    {
        if(lista->num == num) count++;
        lista = lista->prox;
    }
    return count;
}
// devolve o ultimo elemento da lista
int ultimoElemento(No lista){
    if(lista == NULL) return -1;
    while(lista->prox != NULL){
        lista = lista->prox;
    }
    return lista->num;
}
// função que realiza a inversão da lista

//função que realiza a soma dos elementos da lista de forma recursiva
int somaElementos(No lista){
    if(lista == NULL) return 0;
    return lista->num + somaElementos(lista->prox);
}
//verifica se o elemnto está na lista
int verificarElemento(No lista, int num){
    if(lista == NULL) return 0;
    while(lista != NULL){
        if(lista->num == num) return 1;
        lista = lista->prox;
    }
    return 0;
}
//função que realiza a substituição dos itens da lista
int substituirElemento(No lista, int num, int novoNum){
    if(lista == NULL) return 0;
    if(!verificarElemento(lista,num)) return 0;//verifica se o elemnto estána lista
    while(lista != NULL){
        if(lista->num == num) lista->num = novoNum;
        lista = lista->prox;
    }
    return 1;
}
//retornar tamanho da lista
int tamanhoLista(No lista){
    if(lista == NULL) return 0;
    return 1 + tamanhoLista(lista->prox);
}
//verificar se duas listas são iguais
int verificarTamanho(No lista1, No lista2){
    if(lista1 == NULL || lista2 == NULL) return 0;//verifica se as suas listas são válidas
    if(tamanhoLista(lista1) != tamanhoLista(lista2)) return 0;//verifica se as duas tem o mesmo tamanho, e não retorna 0
    while(lista1 != NULL){
        if(lista1->num != lista2->num) return 0;
        lista1 = lista1->prox;
        lista2 = lista2->prox;
    }
    return 1;
}
//retorna o enesimo elemtento da lista recursivamente
int enesimoElemento(No lista, int n){
    if(lista == NULL) return 0;
    if(n == 1) return lista->num; //caso base que retorna o primeiro elemento, o n vai decrementando até chega rno valor do enesimo
    return enesimoElemento(lista->prox,n-1);//chama a função recursivamente até que n seja igual a 1
}
//enfilaremento de lista circular encadeada
No criarNoCircular(int num,No lista){
    No novoNo = (No)malloc(sizeof(No));
    novoNo->num = num;
    if(lista == NULL){ //verifica se a lista é vazia
        novoNo->prox = novoNo; //faz com que o proximo elemento aponte para ele mesmo
        return novoNo;
    }
    novoNo->prox = lista->prox; //faz com que o proximo elemento aponte para o proximo elemento da lista
    lista->prox = novoNo;//faz com que o proximo elemento da lista aponte para o novo elemento
    return novoNo;
}
//exibir lista circular
void exibirListaCircular(No lista){
    No aux = lista;
    if(lista != NULL){//verifica se a lista é válida
        do{
            printf("%d\n",aux->num);
            aux = aux->prox;
        }while(aux != lista); //enquanto o auxiliar for diferente da lista
    }
}
//desinfileira e desencircula a lista circular
void desenfileirarListaCircular(No lista){
    No auxiliar = lista;
    while(auxiliar->prox != lista){ //enquanto o proximo elemento do auxiliar for diferente da lista
        auxiliar = auxiliar->prox;
    }
    auxiliar->prox = NULL; //faz com que o proximo elemento do auxiliar aponte para NULL
}