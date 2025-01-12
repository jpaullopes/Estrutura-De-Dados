#include <stdio.h>
#include <stdlib.h>
#include "listaSequencial.h"

void exibirMenu() {
    printf("\nMenu:\n");
    printf("1. Criar lista\n");
    printf("2. Liberar lista\n");
    printf("3. Inserir aluno no final\n");
    printf("4. Inserir aluno no início\n");
    printf("5. Inserir aluno ordenadamente\n");
    printf("6. Remover aluno do final\n");
    printf("7. Remover aluno do início\n");
    printf("8. Remover aluno por matrícula\n");
    printf("9. Buscar aluno por matrícula\n");
    printf("10. Buscar aluno por posição\n");
    printf("11. Exibir tamanho da lista\n");
    printf("12. Verificar se a lista está cheia\n");
    printf("13. Verificar se a lista está vazia\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main(void) {
    Lista *li = NULL;
    int opcao, matricula, pos;
    Aluno al;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                li = criarLista();
                printf("Lista criada.\n");
                break;
            case 2:
                liberarLista(li);
                li = NULL;
                printf("Lista liberada.\n");
                break;
            case 3:
                printf("Digite a matrícula, nome e notas do aluno: ");
                scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.nota1, &al.nota2, &al.nota3);
                if (inserirFinalLista(li, al)) {
                    printf("Aluno inserido no final da lista.\n");
                } else {
                    printf("Falha ao inserir aluno.\n");
                }
                break;
            case 4:
                printf("Digite a matrícula, nome e notas do aluno: ");
                scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.nota1, &al.nota2, &al.nota3);
                if (inserirInicioLista(li, al)) {
                    printf("Aluno inserido no início da lista.\n");
                } else {
                    printf("Falha ao inserir aluno.\n");
                }
                break;
            case 5:
                printf("Digite a matrícula, nome e notas do aluno: ");
                scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.nota1, &al.nota2, &al.nota3);
                if (insercaoOrdenada(li, al)) {
                    printf("Aluno inserido ordenadamente na lista.\n");
                } else {
                    printf("Falha ao inserir aluno.\n");
                }
                break;
            case 6:
                if (removerFinalLista(li)) {
                    printf("Aluno removido do final da lista.\n");
                } else {
                    printf("Falha ao remover aluno.\n");
                }
                break;
            case 7:
                if (removerInicioLista(li)) {
                    printf("Aluno removido do início da lista.\n");
                } else {
                    printf("Falha ao remover aluno.\n");
                }
                break;
            case 8:
                printf("Digite a matrícula do aluno a ser removido: ");
                scanf("%d", &matricula);
                if (removerOrdenadamenteLista(li, matricula)) {
                    printf("Aluno removido da lista.\n");
                } else {
                    printf("Falha ao remover aluno.\n");
                }
                break;
            case 9:
                printf("Digite a matrícula do aluno a ser buscado: ");
                scanf("%d", &matricula);
                if (buscaSequencialLista(li, matricula, &al)) {
                    printf("Aluno encontrado: %d %s %f %f %f\n", al.matricula, al.nome, al.nota1, al.nota2, al.nota3);
                } else {
                    printf("Aluno não encontrado.\n");
                }
                break;
            case 10:
                printf("Digite a posição do aluno a ser buscado: ");
                scanf("%d", &pos);
                if (buscaPosicaoLista(li, pos, &al)) {
                    printf("Aluno encontrado: %d %s %f %f %f\n", al.matricula, al.nome, al.nota1, al.nota2, al.nota3);
                } else {
                    printf("Aluno não encontrado.\n");
                }
                break;
            case 11:
                printf("Tamanho da lista: %d\n", tamanhoLista(li));
                break;
            case 12:
                printf("Lista cheia: %d\n", listaCheia(li));
                break;
            case 13:
                printf("Lista vazia: %d\n", listaVazia(li));
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    if (li != NULL) {
        liberarLista(li);
    }

    return 0;
}