typedef char Itemp; // Tipo do item da pilha

// Estrutura da pilha
typedef struct pilha{
    int max;
    int topo;
    Itemp *item; // vetor de itens
} *Pilha;

// Funções
// Função para criar uma pilha
Pilha criarPilha(int max);
//função que confere se a pilha está vazia
int pilhaVazia(Pilha pi);
//função que confere se a pilha está cheia
int pilhaCheia(Pilha pi);
//função que insere um item na pilha
int empilha(Pilha pi, Itemp item);
//função que remove um item da pilha e retorna ele
Itemp desempilha(Pilha pi);
//função que retorna o item do topo da pilha
Itemp topo(Pilha pi);
//função que libera a pilha
void desimpilhar(Pilha pi);