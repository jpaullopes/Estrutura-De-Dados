# Projeto de Lista Duplamente Encadeada

Este projeto implementa uma estrutura de dados de lista duplamente encadeada em C. O objetivo é fornecer funcionalidades para manipulação de listas de alunos, incluindo inserção, remoção, busca e verificação de estado.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

### `duplamenteEncadeada.h`

Este arquivo contém as definições de tipos e os protótipos das funções para a lista duplamente encadeada.

- Define a estrutura `Aluno` que armazena os dados dos alunos.
- Define a estrutura `elemento` que representa um nó da lista duplamente encadeada.
- Define o tipo `Lista` como um ponteiro para `elemento`.
- Declara os protótipos das funções para manipulação da lista.

### `duplamenteEncadeada.c`

Este arquivo contém a implementação das funções para a lista duplamente encadeada.

- Implementa as funções para criar, liberar, inserir, remover e buscar elementos na lista.
- Define a estrutura `elemento` que representa um nó da lista duplamente encadeada.
- Implementa as funções para manipulação da lista, como inserção no início, inserção no final, remoção, busca, etc.

### `main.c`

Este arquivo contém a função principal que interage com o usuário e chama as funções de manipulação da lista.

- Inclui o arquivo de cabeçalho `duplamenteEncadeada.h`.
- Implementa a função `main` que serve como ponto de entrada do programa.
- Interage com o usuário através de um menu, permitindo a criação, manipulação e exibição das listas de alunos.

## Funcionalidades

### Lista Duplamente Encadeada

- **Criar Lista**: Cria uma lista vazia.
- **Liberar Lista**: Libera a memória alocada para a lista.
- **Inserir no Início**: Insere um aluno no início da lista.
- **Inserir no Final**: Insere um aluno no final da lista.
- **Inserção Ordenada**: Insere um aluno de forma ordenada na lista.
- **Remover do Início**: Remove um aluno do início da lista.
- **Remover do Final**: Remove um aluno do final da lista.
- **Remover por Matrícula**: Remove um aluno da lista por matrícula.
- **Buscar por Matrícula**: Busca um aluno na lista por matrícula.
- **Buscar por Posição**: Busca um aluno na lista por posição.
- **Tamanho da Lista**: Retorna a quantidade de alunos na lista.
- **Verificar se a Lista está Vazia**: Verifica se a lista está vazia.
- **Verificar se a Lista está Cheia**: Verifica se a lista está cheia (sempre retorna 0, pois a lista é dinâmica).
- **Exibir Lista**: Exibe todos os alunos na lista.

## Exemplo de uso
O programa principal (`main.c`) interage com o usuário através de um menu, permitindo a criação, manipulação e exibição das listas de alunos. Ele oferece opções para inserir, remover, buscar e verificar o estado das listas.

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests para melhorar este projeto.