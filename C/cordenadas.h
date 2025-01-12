#include <stdio.h>

typedef struct ponto Ponto;

// Cria um novo ponto com coordenadas x e y
Ponto* criarPonto(float x, float y);

// Libera a memória alocada para um ponto
void liberarPonto(Ponto* p);

// Retorna as coordenadas de um ponto
void acessarPonto(Ponto* p, float* x, float* y);

// Atribui novas coordenadas a um ponto
void atribuirPonto(Ponto* p, float x, float y);

// Calcula a distância entre dois pontos
float distanciaPontos(Ponto* p1, Ponto* p2);
