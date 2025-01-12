# Projeto de Pilha Estática e Pilha Dinâmica

Este projeto implementa duas estruturas de dados de pilha em C: pilha estática e pilha dinâmica. O objetivo é fornecer funcionalidades para manipulação de pilhas, incluindo inserção, remoção, busca e verificação de estado.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

### `pilhaEstatica.h`

Este arquivo contém as definições de tipos e os protótipos das funções para a pilha estática.

- Define a estrutura `Aluno` que armazena os dados dos alunos.
- Define a estrutura `Pilha` que representa a pilha estática.
- Declara os protótipos das funções para manipulação da pilha.

### `pilhaEstatica.c`

Este arquivo contém a implementação das funções para a pilha estática.

- Implementa as funções para criar, liberar, inserir, remover e buscar elementos na pilha.
- Define a estrutura `Pilha` que representa a pilha estática.
- Implementa as funções para manipulação da pilha, como inserção, remoção, busca, etc.

### `mainPilhaEstatica.c`

Este arquivo contém a função principal que interage com o usuário e chama as funções de manipulação da pilha estática.

- Inclui o arquivo de cabeçalho `pilhaEstatica.h`.
- Implementa a função `main` que serve como ponto de entrada do programa.
- Interage com o usuário através de um menu, permitindo a criação, manipulação e exibição das pilhas de alunos.

### `pilhaDinamica.h`

Este arquivo contém as definições de tipos e os protótipos das funções para a pilha dinâmica.

- Define a estrutura `Aluno` que armazena os dados dos alunos.
- Define a estrutura `No` que representa um nó da pilha dinâmica.
- Define a estrutura `Pilha` que representa a pilha dinâmica.
- Declara os protótipos das funções para manipulação da pilha.

### `pilhaDinamica.c`

Este arquivo contém a implementação das funções para a pilha dinâmica.

- Implementa as funções para criar, liberar, inserir, remover e buscar elementos na pilha.
- Define a estrutura `Pilha` que representa a pilha dinâmica.
- Implementa as funções para manipulação da pilha, como inserção, remoção, busca, etc.

### `mainPilhaDinamica.c`

Este arquivo contém a função principal que interage com o usuário e chama as funções de manipulação da pilha dinâmica.

- Inclui o arquivo de cabeçalho `pilhaDinamica.h`.
- Implementa a função `main` que serve como ponto de entrada do programa.
- Interage com o usuário através de um menu, permitindo a criação, manipulação e exibição das pilhas de alunos.

## Funcionalidades

### Pilha Estática

- **Criar Pilha**: Cria uma pilha vazia.
- **Liberar Pilha**: Libera a memória alocada para a pilha.
- **Tamanho da Pilha**: Retorna a quantidade de elementos na pilha.
- **Verificar se a Pilha está Cheia**: Verifica se a pilha está cheia.
- **Verificar se a Pilha está Vazia**: Verifica se a pilha está vazia.
- **Inserir na Pilha**: Insere um aluno no topo da pilha.
- **Remover da Pilha**: Remove um aluno do topo da pilha.
- **Consultar Topo da Pilha**: Consulta o aluno no topo da pilha.
- **Imprimir Pilha**: Imprime todos os elementos da pilha.

### Pilha Dinâmica

- **Criar Pilha**: Cria uma pilha vazia.
- **Liberar Pilha**: Libera a memória alocada para a pilha.
- **Tamanho da Pilha**: Retorna a quantidade de elementos na pilha.
- **Verificar se a Pilha está Vazia**: Verifica se a pilha está vazia.
- **Inserir na Pilha**: Insere um aluno no topo da pilha.
- **Remover da Pilha**: Remove um aluno do topo da pilha.
- **Consultar Topo da Pilha**: Consulta o aluno no topo da pilha.
- **Imprimir Pilha**: Imprime todos os elementos da pilha.

## Exemplo de Uso

Os programas principais (`mainPilhaEstatica.c` e `mainPilhaDinamica.c`) interagem com o usuário através de um menu, permitindo a criação, manipulação e exibição das pilhas de alunos. Eles oferecem opções para inserir, remover, buscar e verificar o estado das pilhas.

### Menu de Opções

1. Criar pilha
2. Liberar pilha
3. Tamanho da pilha
4. Inserir elemento na pilha
5. Remover elemento da pilha
6. Consultar topo da pilha
7. Imprimir pilha
8. Verificar se a pilha está vazia
9. Verificar se a pilha está cheia (apenas para pilha estática)
0. Sair

### Exemplo de Interação

O usuário pode escolher uma das opções acima para realizar operações na pilha. Por exemplo, para inserir um aluno na pilha, o usuário deve escolher a opção 4 e fornecer os dados do aluno. O programa então insere o aluno na pilha e exibe uma mensagem de confirmação.

### Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests para melhorar este projeto.

### Licença
Este projeto está licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE.txt) para mais detalhes.