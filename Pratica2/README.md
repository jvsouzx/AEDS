# Pratica 2 - Algoritmos e Estrutura de Dados #
Trabalho realizado para a disciplina de Algoritmos e Estrutura de Dados \
CEFET - MG Campus V \
Jorge Vitor G. de Souza
## Compilar ##
```
  make
  make run
```
## Problema 1 - Listas ##
### Enunciado ###

Conforme literatura, o tipo lista é uma estrutura de dado extremamente flexível cuja definição
permite o armazenamento de informação sem muitas regras de manipulação. Sabendo-se
disso, considere dois conjuntos aleatórios de dados, um apenas com números impares e outro
com pares. Veja um exemplo: I = {1, 33, 25, 87, . . . , 13} e P = {62, 42, 36, 48, . . . , 14}. Realize
as solicitações de implementação a seguir considerando para isso estruturar sua solução da
seguinte forma: i) Uma implementação por letra e; ii) Uma implementação magma que conecte
todas as letras por um único menu para execução. 

- a: Crie duas listas (i.e., L1 e L2) com 100 elementos cada conforme regra par/impar acima
apresentada. Feito isso, elabore uma função de concatenação que faça a união de L1
e L2 mantendo as posições de paridade em ordem crescente, ou seja, {{L1[0], L2[0]},
{L1[1], L2[1]}, . . . , {L1[99], L2[99]}}. 

- b: Crie um pequeno jogo utilizando duas listas (i.e., L1 e L2). Nesse, cada lista deve
ter tamanho máximo de 3 entradas e cada posição deve armazenar um número inteiro
aleatório entre 1 e 13. Nesse jogo, após preencher ambas as listas, selecione também
de forma aleatória mais um valor entre 1 e 13 e mostre-o na tela. A regra do jogo é a
seguinte: Ambas as listas devem ser apresentadas na tela de forma sequencial a partir de suas posições de paridade, ou seja, {{L1[0], L2[0]}, {L1[1], L2[1]}, {L1[2], L2[2]}}.
Cada par deve ser subtraído do valor apresentado e ganha o jogo a lista que apresentar
a maior soma final. Mostre o ganhador ao final. 

- c: Crie um pequeno sistema com três listas dinâmicas L1, L2 e L3. A primeira lista deve
armazenar o nome de um produto de mercado comum como pão, arroz, feijão, etc .. bem
como sua quantidade e um identificador único do tipo inteiro. A segunda lista deve armazenar os diferentes mercados da cidade em que esse produto se encontra em estoque,
não é obrigado que todos os mercados tenham os mesmos produtos. Além disso, na L2
é desejável também que tenhamos um identificado único para o mercado. Por fim, em L3
teremos uma estrutura que detalha o preço de um determinado produto para um mercado
específico. Dessa forma, essa última estrutura deve conter dois identificadores (produto
vs mercado) e o respectivo preço. Sua função nessa aplicação é relacionar produtos vs
mercado vs preço e mostrar ao final o menor custo total para uma compra. Para tanto,
detalhe em tela produto, menor preço e mercado a ser comprado.

### Resolução ###

