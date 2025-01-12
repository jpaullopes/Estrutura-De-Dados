# Projeto de Lista com Nó Descritor

Este projeto implementa uma estrutura de dados de lista com nó descritor em C. O objetivo é fornecer funcionalidades para manipulação de listas de alunos, incluindo inserção, remoção, busca e verificação de estado.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

### `noDescritor.h`

Este arquivo contém as definições de tipos e os protótipos das funções para a lista com nó descritor.

- Define a estrutura `Aluno` que armazena os dados dos alunos.
- Define a estrutura `No` que representa um nó simples da lista.
- Define a estrutura `noDescritor` que representa o nó descritor da lista.
- Define os tipos `NO`, `NO_DESCRITOR` e `Lista`.
- Declara os protótipos das funções para manipulação da lista.

### `noDescritor.c`

Este arquivo contém a implementação das funções para a lista com nó descritor.

- Implementa as funções para criar, liberar, inserir, remover e buscar elementos na lista.
- Define a estrutura `noDescritor` que representa o nó descritor da lista.
- Implementa as funções para manipulação da lista, como inserção no início, inserção no final, remoção, busca, etc.

### `main.c`

Este arquivo contém a função principal que interage com o usuário e chama as funções de manipulação da lista.

- Inclui o arquivo de cabeçalho `noDescritor.h`.
- Implementa a função `main` que serve como ponto de entrada do programa.
- Interage com o usuário através de um menu, permitindo a criação, manipulação e exibição das listas de alunos.

## Funcionalidades

### Lista com Nó Descritor

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

## Exemplo de Uso

O programa principal (`main.c`) interage com o usuário através de um menu, permitindo a criação, manipulação e exibição das listas de alunos. Ele oferece opções para inserir, remover, buscar e verificar o estado das listas.

### Menu de Opções

1. Criar lista
2. Liberar lista
3. Inserir aluno no início
4. Inserir aluno no final
5. Inserir aluno ordenadamente
6. Remover aluno do início
7. Remover aluno do final
8. Remover aluno por matrícula
9. Consultar aluno por posição
10. Consultar aluno por matrícula
11. Exibir tamanho da lista
12. Verificar se a lista está cheia
13. Verificar se a lista está vazia
14. Exibir lista
0. Sair

### Exemplo de Interação

O usuário pode escolher uma das opções acima para realizar operações na lista. Por exemplo, para inserir um aluno no início da lista, o usuário deve escolher a opção 3 e fornecer os dados do aluno. O programa então insere o aluno no início da lista e exibe uma mensagem de confirmação.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests para melhorar este projeto.