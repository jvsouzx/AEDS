#include "problema3.h"

int fat(int n){
    int fatorial = 0;
    for(fatorial = 1; n > 1; n = n - 1){
        fatorial = fatorial * n;
    }
    return fatorial;
}

int combinacao(int n, int p){   
    int c;
    int aux;
    aux = n - p;
    c = fat(n);
    c = c/(fat(p)*fat(aux));
    return c;
}

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

void FilaMain(){
    int op; 
    printf("-------------------------------------\n");
	printf("-------| PROBLEMA 3 : FILAS  |-------\n");
	printf(" ------|(1) letra a          |-------\n");
	printf(" ------|(2) letra b          |-------\n");
	printf(" ------|(0) para sair        |-------\n");
	printf("-------------------------------------\n");
	scanf("%d", &op);
	printf("\n\n");

    if(op == 1){
        FilaD f;
        FilaDVazia(&f);
        FilaDR res;
        FilaResVazia(&res);
        int max = 7;
        for(int i = 2; i < max; i++){
            Itemf d;
            d.k = i;
            d.x = 'a';
            d.y = 'b';
            Enfileira(&f, d);   
        }
        FilaDImprime(&f);
        printf("\n");
        Blockf *aux;
        aux = f.first->prox;
        while(aux != NULL){
            Binomio(aux->data.k, aux->data.x, aux->data.y, &res);
            aux = aux->prox;
        }
        FilaResImprime(&res);
        op = 0;
    }else if(op == 2){
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
        FilaBImprime(&f);
        printf("\n");

        Blockfb *aux;
        aux = f.first->prox;

        while(aux != NULL){
            printf("Valor: ");
            printf("%d", aux->data.val);
            FindClasse(&f, &aux->data);	
            aux = aux->prox;
        }        
    }else if(op == 0){
        op = 0;
    }else{
        op = 0;
    }
}   
