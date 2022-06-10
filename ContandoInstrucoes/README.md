# CONTANDO INSTRUÇÕES

Trabalho realizado para a disciplina de Algoritmo e Estrutura de Dados

# Problema Proposto

Criar um programa em C que execute as seguintes operações:

1) - Preenche a matriz N x N com números inteiros aleatórios de 0 a 99;

2) - Considere a posição Linha 0 e Coluna 0 (0,0) como início;

3) - Considere a posição (n, n) como posição final;

4) - Percorra a matriz a partir do início, somando a cada passo, o próximo maior valor encontrado;

5) - O próximo valor pode ser o que está na mesma linha e imediatamente à direita, imediatamente à esquerda, bem como, o que está na coluna abaixo do numero corrente. Há apenas uma exceção de percurso. Ao chegar na última linha deve-se percorre-la até o fim sem realizar mais migrações para colunas acima. 

Observe um exemplo logo abaixo para uma matriz com N = 7.

![nxn](https://user-images.githubusercontent.com/60747654/126351556-7dbf2ed4-5b83-4ff9-9892-a26072ffc060.PNG)

# Desenvolvimento do Problema
O problema foi desenvolvido da seguinte maneira:
1) - É solicitado ao User um número qualquer N.
2) - Após informado o N, o prohrama inicia uma matriz N x N de números randomicos entre 0 e 99.
 
      ![matrizcriada](https://user-images.githubusercontent.com/60747654/126354210-fde5eb1f-db67-4d3d-8011-cebfa285b41f.PNG)
      ![initmatriz](https://user-images.githubusercontent.com/60747654/126354218-5d12a2ba-40b8-43f7-a7d4-33930a921dcf.PNG)
4) - O tratamento das regras do jogo é feito por meio de vários testes(if e else).
5) - Após o jogo ser executado, na posição onde os valores foram somados os mesmos foram substituídos por -1.
      ![caminhorealizado](https://user-images.githubusercontent.com/60747654/126354227-11660174-b0db-45a8-ad52-b420bf5d1520.PNG)
     
# Questões

1) - Qual o custo computacional do algoritmo desenvolvido?      
     Como a matriz criada é de tamanho n x n, o custo no pior caso seria de n^2, e aconteceria caso seja preciso percorrer todas as posições para terminar o jogo.
     como exemplo uma matriz do tipo : \
     9 8 7 \
     6 5 4 \
     3 2 1 
2) - Há mais de uma maneira de resolver esse problema ? \
     Sim, há varias maneiras de se modelar um programa que atenda o problema proposto. Uma boa maneira seria implementando matrizes com alocação dinâmica.
3) - Há algum algoritmo famoso em literatura que resolva isso ? \
     Os algoritmos de ordenação como o quicksort, o bubblesort e etc. Ou até mesmo o algoritmo de djikstra poderiam resolver o problema proposto.
      
      
      
      
      
      
      


