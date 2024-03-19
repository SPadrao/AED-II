Exercicio_01-numPrimo.c <br>
Recebe um número inteiro N que representa quantas ações deseja realizar. Em seguida, lê N números inteiros e verifica se cada um é primo ou não, utilizando a função ehPrimo. Para cada número lido, imprime o número seguido de "1" se for primo, ou "0" se não for primo.

Exercicio_02-recursao.c
Calcula quantos livros podem ser comprados usando vales de desconto.

    - A função compra calcula quantos livros podem ser comprados dada a quantidade de dinheiro d disponível e o preço p de cada livro. Retorna a quantidade de livros que podem ser comprados.
    - A função vale calcula quantos livros adicionais podem ser comprados usando vales de desconto. Recebe como entrada a quantidade de livros já comprados livros e a quantidade de vales disponíveis vales. Se houver vales suficientes, cada vale permite comprar um livro adicional. A função chama a si mesma recursivamente enquanto houver vales disponíveis.
    - Na função main, o programa lê um número N representando quantas ações deseja realizar.
    - Um loop while é utilizado para ler N conjuntos de dados, onde cada conjunto consiste em três valores: o dinheiro disponível d, o preço de cada livro p, e o número de vales v.
    - Para cada conjunto de dados lido, o programa calcula quantos livros podem ser comprados sem vales usando a função compra. Em seguida, calcula quantos livros adicionais podem ser comprados usando vales usando a função vale.
    - O programa imprime o total de livros que podem ser comprados.
    - O loop continua até que todas as ações desejadas sejam realizadas ou até que N seja maior que 10.

Exercicio_04-MergeSort.c
Conta o número de pares em um vetor ordenado que satisfazem uma condição específica. Primeiro lê o tamanho do vetor e um valor K, seguido pelos elementos do vetor. Em seguida, utiliza o algoritmo de ordenação Merge Sort para ordenar o vetor e, durante esse processo, conta quantos pares de elementos satisfazem a condição v[j] * k < v[i]. Por fim, imprime o total de pares encontrados.

Exercicio_05-QuickSort.c
Utiliza o algoritmo de ordenação QuickSort em C para encontrar o k-ésimo menor elemento em um vetor. Realiza a ordenação do vetor usando o QuickSort e, em seguida, imprime o k-ésimo menor elemento encontrado, junto com os elementos ordenados do vetor. O usuário fornece o valor de k e o tamanho do vetor, seguido pelos elementos do vetor, e o programa retorna o k-ésimo menor elemento.

Exercicio_08-ABB.c
Implementa uma estrutura de dados de árvore binária de busca (BST). Permite inserir valores na árvore, buscar valores, remover valores, calcular a altura da árvore e imprimir a árvore em ordem. A altura da árvore é calculada e impressa, assim como a altura da árvore a partir de um nó específico. Também lê valores do usuário, inserindo-os ou removendo-os da árvore conforme necessário, e exibe a altura da árvore a partir de um valor de entrada específico.

Exercicio_09-AVL.c
O código implementa uma árvore AVL em C, um tipo de árvore binária de busca balanceada, que mantém a altura da árvore próxima do mínimo possível para garantir operações de busca, inserção e remoção eficientes. Ele permite inserir valores na árvore, buscar valores, remover valores, calcular e imprimir a altura dos nós da árvore. O programa recebe valores do usuário, inserindo ou removendo da árvore conforme necessário, e exibe a altura dos nós da árvore e os valores dos nós em ordem.

Exercicio_11-AVP.c
O código implementa uma árvore vermelho-preta em C, uma estrutura de dados de árvore binária balanceada, onde cada nó tem uma cor associada (vermelho ou preto) e as seguintes propriedades:

1. Todo nó é vermelho ou preto.
2. A raiz é sempre preta.
3. Todas as folhas (NULL) são pretas.
4. Se um nó é vermelho, então ambos os filhos devem ser pretos.
5. Para cada nó, todos os caminhos de qualquer folha a ele têm o mesmo número de nós pretos.

O programa permite inserir valores na árvore vermelho-preta, consultar a altura de um nó específico, imprimir a altura dos nós da árvore e verificar se um valor está presente na árvore. Ele recebe valores do usuário, inserindo ou consultando a árvore conforme necessário, e exibe a altura dos nós da árvore.

Exercicio_13-Hash.c
Implementação básica de uma tabela de dispersão com encadeamento em C. 

Exercicio_14-ArvoreB.c
O código implementa uma árvore B em C, oferecendo funcionalidades de inserção, pesquisa e contagem de elementos. Após a inicialização da árvore, os registros são inseridos até que um valor negativo seja lido, e então é impressa a quantidade de registros presentes na raiz. Após a leitura de uma chave para pesquisa, o programa realiza a busca na árvore e conta a quantidade de ocorrências do registro. Se o registro não for encontrado, é impressa a quantidade de elementos na raiz da árvore.

Insertion_Sort_Recursivo.c
O código implementa uma versão recursiva do algoritmo de ordenação insertion sort em C. O algoritmo é aplicado a um vetor de inteiros lido como entrada, e a cada chamada recursiva, ordena uma porção menor do vetor até que todo o vetor esteja ordenado. Durante a ordenação, são contabilizadas as operações realizadas e exibidas na saída padrão, além de mostrar o estado do vetor após cada iteração. O programa é finalizado mostrando o vetor ordenado.

Jogo_das_Bolhas.c
O programa implementa o algoritmo Bubble Sort em C para ordenar um vetor de inteiros. Durante a ordenação, é contabilizado o número de trocas realizadas. Com base no número de trocas, o programa determina se Carlos ou Marcelo ganha em um jogo específico, onde o vencedor depende da paridade do número de trocas. O programa recebe como entrada o tamanho do vetor e os elementos do vetor a serem ordenados, e então imprime o vetor ordenado seguido do nome do vencedor do jogo.
