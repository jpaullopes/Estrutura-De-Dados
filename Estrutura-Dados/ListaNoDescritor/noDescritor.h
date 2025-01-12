struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct aluno Aluno;

struct No{ //No simples
    Aluno dados;
    struct No *prox;
};

typedef struct No NO;

struct noDescritor{ //criando a estrutura do nó descritor
    NO *inicio; //ponteiro para o início da lista
    NO *fim; //ponteiro para o fim da lista
    int qtd; //quantidade de elementos na lista
};

typedef struct noDescritor NO_DESCRITOR;

//Funções
//criação do nó descritor
NO_DESCRITOR *criaDescritor();
//liberar nó descritor
void liberaDescritor(NO_DESCRITOR *li);
//lista vazia
int listaVazia(NO_DESCRITOR *li);
//se a lista está cheia
int listaCheia(NO_DESCRITOR *li);
//tamanho da lista
int tamanhoLista(NO_DESCRITOR *li);
//insere no início
int insereInicio(NO_DESCRITOR *li, Aluno al);
//insero no final
int insereFinal(NO_DESCRITOR *li, Aluno al);
//insere ordenado
int insereOrdenado(NO_DESCRITOR *li, Aluno al);
//remove do início
int removeInicio(NO_DESCRITOR *li);
//remoção do final
int removeFinal(NO_DESCRITOR *li);
//remoção com base na matricula
int removeMatricula(NO_DESCRITOR *li, int mat);
//consulta por matricula
int consultaMatricula(NO_DESCRITOR *li, int mat, Aluno *al);
//consulta por posição
int consultaPosicao(NO_DESCRITOR *li, int pos, Aluno *al);
//imprimir lista
void imprimeLista(NO_DESCRITOR *li);