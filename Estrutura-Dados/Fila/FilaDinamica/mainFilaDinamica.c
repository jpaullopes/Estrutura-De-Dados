#include <stdio.h>  
#include <stdlib.h>
#include "filaDinamica.h"

void exibirMenu(void) {
    printf("[ 1 ] Criar fila\n");
    printf("[ 2 ] Liberar fila\n");
    printf("[ 3 ] Tamanho da fila\n");
    printf("[ 4 ] Inserir elemento na fila\n");
    printf("[ 5 ] Remover elemento da fila\n");
    printf("[ 6 ] Consultar início da fila\n");
    printf("[ 7 ] Imprimir fila\n");
    printf("[ 8 ] Verificar se a fila está vazia\n");
    printf("[ 9 ] Verificar se a fila está cheia\n");
    printf("[ 0 ] Sair\n");
}

int main(void) {
    Fila *fi = NULL; // criação da fila
    Aluno al; // criação de um aluno
    int opcao, retorno;

    do {
        exibirMenu();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            fi = criaFila();
            if (fi != NULL) {
                printf("Fila criada com sucesso!\n");
            } else {
                printf("Erro ao criar fila!\n");
            }
        } else if (opcao == 2) {
            liberaFila(fi);
            fi = NULL;
            printf("Fila liberada com sucesso!\n");
        } else if (opcao == 3) {
            retorno = tamanhoFila(fi);
            if (retorno == -1) {
                printf("Erro ao verificar tamanho da fila!\n");
            } else {
                printf("Tamanho da fila: %d\n", retorno);
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
            retorno = insereFila(fi, al);
            if (retorno == 1) {
                printf("Aluno inserido com sucesso!\n");
            } else {
                printf("Erro ao inserir aluno!\n");
            }
        } else if (opcao == 5) {
            retorno = removeFila(fi);
            if (retorno == 1) {
                printf("Aluno removido com sucesso!\n");
            } else {
                printf("Erro ao remover aluno!\n");
            }
        } else if (opcao == 6) {
            retorno = consultaFila(fi, &al);
            if (retorno == 1) {
                printf("Matrícula: [ %d ]\n", al.matricula);
                printf("Nome: [ %s ]\n", al.nome);
                printf("Notas: %.2f | %.2f | %.2f\n", al.n1, al.n2, al.n3);
            } else {
                printf("Erro ao consultar início da fila!\n");
            }
        } else if (opcao == 7) {
            imprimeFila(fi);
        } else if (opcao == 8) {
            if (filaVazia(fi)) {
                printf("A fila está vazia.\n");
            } else {
                printf("A fila não está vazia.\n");
            }
        } else if (opcao == 9) {
            if (filaCheia(fi)) {
                printf("A fila está cheia.\n");
            } else {
                printf("A fila não está cheia.\n");
            }
        } else if (opcao == 0) {
            liberaFila(fi);
            printf("Programa encerrado!\n");
        } else {
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    if (fi != NULL) {
        liberaFila(fi);
    }

    return 0;
}