- a) Para a resolução do item a, foi implementada uma estrutura de lista estática devido a informação prévia do número de elementos.
    Para o prenchimento da lista foi utilizado um metodo para gerar números randômicos entre 1 e 99. Por exemplo para gerar a lista de números pares:
    ```
    
    srand((unsigned)time(NULL));
    while(aux1 != MAXTAM){
		  Item d;
		  d.val = rand()%99;
		  if(d.val % 2 == 0 && d.val != 0){
			  ListInsert(par, d);
			  aux1++;
		  }
	  }
    ```
    Por fim, foi criada uma função que concatena os valores da lista par com os valores da lista impar, mantendo as respectivas posições juntas:
    ```	
    char str[10];
    int result;
    for(int i = par->first; i < par->last; i++){
		Item c;
		sprintf(str, "%d%d",  par->vet[i].val, imp->vet[i].val);
		result = strtol(str, NULL, 10);
		c.val = result;
		ListInsert(conc, c);
	}
    ```
    #### Exemplo de execução: ####
    
    ![menu1](https://user-images.githubusercontent.com/60747654/128634479-7dece094-b740-4c6a-ab17-10adeacbf297.PNG)
    
	![meenu2](https://user-images.githubusercontent.com/60747654/128634481-4d161bc4-60eb-40c0-ad76-2a637022bda9.PNG)
	
	![par](https://user-images.githubusercontent.com/60747654/128634485-3be64866-a9f8-45c0-a995-157324c078a8.PNG)
		
	![imp](https://user-images.githubusercontent.com/60747654/128634488-41aff163-0242-4ed9-aa42-9992cbacfd36.PNG)
	
	![conc](https://user-images.githubusercontent.com/60747654/128634490-9dd9bf14-cc06-4751-bd55-998e32331174.PNG)

- b) Para a resolução do item b foi reutilizada a estrutura de lista estática do item anterior pelo mesmo motivo: já se sabe o tamanho da estrutura, nesse caso 3 posições, porém foram feitas alterações para atender as questões levantadas no item.
	Foi criada uma ListaB para tal, e um metódo que preenche com números aleatórios entre 1 e 13 as 3 posições da lista.
	```
	void ListB(Listab *l1, Listab *l2){
		int aux1 = 0;

		srand((unsigned)time(NULL));
		while(aux1 != MAXTAMB){
			Item d;
			d.val = rand()%13;
			if(d.val != 0){
				ListBInsert(l1, d);
				aux1++;
			}
		}

		int aux2 = 0;
		while(aux2 != MAXTAMB){
			Item d;
			d.val = rand()%13;
			if(d.val != 0){
				ListBInsert(l2, d);
				aux2++;
			}
		}	
	}
	```
	Criadas as listas, é feito um procedimento para gerar o número randomico a ser subtraído:
	```
		srand((unsigned)time(NULL));
		int random = (rand()%12)+1;
		printf("\n");
		printf("NUMERO RANDOMICO: %d", random);
		printf("\n\n");
	```
	Por fim é chamado o método que executa o jogo:
	```
	void GameB(Listab *l1, Listab *l2, Listab *l3, Listab *l4, int random){
		int result1 = 0;
		int result2 = 0;
		int vet1[3],vet2[3];

		for(int i = l1->first; i < l1->last; i++){
			vet1[i] = random - l1->vet[i].val;
			result1 = result1+(random - l1->vet[i].val);
		}
		for(int i = l2->first; i < l2->last; i++){
			vet2[i] = random - l2->vet[i].val;
			result2 = result2+(random - l2->vet[i].val); 
		}

		for(int i = 0; i < MAXTAMB; i++){
			Item d;
			d.val = vet1[i];
			ListBInsert(l3, d);
		}
		for(int i = 0; i < MAXTAMB; i++){
			Item d;
			d.val = vet2[i];
			ListBInsert(l4, d);
		}

		if(result1 > result2){
			printf("L1 é o ganhador! \n\n");
		}else if(result2 > result1){
			printf("L2 é o ganhador! \n\n");
		}else if(result1 == result2){
			printf("Empate!");
		}
	
		PrintListB(l3,l4);
	}
	```
	#### Exemplo de execução: ####
	![menu1](https://user-images.githubusercontent.com/60747654/128635298-4a251c0b-0874-4a11-919a-e7e60ed5e3e2.PNG)
	
	![menu2](https://user-images.githubusercontent.com/60747654/128635302-c8e63a5c-be40-4fcb-8c89-378080c7d798.PNG)
	
	![game](https://user-images.githubusercontent.com/60747654/128635303-2dcd02e7-6381-4e6c-b5aa-9c706f57df1c.PNG)

	
- c) Para a resolução do item c foi utilizada uma estrutura de lista dinâmica, para tal, foram implementadas 3 listas dinâmicas L1, L2 e L3. Pois cada lista tem seu respectivo item.
	```
		struct Item1{
			char *prd;
    		int qtd;
    		int id;
		};

		struct Item2{
			char *mercado;
    		int idm;
		};

		struct Item3{
    		int pxm[2];
			float valor;
		};	
	``` 
	Por fim foi implementado um método que busca um item e seu respectivo mercado e verifica qual mercado possui o menor preço para o mesmo:
	```
	Block3 *aux;
	Block3 *aux2;
	aux2 = l3->first->prox;
	aux = l3->first->prox;
	while(aux != NULL){
		if(aux->data.pxm[0] == 9){
			Item1 d1;
			d1.id = 9;
			if(aux->data.valor > aux2->data.valor){
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux2->data.valor);
				//printf("%d\n", aux2->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}else{
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux->data.valor);
				//printf("%d\n", aux->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}
		}else if(aux->data.pxm[0] == 8){
			Item1 d1;
			d1.id = 8;
			if(aux->data.valor > aux2->data.valor){
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux2->data.valor);
				//printf("%d\n", aux2->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}else{
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux->data.valor);
				//printf("%d\n", aux->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}
		}
		aux = aux->prox;
	}
	```
	#### Exemplo de execução: ####
	
	![menu1](https://user-images.githubusercontent.com/60747654/128635921-b03c61e0-e3c6-4a96-a142-b3cb4b6152ec.PNG)
	
	![menu2](https://user-images.githubusercontent.com/60747654/128635972-1d8635b0-b5fb-4432-88bf-c9a04d2e51a5.PNG)
	
	![exec](https://user-images.githubusercontent.com/60747654/128635977-b8e31133-32a7-4878-9e54-192c0eeaa07b.PNG)


## Problema 2 - Pilhas ##
### Enunciado ###

É de conhecimento que a estrutura do tipo pilha define regras de manipulação que não podem
ser modificadas e que essas são comumente citadas como ações de PUSH (empilhar) e POP
(desempilhar). Sabendo-se disso e mediante as regras de desenvolvimento já apresentadas
faça:

- a: Escreva um programa que utilize uma pilha para verificar se expressões aritméticas estão
com a parentização correta. O programa deve verificar as expressões para ver se cada
“abre parênteses” tem um “fecha parênteses”. Veja exemplo: 
Correto -> ( ( ) ) – ( ( )( ) ) – ( ) ( ) 
Errado -> ( ( ) – ( ( )( ) ) – ( ) ( ).

- b: Elabore um programa utilizando duas pilhas dinâmicas P1 e P2. O objetivo desse programa é transferir os dados da pilha P1 para P2 mantendo-se a ordem de P1 em P2. Para
tanto, não é permitido a utilização de nenhuma estrutura ou variável auxiliar, apenas um
único ponteiro auxiliar do mesmo tipo utilizado para marcar topo e fundo.

- c: Elabore uma função que receba uma pilha P1 com 20 posições preenchidas por números
inteiros aleatórios entre 1 e 99. Para cada número da pilha, utilize a função totiente de
Euler para encontrar para esse número os co-primos. Mostre-os na tela como resultado
de sua execução.

### Resolução ###

- a) Para a resolução do item a foi utilizada uma estrutura de pilha estática com tamanho máximo de 10 items, a estrutura foi escolhida pela facilidade de trabalhar com um unico valor no tipo Item, no caso um dado do tipo char.
	Por fim foi implementado um método que recebe um vetor de caracteres e verifica se a parentização está balanceada:
	```
	void Verify(char *str, Pilha *p1){

		for(int i = 0; str[i] != '\0'; i++){
			Itemp d;
			d.val = str[i];
			if(str[i] == '('){
				PUSH(p1, d);
			}else if(str[i] == ')'){
				POP(p1, &d);
			}
		}
		for(int i=p1->top-1; i>=p1->base; i--){
			if(p1->base == p1->top){
				printf("Parenteses balanceados!\n");
			}else if(p1->vet[i].val == '('){
				printf("Parenteses Desbalanceados!\n");
				printf("Parenteses que nao se fecham:\n");
				PilhaImprime(p1);
			}
		}	
	}

	```
	#### Exemplo de execução: ####
	Entrada utilizada:
	```
	char str[] = "(())(())(";
	```
	![pilha1](https://user-images.githubusercontent.com/60747654/128637116-b8ec60ed-d627-4ba1-9c01-1a950f2d929c.PNG)

- b) Para a resolução do item b foi implementada uma estrutura de pilha dinâmica. Foram criadas duas pilhas P1 e P2, sendo que P1 foi preenchida por um método
	onde são alocados 10 números aleatórios de 1 a 20:
	```
	srand((unsigned)time(NULL));
		for(int i = 1; i < 11; i++){
			Itempd d;
			d.val = (rand()%20)+1;;
			DPush(&P1, d);
		}
	```
	Por fim foi implementada uma função que apresenta a solução do problema proposto no item, ou seja, com apenas uma variável auxiliar Blockpd * aux os items da pilha P! são movidos para a pilha P2:
	```
	void Transfer(PilhaD *P1, PilhaD *P2){
		Blockpd *aux;
		aux = P1->top;

		DPush(P2, aux->prox->prox->prox->prox->prox->prox->prox->prox->prox->data);
		DPop(P1, &aux->data);
		DPush(P2, aux->prox->prox->prox->prox->prox->prox->prox->prox->data);
		DPop(P1, &aux->prox->data);
		DPush(P2, aux->prox->prox->prox->prox->prox->prox->prox->data);
		DPop(P1, &aux->prox->prox->data);
		DPush(P2, aux->prox->prox->prox->prox->prox->prox->data);
		DPop(P1, &aux->prox->prox->prox->data);
		DPush(P2, aux->prox->prox->prox->prox->prox->data);
		DPop(P1, &aux->prox->prox->prox->prox->data);
		DPush(P2, aux->prox->prox->prox->prox->data);
		DPop(P1, &aux->prox->prox->prox->prox->prox->data);
		DPush(P2, aux->prox->prox->prox->data);
		DPop(P1, &aux->prox->prox->prox->prox->prox->prox->data);
		DPush(P2, aux->prox->prox->data);
		DPop(P1, &aux->prox->prox->prox->prox->prox->prox->prox->data);
		DPush(P2, aux->prox->data);
		DPop(P1, &aux->prox->prox->prox->prox->prox->prox->prox->prox->data);
		DPush(P2, aux->data);
		DPop(P1, &aux->prox->prox->prox->prox->prox->prox->prox->prox->prox->data);
	
	}
	```
	#### Exemplo de execução: ####
	![menupilha](https://user-images.githubusercontent.com/60747654/128637474-f999d554-d7c2-4ff1-a979-a5c696774cfb.PNG)
	
	![exeec](https://user-images.githubusercontent.com/60747654/128637475-82476bd1-9810-49bc-9cc6-d18b101d3851.PNG)

	
- c) Para a resolução do problema proposto no item c foi implementada uma pilha dinâmica, aproveitando a estrutura utilizada no problema anterior. Sendo assim ela foi preenchida com 20 items, cada item com um valor randomico entre 1 e 99:
 	```
		PilhaD p;
		PilhaDVazia(&p);
		srand((unsigned)time(NULL));
		for (int i = 0; i < 20; i++){
			Itempd d;
			d.val = (rand()%99)+1;
			DPush(&p, d);
		}
	```
	Por fim foi criada uma função que calcula o Totiente de Euler:
	```
	void Totient(PilhaD *p){
		const int N = 1e5+2;
		int tot[N];

		for(int i = 0; i < N; i++){
			tot[i] = i;
		} 

		for(int i = 2; i < N; i++){
			if(tot[i] == i){
				for (int j = 2*i; j < N; j+=i){
					tot[j] *= i-1;
					tot[j] /= i;
				}
				tot[i] = i-1;
			}
		}
		Blockpd *aux;
		aux = p->top;
		printf("Totiente: \n");
		while(aux != p->base){
			DPop(p, &aux->data);
			printf("%d\n", tot[aux->data.val]);
			aux = aux->prox;
		}
	
	}
	```
	#### Exemplo de execução: ####
	![menu3](https://user-images.githubusercontent.com/60747654/128637848-801aff33-5feb-42e6-b634-7800f1bafd31.PNG)
	
	![pilha1](https://user-images.githubusercontent.com/60747654/128637849-a10ac6d1-03e2-455b-8be8-f5922dd6df97.PNG)
	
	![pilha2](https://user-images.githubusercontent.com/60747654/128637851-57d84dde-d4dd-4523-95e5-6b7e53c10b19.PNG)
	
## Problema 3 - Filas ##
### Enunciado ###

Uma estrutura baseada em fila tem por definição a regra de sempre remover do início e inserir
novos elementos no final. Sabendo-se disso, vamos praticar a utilização desse conceito nos
seguintes problemas:

- a: Em matemática discreta é muito comum nos depararmos com o conceito de binômio de
Newton. O binômio de Newton fornece os coeficientes da expansão de potência para uma
expressão binomial. Sua missão é criar uma função que receba uma Fila cujas posições
representem expressões binomiais do tipo (x+y)
k e retorne para o usuário uma segunda
fila Fresult com a expansão de cada expressão apresentada. Mostre na tela os resultados,
um por linha.

- b: Atualmente, uma das formas de classificar uma entrada qualquer é observar seus atributos em relação a um conjunto de informações já conhecida. Nesse cenário, vamos considerar que esse conjunto de atributos é do tipo inteiro e com variação de 1 a 99, o que
é verdade também para o conjunto de informações conhecida. A estrutura que guarda
as informações conhecidas é definida pelo seguinte modelo: Cada posição da fila há um
atributo e seu peso por classe. Considere que há 5 classes, logo, teremos um vetor de
5 posições como parte de cada posição da fila. Sabendo-se disso, elabore um procedimento/função que dado uma fila de atributos não classificados seja possível buscar essa
classificação entre as informações disponíveis. Mostre para usuário qual a classe que o dado conjunto faz parte. Para isso, considere que a classe de maior valor corresponde
à classe da fila dada. Nesse sentido, some o valor de classe de cada atributo da fila de
entrada e encontre a classe que no final apresente o maior valor. Mostre essa classe
encontrada como resultado.
### Resolução ###

- a)Para a resolução do problema proposto no item a foi implementada uma estrutura de fila dinâmica, sendo a mesma contendo dois tipos de fila, uma fila para receber os binômios e outra fila para os resultados das expansões dos binômios referentes.
 	Foram implementadas três funções principais para solucionar o problema proposto, são elas: fatorial, combinação e Binomio de Newton.
	A Fila receebe os binomios, após isso é chamada a função que calcula o deseenvolvimento  do binômio de newton e o resultado do desenvolvimento é armazenado em uma fila de resultados.
```
int fat(int n){
    int fatorial = 0;
    for(fatorial = 1; n > 1; n = n - 1){
    fatorial = fatorial * n;
    }
   return fatorial;
}
```
	
```
int combinacao(int n, int p){   
    int c;
    int aux;
    aux = n - p;
    c = fat(n);
    c = c/(fat(p)*fat(aux));
    return c;
}
```

```	
void Binomio(int n, char x, char y, FilaDR *res){

    for(int j = 0; j <= n; j++){
        if(j < n){
            char *str = malloc(sizeof(str));
            sprintf(str, "%d(%c^%d * %c^%d) + ", combinacao(n, j), x,n-j, y, j);
            ItemR r;
            r.result = str;
            EnfileiraRes(res, r);
        }else if(j == n){
            char *str = malloc(sizeof(str));
            sprintf(str, "%d(%c^%d * %c^%d)\n", combinacao(n, j), x,n-j, y, j);
            ItemR r;
            r.result = str;
            EnfileiraRes(res, r);    
        }
    }
}

```
#### Exemplo de execução: ####

![binomio](https://user-images.githubusercontent.com/60747654/128638471-ec27141d-5b9c-4660-83e0-8e9df2f2498d.PNG)

- b) Para resolução do item b foi utilizada a mesma estrutura de fila dinâmica do item aterior, porém foram feitas adaptações na estrutura.
	Neste caso a estrutura foi iniciada com 10 valores randomicos entre 1 e 99.
```
FilaDb f;
FilaBVazia(&f);
srand((unsigned)time(NULL));
for(int i = 0; i < 10; i++){
	Itemfb b;
	b.val = (rand()%99)+1;
	for (int j = 0; j < 5; j++){
                b.peso[j] = (rand()%5)+1;
        }
	EnfileiraB(&f, b);
 }
 
 ```
 Por fim foi implementado um método que mostra a classe de determinado valor de acordo com o atributo de peso.
 
 ```
 void FindClasse(FilaDb *f, Itemfb *d){
    Blockfb *aux;

	aux = f->first->prox;
	while(aux != NULL){
        if(&aux->data == d){
            int max = aux->data.peso[0];
            int classe = 0;
            for (int i = 1; i < 5; i++){
                if(max < aux->data.peso[i]){
                    max = aux->data.peso[i];
                    classe = i;
                }else if(max == aux->data.peso[i]){
                    max = aux->data.peso[i];
                    classe = i;
                }
            }
            printf(" Classe: %d", classe);
            printf("\n");
        }
        aux = aux->prox;
    }
}

 ```
 #### Exemplo de execução: ####
 
 ![menu](https://user-images.githubusercontent.com/60747654/128638930-e6440479-eb8e-4df0-8bd2-d5d0e24092af.PNG)
 
 ![fila](https://user-images.githubusercontent.com/60747654/128638932-b179c3ed-68f4-4ac3-b105-701e225a4135.PNG)
 
 ![class](https://user-images.githubusercontent.com/60747654/128638934-e60f4421-0f9f-4580-b6b1-1efeff9c17cd.PNG)
 
## Problema 4 ##
### Enunciado ###
Como é de conhecimento de todos, as estruturas do tipo lista, pilha e filha formam a base da
estrutura de dados e são amplamente utilizadas como parte de muitos problemas atuais. Sua
função e escolher um problema que utilize as três estruturas, buscando com isso desenvolver
sua solução a partir da implementação de uma aplicação. Relate o que seu problema resolve
e qual a finalidade dele em relação ao problema encontrado/proposto. Para essa missão é
permitido apenas a utilização das estruturas em sua composição dinâmica. Note que o objetivo
é manipular adequadamente as estruturas, então, busque por problemas simples já que a
finalidade está na adequação das estruturas ao problema e não na resolução do mesmo de
forma adequada ou efetiva.

## Situação Proposta: ##

Com a proposta de utilizar as 3 estruturas em um mesmo problema, uma situação adequada e simples para tal seria uma compra em um mercado.
Por exemplo, em um mercado existem vários clientes, neste caso sendo representados por uma estrutura de Lista, cada cliente em uma compras
seleciona um produto e o coloca no carrinho, nesta situação os produtos sendo representados por uma estrutura de pilha, onde para pegar um produto 
no fundo da pilha, é necessário remover os produtos existentes por cima, por fim com o carrinho de compras cheio o cliente entra em uma fila para o caixa, assim 
utilizando a definição da estrutura de fila onde o primeiro a entrar é o primeiro a sair.

## Resolução ##

Empilhando os produtos:
```
prod->produto = "Arroz";
prod->val = 6.99;
prod->id = 1;
PushProd(&p , *prod);
prod->produto = "Feijao";
prod->val = 5.84;
prod->id = 2;
PushProd(&p , *prod);
prod->produto = "Carne";
prod->val = 22.56;
prod->id = 3;
PushProd(&p , *prod);
```
Listando os Clientes:

```
 client->client = "Jorge";
 ClientInsert(&l, *client);
 client->client = "Simoni";
 ClientInsert(&l, *client);
 client->client = "Julia";
 ClientInsert(&l, *client);
 
```

Preenchendo o carrinho do Cliente:

```
client->client = "Jorge";
prod->id = 2;
PopProd(&p, prod);
client->carrinho[0] = prod->id; 
prod->id = 3;
PopProd(&p, prod);
client->carrinho[1] = prod->id; 

```
Colocando o cliente na fila e retirando o mesmo da lista:

```
fla->cliente = "Jorge";
EnfileiraF(&f, *fla);
client->client = "Jorge";
CLRemove(&l, *client);

```




