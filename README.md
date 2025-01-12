# Repositório de Estruturas de Dados em C

Este repositório contém implementações de diversas estruturas de dados utilizando a linguagem C. O objetivo é oferecer exemplos práticos e funcionais para o aprendizado e manipulação de estruturas como listas, pilhas e filas.

## Organização do Repositório

O código-fonte está organizado nas seguintes pastas:

* **[`C/`](./C/)**: Contém arquivos com funções relacionadas a coordenadas.
* **[`Estrutura-Dados/`](./Estrutura-Dados/)**: Contém as implementações das estruturas de dados, subdivididas da seguinte forma:

    *   **[`exercicioPilhaED/`](./Estrutura-Dados/exercicioPilhaED/)**: Implementações de pilhas estáticas e dinâmicas.
    *   **[`Fila/`](./Estrutura-Dados/Fila/)**: Implementações de filas estáticas e dinâmicas.
    *   **[`listaCircular/`](./Estrutura-Dados/listaCircular/)**: Implementações de listas circulares.
    *   **[`listaDinamicaEncadeada/`](./Estrutura-Dados/listaDinamicaEncadeada/)**: Implementações de listas encadeadas dinâmicas.
    *   **[`listaDuplamenteEncadeada/`](./Estrutura-Dados/listaDuplamenteEncadeada/)**: Implementações de listas duplamente encadeadas.
    *   **[`ListaNoDescritor/`](./Estrutura-Dados/ListaNoDescritor/)**: Implementações de listas com nó descritor.
    *   **[`listaSequencial/`](./Estrutura-Dados/listaSequencial/)**: Implementações de listas sequenciais.
    *   **[`Pilha/`](./Estrutura-Dados/Pilha/)**: Implementações de pilhas (genéricas ou adicionais).


## Funcionalidades Implementadas

Dentro de cada subdiretório em `Estrutura-Dados/`, você encontrará implementações específicas para a estrutura de dados correspondente. Isso inclui:

*   Funções para criação e destruição da estrutura.
*   Operações de inserção e remoção de elementos.
*   Funções de busca.
*   Funções para verificação de estado da estrutura (vazia, cheia, etc.).

Os arquivos `README.md` em cada subdiretório fornecem detalhes adicionais sobre as funcionalidades específicas de cada estrutura.

## Compilação e Execução

Para compilar e executar os exemplos, você precisará de um compilador C, como o GCC. Navegue até o diretório que contém o arquivo `.c` que você deseja compilar e execute o seguinte comando no seu terminal:

```bash
gcc -o programa main.c
```

Este comando cria um executável chamado `programa`. Para executar, digite no terminal:

```bash
./programa
```

Lembre-se de substituir `main.c` pelo nome do arquivo que você deseja compilar, se necessário.

