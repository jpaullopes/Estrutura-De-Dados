#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

void exibirMenu(void){
    printf("[ 1 ] Criar fila\n");
    printf("[ 2 ] Liberar fila\n");
    printf("[ 3 ] Tamanho da fila\n");
    printf("[ 4 ] Verificar se a fila está cheia\n");
    printf("[ 5 ] Verificar se a fila está vazia\n");
    printf("[ 6 ] Inserir elemento na fila\n");
    printf("[ 7 ] Remover elemento da fila\n");
    printf("[ 8 ] Consultar início da fila\n");
    printf("[ 9 ] Imprimir fila\n");
    printf("[ 0 ] Sair\n");
}

int main(void){
    Fila *fi; //criação da fila
    Aluno al; //criação de um aluno
    int opcao, retorno;
    do{
        exibirMenu();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                fi = criarFila();
                if(fi != NULL){
                    printf("Fila criada com sucesso!\n");
                }else{
                    printf("Erro ao criar fila!\n");
                }
                break;
            case 2:
                liberarFila(fi);
                printf("Fila liberada com sucesso!\n");
                break;
            case 3:
                retorno = tamanho_fila(fi);
                if(retorno == -1){
                    printf("Erro ao verificar tamanho da fila!\n");
                }else{
                    printf("Tamanho da fila: %d\n", retorno);
                }
                break;
            case 4:
                retorno = verificarFilaCheia(fi);
                if(retorno == -1){
                    printf("Erro ao verificar se a fila está cheia!\n");
                }else if(retorno == 1){
                    printf("A fila está cheia!\n");
                }else{
                    printf("A fila não está cheia!\n");
                }
                break;
            case 5:
                retorno = verificarFilaVazia(fi);
                if(retorno == -1){
                    printf("Erro ao verificar se a fila está vazia!\n");
                }else if(retorno == 1){
                    printf("A fila está vazia!\n");
                }else{
                    printf("A fila não está vazia!\n");
                }
                break;
            case 6:
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
                retorno = inserirElementoFila(fi, al);
                if(retorno == 1){
                    printf("Aluno inserido com sucesso!\n");
                }else{
                    printf("Erro ao inserir aluno!\n");
                }
                break;
            case 7:
                retorno = removerElementoFila(fi);
                if(retorno == 1){
                    printf("Aluno removido com sucesso!\n");
                }else{
                    printf("Erro ao remover aluno!\n");
                }
                break;
            case 8:
                retorno = consultarInicioFila(fi, &al);
                if(retorno == 1){
                    printf("Matrícula: [ %d ]\n", al.matricula);
                    printf("Nome: [ %s ]\n", al.nome);
                    printf("Notas: %.2f | %.2f | %.2f\n", al.n1, al.n2, al.n3);
                }else{
                    printf("Erro ao consultar início da fila!\n");
                }
                break;
            case 9:
                imprimirFila(fi);
                break;
            case 0:
                liberarFila(fi);
                printf("Programa encerrado!\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
            }
    }while(opcao != 0);
    if(fi != NULL){
        liberarFila(fi);
    }
    return 0;
}