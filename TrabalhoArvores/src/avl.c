#include "avl.h"

avTree* CreateTree(){
	return NULL;
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


void pesquisa(avTree **t, avTree **aux, avRecord r, int *cont){

	if(*t == NULL){
		*cont+= 1;
		return;
	}

	if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r, cont); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r, cont); return;}

	*aux = *t;
}

void preordem(avTree *t){
  if(!(t == NULL)){
    printf("%lf\t", t->reg.key);
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(avTree *t){
  if(!(t == NULL)){
    central(t->esq); 
    printf("%lf\t", t->reg.key);
    central(t->dir); 
  }
}

void posordem(avTree *t){
  if(!(t == NULL)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%lf\t", t->reg.key);
  }
}


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

void rotacaoDuplaDireita(avTree **t){
	rotacaoSimplesEsquerda(&(*t)->esq);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(avTree **t){
	rotacaoSimplesDireita(&(*t)->dir);
	rotacaoSimplesEsquerda(t);
}

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

void avlMain(){
	avTree *avl = CreateTree();
	avTree *aux = CreateTree();
	int *contav = malloc(sizeof(contav));
	*contav = 0;
	int data = 0;

	printf(" ---------------------------------------------- \n");
	printf("| Informe a base de dados desejada para        |\n");
	printf("| preencher a estrutura da Árvore AVL          |\n");
	printf("| 1 - 1000                                     |\n");
	printf("| 2 - 10000                                    |\n");
	printf("| 3 - 1000000                                  |\n");
	printf(" ---------------------------------------------- \n");
	scanf("%d", &data);

	if (data == 1){
		clock_t begin = clock();
		fillAVLTree(path1, &avl);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);
		
	}else if (data == 2){
		clock_t begin = clock();
		fillAVLTree(path2, &avl);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);

	}else if (data == 3){
		clock_t begin = clock();
		fillAVLTree(path3, &avl);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);

	}else{
		printf("Opção inválida!\n");
	}

	int search = 0;
	printf(" ---------------------------------------------- \n");
	printf("| Informe a base de dados desejada para        |\n");
	printf("| pesquisar na estrutura da Árvore AVL         |\n");
	printf("| 1 - 5000                                     |\n");
	printf("| 2 - 10000                                    |\n");
	printf("| 3 - 100000                                   |\n");
	printf(" ---------------------------------------------- \n");
	scanf("%d", &search);

	if(search == 1){
		clock_t begin = clock();
		searchAVLTree(path4, &avl, &aux, contav);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
		printf("%d números não foram encontrados!\n", *contav);

	} else if (search == 2){
		clock_t begin = clock();
		searchAVLTree(path5, &avl, &aux, contav);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
		printf("%d números não foram encontrados!\n", *contav);

	} else if (search == 3){
		clock_t begin = clock();
		searchAVLTree(path6, &avl, &aux, contav);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
		printf("%d números não foram encontrados!\n", *contav);

	} else {

		printf("Opção inválida!\n");

	}
}