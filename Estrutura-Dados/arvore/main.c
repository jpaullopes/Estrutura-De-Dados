#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    // Criando uma árvore binária de busca
    Arv arvore = NULL;
    
    // Inserindo elementos
    insert(&arvore, 50);
    insert(&arvore, 30);
    insert(&arvore, 70);
    insert(&arvore, 20);
    insert(&arvore, 40);
    insert(&arvore, 60);
    insert(&arvore, 80);
    
    // Exibindo informações sobre a árvore
    printf("Árvore Binária de Busca criada com sucesso!\n\n");
    
    printf("Percurso em ordem: ");
    emOrdem(arvore);
    printf("\n");
    
    printf("Percurso pré-ordem: ");
    preOrdem(arvore);
    printf("\n");
    
    printf("Percurso pós-ordem: ");
    posOrdem(arvore);
    printf("\n\n");
    
    // Teste de funções
    printf("Número de nós: %d\n", nos(arvore));
    printf("Número de folhas: %d\n", folhas(arvore));
    printf("Altura da árvore: %d\n", altura(arvore));
    
    // Busca de elementos
    int buscar = 40;
    if(tem(arvore, buscar)) {
        printf("O elemento %d está presente na árvore.\n", buscar);
    } else {
        printf("O elemento %d não está presente na árvore.\n", buscar);
    }
    
    // Verificação de árvore binária de busca
    if(ehArvBinaria(arvore)) {
        printf("É uma árvore binária de busca válida.\n");
    } else {
        printf("Não é uma árvore binária de busca válida.\n");
    }
    
    // Exibição decrescente
    printf("\nExibição em ordem decrescente: ");
    exibeDecrescente(arvore);
    printf("\n");
    
    // Removendo um elemento
    printf("\nRemovendo o elemento 30...\n");
    remover(&arvore, 30);
    printf("Árvore após remoção (em ordem): ");
    emOrdem(arvore);
    printf("\n");
    
    // Criando uma segunda árvore idêntica para teste
    Arv arvore2 = NULL;
    insert(&arvore2, 50);
    insert(&arvore2, 70);
    insert(&arvore2, 20);
    insert(&arvore2, 40);
    insert(&arvore2, 60);
    insert(&arvore2, 80);
    
    // Verificando se as árvores são iguais
    if(ehIgual(arvore, arvore2)) {
        printf("As árvores são iguais.\n");
    } else {
        printf("As árvores são diferentes.\n");
    }
    
    // Liberando memória
    printf("\nDestruindo as árvores...\n");
    destroirArv(&arvore);
    destroirArv(&arvore2);
    printf("Árvores destruídas com sucesso!\n");
    
    return 0;
}