# Estrutura de Dados: Árvores

Trabalho proposto para a disciplina de Algoritmos e Estrutura de Dados no CEFET-MG Campus V.

<a href="#intro"> Introdução </a>

<a href="#database"> Criação das Bases de Dados</a>

<a href="#binaria"> Árvore Binária </a>

<a href="#avl"> Árvore AVL </a>

<a href="#rb"> Árvore Rubro Negra </a>

<a href="#compilar"> Compilação </a>

<a href="#analise"> Análise e Conclusão </a>

<a href="#referencias"> Referências </a>

<h2 id="intro"> Introdução </h2>

O presente trabalho consiste na implementação da Árvore Rubro Negra bem como sua comparação com a Árvore Binária e a Árvore AVL.
Para conclusão do trabalho foram preparadas três bases de dados para preencher a estrutura com 1000, 10000 e 1000000 
entradas randômicas e não repetidas, sendo essas do tipo ponto flutuante, e três bases de pesquisa com 1000, 5000 e 100000 
entradas, essas do tipo ponto flutuante podendo conter números únicos e números repetidos.

<h2 id="database"> Criação das Bases de Dados</h2>

Para gerar as bases de dados necessárias no trabalho, foram implementados os códigos a seguir.

Função responsável por gerar os números randômicos do tipo float
```
double rand_float(){
    return ((double)(rand() % 2000000)) / ((double)1000000);
}
```
Função para verificar se um número já existe na base
```
bool exist(double values[], int tam, double value){
    for(int i = 0; i < tam; i++){
        if(values[i] == value){
            return true;
        }
    }
    return false;
}
```

Função que preenche o arquivo da base de dados com números randômicos
```
void file1(char *path){
    srand(time(NULL));
    double values[1000];
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        double value;
        for(int i = 0; i < 1000; i++){
            value = rand_float();
            while(exist(values, i, value)){
                value = rand_float();
            }
            values[i] = value;
            fprintf(arq, "%lf\n", value);
        }
    }
    fclose(arq);
}
```

Função que preenche a base de pesquisa com números randômicos
```
void search1(char *path){
    srand(time(NULL));
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        for(int i = 0; i < 5000; i++){
            fprintf(arq, "%lf\n", rand_float());
        }
    }
    fclose(arq); 
}
```

<h2 id="binaria"> Árvore Binária </h2>

Uma árvore de busca binária consiste em uma árvore binária na qual cada filho de um
vértice é dado como um filho esquerdo ou direito, nenhum vértice possui mais do que um
filho esquerdo ou direito e cada vértice é rotulado com uma chave, que é um dos itens. São
associadas chaves a um vértice de modo que a chave de um vértice é maior que as chaves de
todos os vértices de sua subárvore esquerda quanto menor que as chaves de todos os vértices
de sua subárvore direita.

As funções abaixo foram utilizadas para ler os dados de um arquivo e preencher a estrutura da Árvore Binária
```
void insertBTree(Tree **t, Record r){
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  } else {
    if(r.key < (*t)->reg.key){
      insertBTree(&(*t)->esq, r);
    }
    if(r.key > (*t)->reg.key){
      insertBTree(&(*t)->dir, r);
    }
  }
}

void fillBTree(char *path, Tree **t){
  FILE *file;
  const char s[] = "\n";
  char *tok;
  char linha[1024];
  char *res;
  file = fopen(path, "r");
  if(file == NULL){
    printf("Não foi possível abrir o arquivo!\n");
    return;
  }
  while(!feof(file)){
    Record *rc = malloc(sizeof(Record));
    res = fgets(linha, 1024, file);
    tok = strtok(res, s);
    while(tok != NULL){
      rc->key = strtod(tok, NULL);
      tok = strtok(NULL, s);
    }
    insertBTree(t, *rc);
  }
  fclose(file);
}
```
Para a pesquisa na estrutura foram utilizadas as funções abaixo que fazem a leitura do arquivo de pesquisa e usa os mesmos para buscar os dados em comum, ou seja os dados presentes na estrutura da Árvore Binária

```
void binarySearch(Tree **t, Tree **aux, Record r, int *cont){

  if(*t == NULL){
    *cont+= 1;
    return;
  }

  if((*t)->reg.key > r.key){ binarySearch(&(*t)->esq, aux, r, cont); return;}
  if((*t)->reg.key < r.key){ binarySearch(&(*t)->dir, aux, r, cont); return;}

  *aux = *t;
}

void searchBTree(char *path, Tree **t, Tree **aux, int *cont){
  FILE *file;
  const char s[] = "\n";
  char *tok;
  char linha[1024];
  char *res;

  file = fopen(path, "r");
  if(file == NULL){
    printf("Não foi possível abrir o arquivo!\n");
    return;
  }
  
  while(!feof(file)){
    Record *r = malloc(sizeof(Record));
    res = fgets(linha, 1024, file);
    tok = strtok(res, s);
    while(tok != NULL){
      r->key = strtod(tok, NULL);
      tok = strtok(NULL, s);
    }
    binarySearch(t, aux, *r, cont);
  }
  
  fclose(file);
}
```

