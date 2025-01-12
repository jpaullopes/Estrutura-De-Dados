struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct aluno Aluno;

struct listaCircular{
    Aluno dados;
    struct listaCircular *prox; //ponteiro que aponta para proximo elemento
};

typedef struct listaCircular ListaCircular;
typedef ListaCircular *Lista; //ponteiro que aponta para a lista

//Crianção da lista
Lista* criarLista(void); //retorno de um ponteiro de ponteiro(**li)
//Libera a lista
void liberarLista(Lista *li);
//tamanho da lista
int tamanhoLista(Lista *li);
//lista cheia
int listaCheia(Lista *li);
//lista vazia
int listaVazia(Lista *li);
//Inserção no inicio da lista
int insereInicio(Lista *li, Aluno al);
//inserçã no final da lista
int insereFinal(Lista *li, Aluno al);
//inserção ordenada com base na matricula
int insereOrdenado(Lista *li, Aluno al);
//temoção no incio da lista
int removeInicio(Lista *li);
//remoção no final da lista
int removeFinal(Lista *li);
//remoção de um elemento qualquer | baseado na matricula
int removeQualquer(Lista *li, int matricula);
//conulta com base na posição
int consultaPosicao(Lista *li, int posicao, Aluno *al);
//consulta com base em critério(matricula)
int consultaMatricula(Lista *li, int matricula, Aluno *al);