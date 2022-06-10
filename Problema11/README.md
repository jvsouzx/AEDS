# Problema 11
Trabalho realizado para a disciplina de Laboratório de Algorítmos e Estrutura de Dados

Problema Proposto: 

Em um computador há diferentes arquivos, e esses só podem ser carregados para a memória
de forma parcial (pense grande, há muitos dados). Como a memória não é infinita, de tempos
em tempos parte desses arquivos precisarão ser devolvidos para o disco para liberar espaço
para novas partes. Para isso o computador adota a seguinte estratégia: Um processo Pk
solicita uma ordem/sequência de leitura das partes de acordo com um arquivo de configuração.
Arquivo esse definido no seguinte padrão hP1, 04, 07, 01, 01, 08, 06, ...., 03i.
A sequência de páginas de um processo é buscada em disco e enviada para a memória,
a qual as organiza em ordem de chegada. Quando o espaço de memória que aloca as partes
do arquivo do processo Pk estiver cheia, ou seja, com 5 partes, uma parte será devolvida para
o disco. Como regra, a parte enviada para disco sempre será a mais antiga solicitada, ou seja,
a que chegou primeiro dentre as 5.
Quando uma parte do arquivo é solicitada por um processo, pode-se ocorrer uma de duas
condições: 1) - A parte já está em memória, logo, não há essa mesma página em disco. Logo,
apenas a utilizamos e computamos como acesso válido de memória; 2) - A parte não está em
memória e precisa ser removida do disco e transportada para a memória. Nesse caso, computamos como falha de leitura e executamos o procedimento de carregamento dessa página
para a memória, retirando-a do disco. A Figura 1 detalha o modelo de simulador a ser construído.



![prob11](https://user-images.githubusercontent.com/60747654/125209158-5f1d4b00-e26d-11eb-83b9-f6d58d38bc81.PNG)



Problema a ser resolvido: 

Elaborar um código estruturado em C/C++ que consiga simular
as condições descritas. Considere para isso estabelecer um arquivo de entrada/configuração
cujas linhas representam processos e chamadas de partes de um arquivo conforme exemplo
detalhado no primeiro parágrafo. Junto a isso, considere um segundo arquivo que detalhe M
arquivos e a ordem de suas partes conforme exemplo: hA1, 03, 02, 05, 01, 04i. Observe que
o arquivo de configuração define o arquivo A1 com 5 partes e a ordem de suas partes está
definida conforme o exemplo. Assim, sua função é emular todo esse sistema com esses dois
arquivos de entrada pré-definidos. Por fim, detalhar quantos erros de leitura ocorreram e 
quantas leituras de memória bem sucedidas ocorreram por processo. Por fim, sugerir uma forma
melhor de organizar a memória que reduza a quantidade de falhas durante a execução. Mostre
em relatório qual é a porcentagem de ganho que sua solução apresenta em comparação com
a solução básica implementada.

Implementação:

Por meio de um programa feito em C, dividido em memoria, disco e list, foi implementado um modelo
que cria um disco por meio de uma estrutura de lista e inicia uma memoria por meio de uma matriz
assim chegando ao ponto de executar processos, os mesmos configurados por meio de arquivos de texto
(.txt)

# Compilar
 
make

make run

Att: Jorge Vitor G. de Souza