<h2 id="avl"> Árvore AVL</h2>

A árvore AVL é uma árvore de busca binária balanceada, a proposta da AVL está em manter as subárvores esquerda e direita com altura 
aproximada, para garantir o balanceamento a AVL calcula o desequilíbrio a partir da profundidade do nó mais distante de cada subárvore.
Caso esse se encontre com um indice de desbalanceamento maior ou igual a 2, a árvore é recomposta por rotações.

As funções abaixo foram utilizadas para ler os dados de um arquivo e preencher a estrutura da Árvore AVL

```
void fillAVLTree(char *path, avTree **t){
	FILE *file;
  	const char s[] = "\n";
  	char *tok;
  	char linha[1024];
  	char *res;

  	file = fopen(path, "r");
  	if(file == NULL){
    	printf("Não foi possível abrir o arquivo!\n");
    	return;
  	}

  	while(!feof(file)){
    	avRecord *rc = malloc(sizeof(avRecord));
    	res = fgets(linha, 1024, file);
    	tok = strtok(res, s);
    	while(tok != NULL){
      		rc->key = strtod(tok, NULL);
      		tok = strtok(NULL, s);
    	}
    	insertTree(t, *rc);
  	}
  	fclose(file);
}

void insertTree(avTree **t, avRecord r){

  if(*t == NULL){
    *t = (avTree*)malloc(sizeof(avTree));
    (*t)->esq    = NULL; 
    (*t)->dir    = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
      if ((getWeight(&(*t)->esq) - getWeight(&(*t)->dir)) == 2){
      	if(r.key < (*t)->esq->reg.key)
      		rotacaoSimplesDireita(t);
      	else
      		rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
      if ((getWeight(&(*t)->dir) - getWeight(&(*t)->esq)) == 2){
      	if(r.key > (*t)->dir->reg.key)
      		rotacaoSimplesEsquerda(t);
      	else
      		rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
}
```

Para garantir o balanceamento da estrutura existem os seguintes métodos

```
int getWeight(avTree **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right){
	if(left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(avTree **t){
	avTree *aux;
	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(avTree **t){
	avTree *aux;
	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->esq), getWeight(&(*t)->dir)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->esq), (*t)->weight) + 1;
	(*t) = aux;
}
```


Para a pesquisa na estrutura foram utilizadas as funções abaixo que fazem a leitura do arquivo de pesquisa e usa os mesmos para buscar os dados em comum, ou seja os dados presentes na estrutura da Árvore AVL

```
void searchAVLTree(char *path, avTree **t, avTree **aux, int *cont){
	FILE *file;
  	const char s[] = "\n";
  	char *tok;
  	char linha[1024];
  	char *res;

  	file = fopen(path, "r");
  	if(file == NULL){
    	printf("Não foi possível abrir o arquivo!\n");
    	return;
  	}

  	while(!feof(file)){
    	avRecord *rc = malloc(sizeof(avRecord));
    	res = fgets(linha, 1024, file);
    	tok = strtok(res, s);
    	while(tok != NULL){
      		rc->key = strtod(tok, NULL);
      		tok = strtok(NULL, s);
    	}
    	pesquisa(t, aux,*rc, cont);
  	}
  	fclose(file);
}

void pesquisa(avTree **t, avTree **aux, avRecord r, int *cont){

	if(*t == NULL){
		*cont+= 1;
		return;
	}

	if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r, cont); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r, cont); return;}

	*aux = *t;
}
```

<h2 id="rb"> Árvore Rubro Negra(Red-Black)</h2>

Uma árvore rubro negra é uma árvore de busca binária com um bit extra de armazenamento por nó: sua cor, ela pode ser VERMELHA ou PRETA. Restringindo as cores dos nós em qualquer caminho simples da raiz até uma folha, as árvores rubro negra asseguram que o comprimento de nenhum desses caminhos seja maior que duas vezes o de
qualquer outro, de modo que a árvore é aproximadamente balanceada.
Cada nó da árvore contém agora os atributos cor, chave, esquerda, direita e p. Se um filho ou o pai de um nó
não existir, o atributo do ponteiro correspondente do nó contém o valor NIL. Trataremos esses valores NIL como se
fossem ponteiros para folhas (nós externos) da árvore de busca binária e os nós normais que portam chaves como nós
internos da árvore.
Uma árvore rubro negra é uma árvore de busca binária que satisfaz as seguintes propriedades:
1. Todo nó é vermelho ou preto.
2. A raiz é preta.
3. Toda folha (NIL) é preta.
4. Se um nó é vermelho, então os seus filhos são pretos.
5. Para cada nó, todos os caminhos simples do nó até folhas descendentes contêm o mesmo número de nós pretos.

