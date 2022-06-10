#include "list.h"

void ListMake(Lista *l){
    l->first = 0;
    l->last = 0;
}

void ListInsert(Lista *l, Item d){
    l->vet[l->last] = d;
	l->last ++;
}

void Swap(Item *a, Item *b){
	Item aux;
	aux = *a;
	*a  = *b;
	*b  = aux;   
}

void ListRemove(Lista *l, Item d){
    bool ok = false;

	if(l->first == l->last)
		printf("LISTA VAZIA!\n");
	else{
		for(int i=l->first; i<l->last; i++){
            if(l->vet[i].ind == d.ind){
				Swap(&l->vet[i], &l->vet[i+1]);
				ok = true;	
			}
        }
		if(ok)
		    l->last --;
	}
}

void ListPrint(Lista *l){
    for(int i=l->first; i<l->last; i++){
        for(int j = 0;j < 11;j++)
            printf("%d\t", l->vet[i].val[j]);
        printf("\n");
    }
}

void procPrint(Lista *l){
    for(int i=l->first; i<l->last; i++){
        for(int j = 0;j < 50;j++)
            printf("%d\t", l->vet[i].proc[j]);
        printf("\n");
    }
}