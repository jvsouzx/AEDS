#include "Lista.h"

void EmptyList(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void ListInsert(Lista *l, Item d){
	if (l->last >= MAXTAM){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void PrintList(Lista *l){
    for(int i = l->first; i < l->last; i++){
		printf("%d:%d\t", i,l->vet[i].val);
		printf("\n");
	}
}

void EmptyListB(Listab *l){
	l->first = 0;
	l->last  = 0;
}

void ListBInsert(Listab *l, Item d){
	if (l->last >= MAXTAMB){
		printf("LISTA CHEIA!\n");
	}else{
		l->vet[l->last] = d;
		l->last ++;
	}
}

void PrintListB(Listab *l1, Listab *l2){
    for(int i = l1->first; i < l1->last; i++)
		printf("(%d,%d)\t", l1->vet[i].val, l2->vet[i].val);
	printf("\n");
}

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

void Swap(Item *a, Item *b){
	Item aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void ListBRemove(Listab *l){
	bool ok = false;

	if(l->first == l->last)
		printf("LISTA VAZIA!\n");
	else{
		for(int i=l->first; i<l->last; i++){
			Swap(&l->vet[i], &l->vet[i+1]);
			ok = true;	
		}
		if(ok)
			l->last --;
	}
}