#include "rb.h"

rbTree* CreateRBTree(){
	return NULL;
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

void rbSearch(rbTree **t, rbTree **aux, rbRecord r, int *cont){

  if(*t == NULL){
    *cont+= 1;
    return;
  }

  if((*t)->reg.key > r.key){ rbSearch(&(*t)->esq, aux, r, cont); return;}
  if((*t)->reg.key < r.key){ rbSearch(&(*t)->dir, aux, r, cont); return;}

  *aux = *t;
}

void rbPreordem(rbTree *t){
  if(!(t == NULL)){
    printf("%lf\t", t->reg.key);
    rbPreordem(t->esq); 
    rbPreordem(t->dir); 
  }
}

void rbCentral(rbTree *t){
  if(!(t == NULL)){
    rbCentral(t->esq); 
    printf("%lf\t", t->reg.key);
    rbCentral(t->dir); 
  }
}

void rbPosordem(rbTree *t){
  if(!(t == NULL)){
    rbPosordem(t->esq); 
    rbPosordem(t->dir); 
    printf("%lf\t", t->reg.key);
  }
}

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

void rbMain(){
    rbTree *rb = CreateRBTree();
    rbTree *aux = CreateRBTree();
    int *contrb = malloc(sizeof(contrb));
    *contrb = 0;
    int data = 0;

    printf(" ---------------------------------------------- \n");
    printf("| Informe a base de dados desejada para        |\n");
    printf("| preencher a estrutura da Árvore Rubro Negra  |\n");
    printf("| 1 - 1000                                     |\n");
    printf("| 2 - 10000                                    |\n");
    printf("| 3 - 1000000                                  |\n");
    printf(" ---------------------------------------------- \n");
    scanf("%d", &data);

    if(data == 1){
        clock_t begin = clock();
        fillRBTree(path1, &rb);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);
            
    }else if(data == 2){
        clock_t begin = clock();
        fillRBTree(path2, &rb);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);

    }else if(data == 3){
        clock_t begin = clock();
        fillRBTree(path3, &rb);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo gasto para preencher a estrutura: %lf\n", time_spent);

    }else{
        printf("Opção inválida!\n");
    }

    int search = 0;
    printf(" ---------------------------------------------- \n");
    printf("| Informe a base de dados desejada para        |\n");
    printf("| pesquisar na estrutura da Árvore Rubro Negra |\n");
    printf("| 1 - 5000                                     |\n");
    printf("| 2 - 10000                                    |\n");
    printf("| 3 - 100000                                   |\n");
    printf(" ---------------------------------------------- \n");
    scanf("%d", &search);

    if(search == 1){
        clock_t begin = clock();
        searchRBTree(path4, &rb, &aux, contrb);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
        printf("%d números não foram encontrados!\n", *contrb);

    }else if(search == 2){
        clock_t begin = clock();
        searchRBTree(path5, &rb, &aux, contrb);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
        printf("%d números não foram encontrados!\n", *contrb);

    }else if(search == 3){
        clock_t begin = clock();
        searchRBTree(path6, &rb, &aux, contrb);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo gasto para pesquisar na estrutura: %lf\n", time_spent);
        printf("%d números não foram encontrados!\n", *contrb);

    }else{
        printf("Opção inválida!\n");
    }
}