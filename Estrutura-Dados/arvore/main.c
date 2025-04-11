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
    
    // Demonstrando a função valor() com uma árvore de expressão aritmética
    printf("\n--- Demonstração de Árvore de Expressão Aritmética ---\n");
    
    // Criando uma árvore para a expressão ((5 + 3) / 4) * (6 - 1)
    Arv op_mult = NULL;            // Operador *
    Arv op_div = NULL;             // Operador /
    Arv op_soma = NULL;            // Operador +
    Arv op_sub = NULL;             // Operador -
    
    // Criando as folhas com valores
    Arv num5 = criarArv(NULL, 5, NULL);
    Arv num3 = criarArv(NULL, 3, NULL);
    Arv num4 = criarArv(NULL, 4, NULL);
    Arv num6 = criarArv(NULL, 6, NULL);
    Arv num1 = criarArv(NULL, 1, NULL);
    
    // Montando a subárvore (5 + 3)
    op_soma = criarArv(NULL, '+', NULL);
    op_soma->Esq = num5;
    op_soma->Dir = num3;
    
    // Montando a subárvore (6 - 1)
    op_sub = criarArv(NULL, '-', NULL);
    op_sub->Esq = num6;
    op_sub->Dir = num1;
    
    // Montando a subárvore ((5 + 3) / 4)
    op_div = criarArv(NULL, '/', NULL);
    op_div->Esq = op_soma;
    op_div->Dir = num4;
    
    // Montando a árvore completa ((5 + 3) / 4) * (6 - 1)
    op_mult = criarArv(NULL, '*', NULL);
    op_mult->Esq = op_div;
    op_mult->Dir = op_sub;
    
    // Avaliando a expressão
    printf("Expressão: ((5 + 3) / 4) * (6 - 1)\n");
    printf("Resultado: %d\n", valor(op_mult));
    
    // Liberando memória
    printf("\nDestruindo todas as árvores...\n");
    destroirArv(&arvore);
    destroirArv(&arvore2);
    destroirArv(&op_mult); // Isso vai liberar toda a árvore de expressão
    printf("Árvores destruídas com sucesso!\n");
    
    
    return 0;
}