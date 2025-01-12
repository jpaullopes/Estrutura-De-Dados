# Projeto de Fila Dinâmica e Fila Estática

Este projeto está em processo de desenvolvimento e implementará duas estruturas de dados: fila dinâmica e fila estática. O objetivo é fornecer funcionalidades para manipulação de filas, incluindo inserção, remoção, busca e verificação de estado.

## Estrutura do Projeto

O projeto será composto pelos seguintes arquivos:

### `filaDinamica.h`

Este arquivo conterá as definições de tipos e os protótipos das funções para a fila dinâmica.

### `filaDinamica.c`

Este arquivo conterá a implementação das funções para a fila dinâmica.

### `filaEstatica.h`

Este arquivo conterá as definições de tipos e os protótipos das funções para a fila estática.

### `filaEstatica.c`

Este arquivo conterá a implementação das funções para a fila estática.

### `main.c`

Este arquivo conterá a função principal que interage com o usuário e chama as funções de manipulação das filas.

## Funcionalidades

### Fila Estática

- **Criar Fila**: Cria uma fila vazia.
- **Liberar Fila**: Libera a memória alocada para a fila.
- **Tamanho da Fila**: Retorna a quantidade de elementos na fila.
- **Verificar se a Fila está Cheia**: Verifica se a fila está cheia.
- **Verificar se a Fila está Vazia**: Verifica se a fila está vazia.
- **Inserir no Final da Fila**: Insere um aluno no final da fila.
- **Remover do Início da Fila**: Remove um aluno do início da fila.
- **Consultar Início da Fila**: Consulta o aluno no início da fila.

## Exemplo de Uso

O programa principal (`main.c`) interage com o usuário através de um menu, permitindo a criação, manipulação e exibição das filas de alunos. Ele oferece opções para inserir, remover, buscar e verificar o estado das filas.

### Menu de Opções

1. Criar fila
2. Liberar fila
3. Inserir aluno no final
4. Remover aluno do início
5. Consultar aluno no início
6. Exibir tamanho da fila
7. Verificar se a fila está cheia
8. Verificar se a fila está vazia
0. Sair

### Exemplo de Interação

O usuário pode escolher uma das opções acima para realizar operações na fila. Por exemplo, para inserir um aluno no final da fila, o usuário deve escolher a opção 3 e fornecer os dados do aluno. O programa então insere o aluno no final da fila e exibe uma mensagem de confirmação.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests para melhorar este projeto.

## Licença

Este projeto estará licenciado sob a licença MIT. Veja o arquivo [LICENSE](LICENSE.txt) para mais detalhes.
