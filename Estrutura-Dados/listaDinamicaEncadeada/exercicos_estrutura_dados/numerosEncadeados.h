typedef struct numerosEncadeados{
    int num;
    struct numerosEncadeados *prox;
}*No;

//função que cria um nó
No criarNo(int num,No lista);
//função que libera uma lista
void liberarLista(No *lista);
//exibe a lista
void exibirLista(No lista);
//exibe a lista de forma recursiva invertida
void exibirListaInvertida(No lista);
//contar occorencias no numero
int contarOcorrencias(No lista, int num);
//devolve o ultimo elemento da lsta
int ultimoElemento(No lista);
//função que realiza a inversão da lista
//No inverterLista(No lista);
//função que realiza a soma dos elementos da lista de forma recursiva
int somaElementos(No lista);
//verifica se o elento está na lista
int verificarElemento(No lista, int num);
//função que realiza a substituição dos itens da lista
int substituirElemento(No lista, int num, int novoNum);
//retornar tamanho da lista
int tamanhoLista(No lista);
//verificar se duas listas são iguais
int verificarTamanho(No lista1, No lista2);
//retorna o enesimo elemtento da lista
int enesimoElemento(No lista, int n);
//enfilaremento de lista circular encadeada
No criarNoCircular(int num,No lista);
//exibir lista circular
void exibirListaCircular(No lista);
//desinfeleira uma lista(Nó) circular
void desenfileirarListaCircular(No lista);
