#include "binary.h"

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

Tree* CreateBTree(){
	return NULL;
}

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

void binarySearch(Tree **t, Tree **aux, Record r, int *cont){

  if(*t == NULL){
    *cont+= 1;
    return;
  }

  if((*t)->reg.key > r.key){ binarySearch(&(*t)->esq, aux, r, cont); return;}
  if((*t)->reg.key < r.key){ binarySearch(&(*t)->dir, aux, r, cont); return;}

  *aux = *t;
}

void binaryPreordem(Tree *t){
  if(!(t == NULL)){
    printf("%lf\t", t->reg.key);
    binaryPreordem(t->esq); 
    binaryPreordem(t->dir); 
  }
}

void binaryCentral(Tree *t){
  if(!(t == NULL)){
    binaryCentral(t->esq); 
    printf("%lf\t", t->reg.key);
    binaryCentral(t->dir); 
  }
}

void binaryPosordem(Tree *t){
  if(!(t == NULL)){
    binaryPosordem(t->esq); 
    binaryPosordem(t->dir); 
    printf("%lf\t", t->reg.key);
  }
}

void binaryMain(){
  Tree *binary = CreateBTree();
  Tree *aux = CreateBTree();
  int *cont = malloc(sizeof(cont));
  *cont = 0;
  int data = 0;
  printf(" ---------------------------------------------- \n");
  printf("| Informe a base de dados desejada para        |\n");
  printf("| preencher a estrutura da Árvore Binária      |\n");
  printf("| 1 - 1000                                     |\n");
  printf("| 2 - 10000                                    |\n");
  printf("| 3 - 1000000                                  |\n");
  printf(" ---------------------------------------------- \n");
  scanf("%d", &data);

  if (data == 1){
    clock_t begin = clock();
    fillBTree(path1, &binary);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);

  }
  else if (data == 2){
    clock_t begin = clock();
    fillBTree(path2, &binary);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);

  }else if (data == 3){
    clock_t begin = clock();
    fillBTree(path3, &binary);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);

  } else {
    printf("Opção inválida!\n");
  }

  int search = 0;
  printf(" ---------------------------------------------- \n");
  printf("| Informe a base de dados desejada para        |\n");
  printf("| pesqquisar na estrutura da Árvore Binária    |\n");
  printf("| 1 - 5000                                     |\n");
  printf("| 2 - 10000                                    |\n");
  printf("| 3 - 100000                                   |\n");
  printf(" ---------------------------------------------- \n");
  scanf("%d", &search);

  if (search == 1){
    clock_t begin = clock();
    searchBTree(path4, &binary, &aux, cont);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
    printf("%d números não foram encontrados!\n", *cont);

  }else if (search == 2){
    clock_t begin = clock();
    searchBTree(path5, &binary, &aux, cont);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
    printf("%d números não foram encontrados!\n", *cont);

  } else if (search == 3){
    clock_t begin = clock();
    searchBTree(path6, &binary, &aux, cont);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
    printf("%d números não foram encontrados!\n", *cont);

  }else{
    printf("Opção inválida!\n");
  }
}
