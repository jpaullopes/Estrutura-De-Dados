#include <stdio.h>
#include <stdlib.h>
#include "numerosEncadeados.h"

int main(void){
    No lista = criarNo(3,criarNo(1,criarNo(5,NULL)));
    //exibe a lista invertida
    exibirListaInvertida(lista);
    //contar occorencias no numero
    printf("O numero 3 aparece %d vezes na lista\n",contarOcorrencias(lista,3));
    //devolve o ultimo elemento da lista
    printf("O ultimo elemento da lista é: %d\n",ultimoElemento(lista));
    //função que realiza a soma dos elementos da lista de forma recursiva
    printf("A soma dos elementos da lista é: %d\n",somaElementos(lista));
    //verifica se o elento está na lista
    printf("O numero 5 está na lista? %d\n",verificarElemento(lista,5));
    //função que realiza a substituição dos itens da lista
    printf("Substituindo o numero 5 por 10\n");
    substituirElemento(lista,5,10);
    exibirLista(lista);
    //retornar tamanho da lista
    printf("O tamanho da lista é: %d\n",tamanhoLista(lista));
    //verificar se duas listas são iguais
    No lista2 = criarNo(3,criarNo(1,criarNo(5,NULL)));
    printf("As listas são iguais? %d\n",verificarTamanho(lista,lista2));
    //retorna o enesimo elemtento da lista
    printf("O 2º elemento da lista é: %d\n",enesimoElemento(lista,2));
    //enfilaremento de lista circular encadeada
    No listaCircular = criarNoCircular(3,criarNoCircular(1,criarNoCircular(5,NULL)));
    //exibir lista circular
    exibirListaCircular(listaCircular);
    liberarLista(&lista);
    liberarLista(&lista2);
    return 0;
}