As funções abaixo foram utilizadas para ler os dados de um arquivo e preencher a estrutura da Árvore Rubro Negra

```
void fillRBTree(char *path, rbTree **t){
	FILE *file;
  	const char s[] = "\n";
  	char *tok;
  	char linha[1024];
  	char *res;

  	file = fopen(path, "r");
  	if(file == NULL){
    	printf("Não foi possível abrir o arquivo!\n");
    	return;
  	}

  	while(!feof(file)){
    	rbRecord *rc = malloc(sizeof(rbRecord));
    	res = fgets(linha, 1024, file);
    	tok = strtok(res, s);
    	while(tok != NULL){
      		rc->key = strtod(tok, NULL);
          rc->value = strtod(tok, NULL);
      		tok = strtok(NULL, s);
    	}
    	insertRB(t, *rc);
  	}
  	fclose(file);
}
void insert(rbTree **t, rbRecord r){

  if(*t == NULL){
    *t = (rbTree*)malloc(sizeof(rbTree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r;
    (*t)->color = RED; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insert(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insert(&(*t)->dir, r);
    }
  
  }

}

void insertRB(rbTree **t, rbRecord r){
    rbTree *aux;
    insert(t, r);

    while((*t)->parent != NULL && (*t)->parent->color == RED){
        if((*t)->parent == (*t)->parent->parent->dir){
            aux = (*t)->parent->parent->esq;

            if(aux->color == RED){
                aux->color = BLACK;
                (*t)->parent->color = BLACK;
                (*t)->parent->parent->color = RED;
                *t = (*t)->parent->parent;

            } else {

                if((*t) == (*t)->parent->esq){
                    (*t) = (*t)->parent;
                    rightRotate(t);
                }
                (*t)->parent->color = BLACK;
                (*t)->parent->parent->color = RED;
                leftRotate(t);

            }

        } else {
            aux  = (*t)->parent->parent->dir;

            if(aux->color == RED){
                aux->color = BLACK;
                (*t)->parent->color = BLACK;
                (*t)->parent->parent->color = RED;
                *t = (*t)->parent->parent; 
                
            } else {

                if((*t) == (*t)->parent->dir){
                    *t = (*t)->parent;
                    leftRotate(t);
                }
                (*t)->parent->color = BLACK;
                (*t)->parent->parent->color = RED;
                rightRotate(t);
            }
        }
    }
    (*t)->color = BLACK;
}
```

Para garantir que as propriedades da árvore rubro negra sejam respeitadas ao inserir um elemnto existem os seguintes métodos

```
void rightRotate(rbTree **t){
    rbTree *aux;
    aux = (*t)->esq;
    (*t)->esq = aux->dir;
    if(aux->dir != NULL){
        aux->dir->parent = (*t);
    }
    aux->parent = (*t)->parent;
    if((*t)->parent == NULL){
        (*t) = aux;
    } else if((*t) == (*t)->parent->dir){
        (*t)->parent->dir = aux;
    } else {
        (*t)->parent->esq = aux;
    }
    aux->dir = (*t);
    (*t)->parent = aux;
}

void leftRotate(rbTree **t){
    rbTree *aux;
    aux = (*t)->dir;
    (*t)->dir = aux->esq;
    if(aux->esq != NULL){
        aux->esq->parent = (*t);
    }
    aux->parent = (*t)->parent;
    if((*t)->parent == NULL){
        (*t) = aux;
    } else if((*t) == (*t)->parent->esq){
        (*t)->parent->esq = aux;
    } else {
        (*t)->parent->dir = aux;
    }
    aux->esq = (*t);
    (*t)->parent = aux;
}
```

Para a pesquisa na estrutura foram utilizadas as funções abaixo que fazem a leitura do arquivo de pesquisa e usa os mesmos para buscar os dados em comum, ou seja os dados presentes na estrutura da Árvore Rubro Negra

