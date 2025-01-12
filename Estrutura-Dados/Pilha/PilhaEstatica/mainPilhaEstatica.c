#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"

void exibirMenu(void) {
    printf("[ 1 ] Criar pilha\n");
    printf("[ 2 ] Liberar pilha\n");
    printf("[ 3 ] Tamanho da pilha\n");
    printf("[ 4 ] Inserir elemento na pilha\n");
    printf("[ 5 ] Remover elemento da pilha\n");
    printf("[ 6 ] Consultar topo da pilha\n");
    printf("[ 7 ] Imprimir pilha\n");
    printf("[ 8 ] Verificar se a pilha está vazia\n");
    printf("[ 9 ] Verificar se a pilha está cheia\n");
    printf("[ 0 ] Sair\n");
}

int main(void) {
    Pilha *pi = NULL; // criação da pilha
    Aluno al; // criação de um aluno
    int opcao, retorno;

    do {
        exibirMenu();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            pi = criarPilha();
            if (pi != NULL) {
                printf("Pilha criada com sucesso!\n");
            } else {
                printf("Erro ao criar pilha!\n");
            }
        } else if (opcao == 2) {
            liberarPilha(pi);
            pi = NULL;
            printf("Pilha liberada com sucesso!\n");
        } else if (opcao == 3) {
            retorno = tamanhoPilha(pi);
            if (retorno == -1) {
                printf("Erro ao verificar tamanho da pilha!\n");
            } else {
                printf("Tamanho da pilha: %d\n", retorno);
            }
        } else if (opcao == 4) {
            printf("Digite a matrícula do aluno: ");
            scanf("%d", &al.matricula);
            printf("Digite o nome do aluno: ");
            scanf("%s", al.nome);
            printf("Digite a primeira nota do aluno: ");
            scanf("%f", &al.n1);
            printf("Digite a segunda nota do aluno: ");
            scanf("%f", &al.n2);
            printf("Digite a terceira nota do aluno: ");
            scanf("%f", &al.n3);
            retorno = inserirPilha(pi, al);
            if (retorno == 1) {
                printf("Aluno inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir aluno!\n");
            }
        } else if (opcao == 5) {
            retorno = removerPilha(pi);
            if (retorno == 1) {
                printf("Aluno removido com sucesso!\n");
            } else {
                printf("Erro ao remover aluno!\n");
            }
        } else if (opcao == 6) {
            retorno = consultarTopoPilha(pi, &al);
            if (retorno == 1) {
                printf("Matrícula: [ %d ]\n", al.matricula);
                printf("Nome: [ %s ]\n", al.nome);
                printf("Notas: %.2f | %.2f | %.2f\n", al.n1, al.n2, al.n3);
            } else {
                printf("Erro ao consultar topo da pilha!\n");
            }
        } else if (opcao == 7) {
            imprimirPilha(pi);
        } else if (opcao == 8) {
            if (pilhaVazia(pi)) {
                printf("A pilha está vazia.\n");
            } else {
                printf("A pilha não está vazia.\n");
            }
        } else if (opcao == 9) {
            if (pilhaCheia(pi)) {
                printf("A pilha está cheia.\n");
            } else {
                printf("A pilha não está cheia.\n");
            }
        } else if (opcao == 0) {
            liberarPilha(pi);
            printf("Programa encerrado!\n");
        } else {
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    if (pi != NULL) {
        liberarPilha(pi);
    }

    return 0;
}