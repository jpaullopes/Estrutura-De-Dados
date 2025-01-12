#include <stdio.h>
#include <stdlib.h>
#include "listaSequencial.h"

// Estrutura da lista
// Contém a quantidade de alunos na lista e um array de alunos
struct lista{
    // Quantidade de alunos na lista
    int quantidade;
    // Array de alunos
    Aluno dados[MAX];
};
Lista* criarLista(){
    // Aloca memória para a lista e inicializa a quantidade de alunos
    Lista* lst = (Lista*) malloc(sizeof(Lista));
    if (lst == NULL) {
        printf("Memória insuficiente\n");
        // Encerra o programa
        exit(1);
    }
    lst->quantidade = 0;
    return lst;
}
void liberarLista(Lista *l){
    //Lieberar memoria alocada na lista
    free(l);
}
int tamanhoLista(Lista *li){
    //retorna a quantidade de alunos na lista
    if(li == NULL){
        return -1;
    }
    return li->quantidade;
}
int listaCheia(Lista *li){
    //retorna 1 se a lista estiver cheia e 0 se não estiver
    if(li == NULL){
        return -1;
    }
    return (li->quantidade == MAX);
}
int listaVazia(Lista *li){
    //retorna 1 se a lista estiver vazia e 0 se não estiver
    if(li == NULL){
        return -1;
    }
    return (li->quantidade == 0);
}
//Inserção de um aluno no final da lista
int inserirFinalLista(Lista *li,Aluno al){
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)){
        return 0;
    }
    //Insere o aluno no final da lista
    li->dados[li->quantidade] = al;
    return 1;
}
//Inserção de um aluno no inicio da lista
int  inserirInicioLista(Lista *li, Aluno al){
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)) return 0;
    //Desloca os elementos da lista para o final
    for(int i = li->quantidade - 1;i >= 0;i--){
        li->dados[i+1] = li->dados[i];
    }
    //Insere o aluno no inicio da lista
    li->dados[0] = al;
    //Incrementa a quantidade de alunos na lista
    li->quantidade++;
    return 1;
}
//Inserção ordenada de um aluno na lista
//com base na matrícula
int insercaoOrdenada(Lista* li, Aluno al){
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)) return 0;
    int i;
    //Procura posição de inserção
    while(i < li->quantidade && li->dados[i].matricula < al.matricula){
        i++;
    }

    //Desloca os elementos para o final da lista
    for(int k = li->quantidade-1;k >= i;k--){
        //Desloca os elementos da lista para o final
        li->dados[k+1] = li->dados[k];
        //Insere o aluno na posição correta
    }
    li->dados[i] = al;    
    //Incrementa a quantidade de alunos na lista
    li->quantidade++;
    return 1;
}
//Remoção de um aluno no final da lista
int removerFinalLista(Lista* li){
    //Verifica se a lista é válida
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    li->quantidade--;
    return 1;
}

//Remoção de um aluno no inicio da lista
int removerInicioLista(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    //Desloca os elementos uma posição para o inicio da lista
    for(int i = 0; i < li->quantidade - 1; i++){
        li->dados[i] = li->dados[i+1];
    }
    li->quantidade--;
    return 1;
}
//Remoção de um aluno do meio da lista
int removerOrdenadamenteLista(Lista* li,int matricula){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    int i = 0;
    //Procura o aluno na lista
    while(i < li->quantidade && li->dados[i].matricula != matricula){
        i++;
    }
    //Verifica se o aluno não foi encontrado
    if(i == li->quantidade) return 0;
    //Desloca os elementos uma posição para o inicio da lista
    for(int k = i;k < li->quantidade - 1;k++){
        li->dados[k] = li->dados[k+1];
    }
    li->quantidade--;
    return 1;
}

//Busca sequencial de um aluno na lista
int buscaSequencialLista(Lista* li,int matricula,Aluno *al){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    int i = 0;
    while(i < li->quantidade && li->dados[i].matricula != matricula){
        i++;
    }
    if(i == li->quantidade) return 0;
    *al = li->dados[i];
}

//Busca por posição de um aluno na lista
//estamos considerando posiçoes começando do 1
int buscaPosicaoLista(Lista * li, int pos, Aluno *al){
    if(li == NULL || pos <= 0 || pos > li->quantidade) return 0;
    *al = li->dados[pos - 1];
}