```
void searchRBTree(char *path, rbTree **t, rbTree **aux, int *cont){
	FILE *file;
  	const char s[] = "\n";
  	char *tok;
  	char linha[1024];
  	char *res;

  	file = fopen(path, "r");
  	if(file == NULL){
    	printf("Não foi possível abrir o arquivo!\n");
    	return;
  	}

  	while(!feof(file)){
    	rbRecord *rc = malloc(sizeof(rbRecord));
    	res = fgets(linha, 1024, file);
    	tok = strtok(res, s);
    	while(tok != NULL){
      		rc->key = strtod(tok, NULL);
      		tok = strtok(NULL, s);
    	}
    	rbSearch(t, aux, *rc, cont);
  	}
  	fclose(file);
}

void rbSearch(rbTree **t, rbTree **aux, rbRecord r, int *cont){

  if(*t == NULL){
    *cont+= 1;
    return;
  }

  if((*t)->reg.key > r.key){ rbSearch(&(*t)->esq, aux, r, cont); return;}
  if((*t)->reg.key < r.key){ rbSearch(&(*t)->dir, aux, r, cont); return;}

  *aux = *t;
}
```
<h2 id="compilar"> Compilação e Execução </h2>

Para compilar
```
make clean
make
make run 
```
Após executar os comandos acima o programa irá exibir o menu principal

![1](https://user-images.githubusercontent.com/60747654/146002758-c16396ed-02ef-41e6-993c-147bd1730393.png)

O usuário deve selecionar o tipo de estrutura a ser utilizado. Após selecionada a estrutura, deve ser informado o tamanho da base de dados a ser utilizada no preenchimento

![2](https://user-images.githubusercontent.com/60747654/146002972-11246bd9-9ec5-4f6e-872f-ebc36dc9c2c6.png)

Com a estrutura devidamente preenchida o próximo passo é selecionar uma base de pesquisa 

![3](https://user-images.githubusercontent.com/60747654/146003134-ee847bdb-e647-4bbb-a730-4f20a134ba68.png)

Assim chegando ao final da execução

![4](https://user-images.githubusercontent.com/60747654/146003229-3d38e505-ea7d-4442-b14a-e470e362992b.png)

<h2 id="analise"> Análise, Discussão e Conclusão </h2>

Com a finalidade de analisar o tempo de execução do preenchimento e do método de busca implementados, foi utilizada a função clock da biblioteca <time.h>

Com por exemplo a implementação abaixo no método de preenchimento da árvore binária
```
clock_t begin = clock();
fillRBTree(path1, &rb);
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);
```
O gráfico abaixo apresenta uma comparação do tempo total de inserção em cada estrutura, onde o eixo y representa o tempo em segundos e o eixo x a quantidade de dados, nota-se que o tempo de inserção de todas as estruturas é muito semelhante quando se trata de uma quantidade pequena de dados, como por exemplo, quando utilizadas as bases de 1000 e 10000 dados. Porém quando a quantidade de dados começa a aumentar é possível notar a eficiência das estruturas quanto aos métodos de inserção. Tanto a árvore avl quanto a rubro negra apresentam tempos de inserção maiores do que a árvore binária, pois ambas necessitam de métodos para balanceamento da estrutura para assim não perder suas caractéristicas após a inserção de um novo dado.

![insertion](https://user-images.githubusercontent.com/60747654/146044369-73703478-80ec-4b38-94d5-529d0dceec66.png)

Para a análise do tempo de busca em cada estrutura foi realizado o cálculo da média de tempo de busca em cada estrutura, fazendo a média aritmética do tempo de busca de todas as bases de pesquisa em todas as bases de dados disponíveis, nota-se que o tempo médio da árvore avl e da binária em bases pequenas é bem semelhante, porém em bases de dados maiores a estrutura da AVL é a mais eficiente, pois devido ao seu balanceamento sempre irá apresentar a menor altura possível, fazendo com que a operação de busca mesmo no pior caso (que seria um elemento na folha mais baixa) seja mais rápida.
![search](https://user-images.githubusercontent.com/60747654/146044396-914b7ef5-47a4-45d9-9472-d4f68b34a9a6.png)

A árvore AVL se mostra a estrutura mais eficiente para buscar elementos na base de dados maior e binária na base menor, sendo assim a Rubro Negra seria uma boa opção para trabalhar em uma base mediana de dados, como é possível observar na curva do gráfico acima.

<h2 id="referencias"> Referências </h2>

[Algoritmos - Teoria e Prática 3ªed](https://www.amazon.com.br/Algoritmos-Teoria-Pr%C3%A1tica-Thomas-Cormen/dp/8535236996)

[Matemática Discreta e Suas Aplicações 6ªed](https://www.amazon.com.br/Matemática-Discreta-Aplicações-Kenneth-Rosen/dp/8577260364)
