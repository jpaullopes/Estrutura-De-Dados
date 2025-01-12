#include <stdio.h>
#include <stdlib.h>
#include "noDescritor.h"

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1. Criar lista\n");
    printf("2. Liberar lista\n");
    printf("3. Inserir aluno no início\n");
    printf("4. Inserir aluno no final\n");
    printf("5. Inserir aluno ordenadamente\n");
    printf("6. Remover aluno do início\n");
    printf("7. Remover aluno do final\n");
    printf("8. Remover aluno por matrícula\n");
    printf("9. Consultar aluno por posição\n");
    printf("10. Consultar aluno por matrícula\n");
    printf("11. Exibir tamanho da lista\n");
    printf("12. Verificar se a lista está cheia\n");
    printf("13. Verificar se a lista está vazia\n");
    printf("14. Exibir lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main(void) {
    NO_DESCRITOR *li = NULL;
    int opcao, matricula, pos;
    Aluno al;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        if (opcao == 1) {
            li = criaDescritor();
            if (li != NULL) {
                printf("Lista criada.\n");
            } else {
                printf("Erro ao criar lista.\n");
            }
        } else if (opcao == 2) {
            liberaDescritor(li);
            li = NULL;
            printf("Lista liberada.\n");
        } else if (opcao == 3) {
            printf("Digite a matrícula, nome e notas do aluno: ");
            scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
            if (insereInicio(li, al)) {
                printf("Aluno inserido no início da lista.\n");
            } else {
                printf("Erro ao inserir aluno.\n");
            }
        } else if (opcao == 4) {
            printf("Digite a matrícula, nome e notas do aluno: ");
            scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
            if (insereFinal(li, al)) {
                printf("Aluno inserido no final da lista.\n");
            } else {
                printf("Erro ao inserir aluno.\n");
            }
        } else if (opcao == 5) {
            printf("Digite a matrícula, nome e notas do aluno: ");
            scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
            if (insereOrdenado(li, al)) {
                printf("Aluno inserido de forma ordenada na lista.\n");
            } else {
                printf("Erro ao inserir aluno.\n");
            }
        } else if (opcao == 6) {
            if (removeInicio(li)) {
                printf("Aluno removido do início da lista.\n");
            } else {
                printf("Erro ao remover aluno.\n");
            }
        } else if (opcao == 7) {
            if (removeFinal(li)) {
                printf("Aluno removido do final da lista.\n");
            } else {
                printf("Erro ao remover aluno.\n");
            }
        } else if (opcao == 8) {
            printf("Digite a matrícula do aluno a ser removido: ");
            scanf("%d", &matricula);
            if (removeMatricula(li, matricula)) {
                printf("Aluno removido da lista.\n");
            } else {
                printf("Erro ao remover aluno.\n");
            }
        } else if (opcao == 9) {
            printf("Digite a posição do aluno: ");
            scanf("%d", &pos);
            if (consultaPosicao(li, pos, &al)) {
                printf("Aluno encontrado: Matrícula: %d, Nome: %s, Notas: %.2f, %.2f, %.2f\n", al.matricula, al.nome, al.n1, al.n2, al.n3);
            } else {
                printf("Aluno não encontrado.\n");
            }
        } else if (opcao == 10) {
            printf("Digite a matrícula do aluno: ");
            scanf("%d", &matricula);
            if (consultaMatricula(li, matricula, &al)) {
                printf("Aluno encontrado: Matrícula: %d, Nome: %s, Notas: %.2f, %.2f, %.2f\n", al.matricula, al.nome, al.n1, al.n2, al.n3);
            } else {
                printf("Aluno não encontrado.\n");
            }
        } else if (opcao == 11) {
            printf("Tamanho da lista: %d\n", tamanhoLista(li));
        } else if (opcao == 12) {
            if (listaCheia(li)) {
                printf("A lista está cheia.\n");
            } else {
                printf("A lista não está cheia.\n");
            }
        } else if (opcao == 13) {
            if (listaVazia(li)) {
                printf("A lista está vazia.\n");
            } else {
                printf("A lista não está vazia.\n");
            }
        } else if (opcao == 14) {
            imprimeLista(li);
        } else if (opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    if (li != NULL) {
        liberaDescritor(li);
    }

    return 0;
}