# Red Black Tree 

A estrutura de dados Red Black Tree(Árvore Vermelho e Preto) é uma estrutura de árvore binária, onde cada nó dá árvore pode ter apenas dois filhos, chamados de filho direito e filho esquerdo, que por sua vez podem ter apenas dois filhos cada e assim por diante, e aproximadamente balanceada onde nenhum dos caminhos da árvore pode ser duas vezes maior do que qualquer outro. O diferencial dessa árvore binária é a utilização de cores, vermelho ou preto, para poder validar as trocas e manter seu balanceamento aproximado. Dado essa caracteristica de utilização de cores em sua estrutura a árvore Red Black possui 5 propriedades únicas:

1. Todo nó é vermelho ou preto.
2. A raiz é preta.
3. Toda folha com valor NULL é preta.
4. Se um nó é vermelho, então os seus filhos são pretos.
5. Para cada nó, todos os caminhos simples do nó até folhas descendentes contêm o mesmo número de nós pretos.

A afirmação de que um árvore Red Black com n nós internos tem, no máximo, a altura 2lg(n+1) garante que essa estrutura nos garanta uma pesquisa no tempo O(lg n), tornando-a uma ótima estrutura de pesquisa, porém não tão ótima para inserção, já que a cada inserção é necessário verificar o balanceamento de toda a árvore.

## Um dicionário utilizando Red Black Tree 

Como mencionado acima as árvores vermelho e preto são ótimas estruturas de pesquisa mas não tão ótimas estruturas de inserção, sendo assim elas funcionam muito bem como estruturas de armazenamento de dados que não fazem constante inserção e nem remoção, como um dicionário por exemplo, é um conjunto de dados, levando em conta as palavras cultas da lingua portuguesa, que não possue constante criação, alteração e nem remoção de muitas palavras ao longo do tempo, fazendo com que ele seja uma ótima escolha para a aplicação de árvores vermelho e preto.

## Funcionamento do dicionário utilizando Red Black Tree 

Para a implementação da Red Black foi utilizado no lugar do key uma estrutura Record que possue dois valores, word e description, onde word, um *char, é a palavra e description, também um *char, é o significado dessa palavras, ambos dados, palavra e significado são obtidos no arquivo, "AEDS/black_red_tree/palavras.txt", é um arquivo simples, contendo apenas 24 palavras e seus respectivos significados, foi feito assim pois essa é apenas uma demonstração de uma representação real, o arquivo poderia conter quantas entradas a memória da sua máquina permitisse. O Record recebe as entradas do arquivo disponibilizado e armazena em um nó, para a estruturação da árvore são utlizados os valores de word armazenado em cada nó, comparando, utilizando a função strcmp() da biblioteca string.h, cada palavra com outra já inserida é possível montar um dicionário utilizando a Red Black Tree.

## Fontes utilizadas na pesquisa e implementação do código

### Teoria

T. Cormen, E. Leiserson, R. L. Rivest, C. Stein. Algoritmos: Teoria e Prática, Editora Campus - Rio de Janeiro - 2002
https://www.baeldung.com/cs/red-black-trees
https://medium.com/@intuition.engin/redblackpy-fast-and-scalable-series-for-scientific-and-quantitative-research-in-python-cad49b5c6d3
https://www.quora.com/What-are-some-real-world-applications-of-Red-Black-trees-today

### Prática
T. Cormen, E. Leiserson, R. L. Rivest, C. Stein. Algoritmos: Teoria e Prática, Editora Campus - Rio de Janeiro - 2002
https://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm
https://www.codesdope.com/course/data-structures-red-black-trees/
https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
https://stackoverflow.com/questions/42800462/trying-to-implement-a-red-black-tree-in-c
https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
https://www.dicio.com.br/memoria/
http://www.lrc.ic.unicamp.br/~luciano/courses/mc202-2s2009/tutorial_gdb.txt 
