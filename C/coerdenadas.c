#include <stdio.h>
#include <stdlib.h>
#include "cordenadas.h"

struct ponto {
    float x;
    float y;
};

Ponto* criarPonto(float x, float y) {
    // Aloca memória para um novo ponto e inicializa suas coordenadas
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p == NULL) {
        printf("Memória insuficiente\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void liberarPonto(Ponto *p){
    // Libera a memória alocada para o ponto
    free(p);
}

void acessarPonto(Ponto* p, float* x, float* y){
    // Atribui as coordenadas do ponto às variáveis fornecidas
    *x = p->x;
    *y = p->y;
}

void atribuirPonto(Ponto* p, float x, float y){
    // Atribui novas coordenadas ao ponto
    p->x = x;
    p->y = y;
}

float distanciaPontos(Ponto* p1, Ponto* p2){
    // Calcula a distância euclidiana entre dois pontos
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}