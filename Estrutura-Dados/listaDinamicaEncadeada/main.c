#include <stdio.h>
#include <stdlib.h>
#include "dinamicaEncadeada.h"

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
    printf("9. Consultar aluno por matrícula\n");
    printf("10. Consultar aluno por posição\n");
    printf("11. Exibir tamanho da lista\n");
    printf("12. Verificar se a lista está cheia\n");
    printf("13. Verificar se a lista está vazia\n");
    printf("14. Exibir lista\n");
    printf("15. Anexar duas listas\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}

int main(void) {
    Lista *li = NULL;
    Lista *li2 = NULL;
    int opcao, matricula, pos;
    Aluno al;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                li = criarLista();
                if (li != NULL) {
                    printf("Lista criada.\n");
                } else {
                    printf("Erro ao criar lista.\n");
                }
                break;
            case 2:
                if (li != NULL) {
                    liberarLista(li);
                    li = NULL;
                    printf("Lista liberada.\n");
                } else {
                    printf("A lista não foi criada.\n");
                }
                break;
            case 3:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    printf("Digite a matrícula, nome e notas do aluno: ");
                    scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
                    if (inserirComecoLista(li, al)) {
                        printf("Aluno inserido no início da lista.\n");
                    } else {
                        printf("Erro ao inserir aluno.\n");
                    }
                }
                break;
            case 4:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    printf("Digite a matrícula, nome e notas do aluno: ");
                    scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
                    if (inserirFinalLista(li, al)) {
                        printf("Aluno inserido no final da lista.\n");
                    } else {
                        printf("Erro ao inserir aluno.\n");
                    }
                }
                break;
            case 5:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    printf("Digite a matrícula, nome e notas do aluno: ");
                    scanf("%d %s %f %f %f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
                    if (inserirListaOrdenada(li, al)) {
                        printf("Aluno inserido de forma ordenada na lista.\n");
                    } else {
                        printf("Erro ao inserir aluno.\n");
                    }
                }
                break;
            case 6:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    if (removerComecoLista(li)) {
                        printf("Aluno removido do início da lista.\n");
                    } else {
                        printf("Erro ao remover aluno.\n");
                    }
                }
                break;
            case 7:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    if (remocaoFinalLista(li)) {
                        printf("Aluno removido do final da lista.\n");
                    } else {
                        printf("Erro ao remover aluno.\n");
                    }
                }
                break;
            case 8:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    printf("Digite a matrícula do aluno a ser removido: ");
                    scanf("%d", &matricula);
                    if (remocaoListaOrdenada(li, matricula)) {
                        printf("Aluno removido da lista.\n");
                    } else {
                        printf("Erro ao remover aluno.\n");
                    }
                }
                break;
            case 9:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    printf("Digite a matrícula do aluno: ");
                    scanf("%d", &matricula);
                    if (consultaListaMatricula(li, matricula, &al)) {
                        printf("Aluno encontrado: %s, Notas: %.2f, %.2f, %.2f\n", al.nome, al.n1, al.n2, al.n3);
                    } else {
                        printf("Aluno não encontrado.\n");
                    }
                }
                break;
            case 10:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    printf("Digite a posição do aluno: ");
                    scanf("%d", &pos);
                    if (consultaListaPosicao(li, pos, &al)) {
                        printf("Aluno encontrado: %s, Notas: %.2f, %.2f, %.2f\n", al.nome, al.n1, al.n2, al.n3);
                    } else {
                        printf("Aluno não encontrado.\n");
                    }
                }
                break;
            case 11:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    printf("Tamanho da lista: %d\n", tamanhoLista(li));
                }
                break;
            case 12:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    if (listaCheia(li)) {
                        printf("A lista está cheia.\n");
                    } else {
                        printf("A lista não está cheia.\n");
                    }
                }
                break;
            case 13:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    if (listaVazia(li)) {
                        printf("A lista está vazia.\n");
                    } else {
                        printf("A lista não está vazia.\n");
                    }
                }
                break;
            case 14:
                if (li == NULL) {
                    printf("Crie a lista primeiro.\n");
                } else {
                    exibirLista(*li);
                }
                break;
            case 15:
                if (li == NULL || li2 == NULL) {
                    printf("Crie as duas listas primeiro.\n");
                } else {
                    if (anexarListas(li, li2)) {
                        printf("Listas anexadas com sucesso.\n");
                    } else {
                        printf("Erro ao anexar listas.\n");
                    }
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while(opcao != 0);

    if (li != NULL) {
        liberarLista(li);
    }

    return 0;
}