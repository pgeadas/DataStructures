################## DataStructures

Solving a problem using BST Trees, AVL trees, Linked Lists, written in C.






#########################################################
A Caixa dos Números
########################################################
A “Caixa dos Números” é um baú muito especial que armazena números na forma de
sequências ordenadas. A inserção de números é feita com a operação SAVE(x), na qual x
é o inteiro que se pretende adicionar (e sendo possível inserir várias vezes o mesmo
número).
A caixa permite também saber qual o elemento na enésima posição. Para isso dispõe da
operação LOAD. A primeira vez que é invocada, essa operação indica qual o primeiro
elemento da sequência ordenada, a segunda vez é indicado o valor do segundo
elemento da sequência, e a enésima vez indica o valor do enésimo elemento da
sequência. Para melhor compreender o funcionamento da Caixa dos Números, atente-se
ao seguinte exemplo:
Operação n Conteúdo da Caixa (ordenado) Resposta
------------------------------------------------------
SAVE(-1) 0 -1
SAVE(1) 0 -1, 1
LOAD 1 -1, 1 -1
LOAD 2 -1, 1 1
SAVE(57) 2 -1, 1, 57
SAVE(2) 2 -1, 1, 2, 57
SAVE(8) 2 -1, 1, 2, 8, 57
LOAD 3 -1, 1, 2, 8, 57 2
SAVE(456) 3 -1, 1, 2, 8, 57, 456
LOAD 4 -1, 1, 2, 8, 57, 456 8
SAVE(2) 4 -1, 1, 2, 2, 8, 57, 456
--------------------------------------------------
Cada elemento inserido na lista está compreendido no intervalo -2 x 109 ≤ x ≤ 2 x 109.
5/6
Dado que o número máximo de operações SAVE(x) e LOAD é elevado (60.000 operações
de cada tipo), é necessário aplicar um algoritmo bastante eficiente para a “Caixa dos
Números”.
É garantido que a n-ésima operação LOAD só é efectuada quando já estiverem na lista
pelo menos n elementos.
O Input
A primeira linha do Input indica o número de “caixas” a tratar, devendo cada “caixa” ser
tratada de forma independente.
Segue-se o input relativo a cada uma das caixas, separado do anterior por uma linha em
branco.
Para cada “caixa” o input inclui, na primeira linha, dois inteiros que representam,
respectivamente, o número de elementos a incluir na caixa e o número de operações
LOAD a efectuar. Seguem-se duas sequências de números: os elementos a inserir na
caixa (primeira sequência) e os momentos nos quais são invocadas as operações LOAD
(segunda sequência).
O Output
Para cada “caixa” deve ser indicado o valor de cada operação LOAD. Outputs gerados
por “caixas” distintas deverão ser separados por um espaço em branco.
Pegando no exemplo já mencionado (1ª caixa) e numa segunda caixa semelhante mas
apenas com 3 operações LOAD, atente-se no seguinte exemplo de input/output:
Pode ver de seguida alguns exemplos de entrada e saída do programa.

ENTRADA
2
7 4
3 1 57 2 8 456 2
2 2 3 5
6/6
7 3
3 1 57 20 8 456 2
2 4 6

SAÍDA
13
57
8 138
