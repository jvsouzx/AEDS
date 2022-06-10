#include "ListaC.h"

void EmptyListC(Lista1 *l1, Lista2 *l2, Lista3 *l3){
	l1->first = (Block1*) malloc (sizeof(Block1));
	l1->last  = l1->first;
	l1->first->prox = NULL;

	l2->first = (Block2*) malloc (sizeof(Block2));
	l2->last  = l2->first;
	l2->first->prox = NULL;

	l3->first = (Block3*) malloc (sizeof(Block3));
	l3->last  = l3->first;
	l3->first->prox = NULL;
}

void ListC1Insert(Lista1 *l1, Item1 d1){
	l1->last->prox = (Block1*) malloc (sizeof(Block1));
	l1->last = l1->last->prox;
	l1->last->data = d1;
	l1->last->prox = NULL;
}

void ListC2Insert(Lista2 *l2, Item2 d2){
	l2->last->prox = (Block2*) malloc (sizeof(Block2));
	l2->last = l2->last->prox;
	l2->last->data = d2;
	l2->last->prox = NULL;
}

void ListC3Insert(Lista3 *l3, Item3 d3){
	l3->last->prox = (Block3*) malloc (sizeof(Block3));
	l3->last = l3->last->prox;
	l3->last->data = d3;
	l3->last->prox = NULL;
}

void List1Print(Lista1 *l1){
	Block1 *aux;

	aux = l1->first->prox;
	while(aux != NULL){
		printf("Produto: %s\n", aux->data.prd);
		printf("ID: %d\n", aux->data.id);
		printf("Quantidade: %d\n", aux->data.qtd);
		aux = aux->prox;
	}
}

void List1Search(Lista1 *l1, Item1 *d1){
	Block1 *aux;

	aux = l1->first->prox;
	while(aux != NULL){
		if(aux->data.id == d1->id){
			printf("Produto: %s\n", aux->data.prd);
			printf("ID: %d\n", aux->data.id);
			printf("Quantidade: %d\n", aux->data.qtd);
		}
		aux = aux->prox;
	}
}

void List2Print(Lista2 *l2){
	Block2 *aux;

	aux = l2->first->prox;
	while(aux != NULL){
		printf("Mercado: %s\n", aux->data.mercado);
		printf("ID: %d\n", aux->data.idm);
		aux = aux->prox;
	}
}

void List2Search(Lista2 *l2, Item2 *d2){
	Block2 *aux;

	aux = l2->first->prox;
	while(aux != NULL){
		if(aux->data.idm == d2->idm){
			printf("Mercado: %s\n", aux->data.mercado);
			printf("ID: %d\n", aux->data.idm);
		}
		aux = aux->prox;
	}
}

void List3Print(Lista3 *l3){
	Block3 *aux;

	aux = l3->first->prox;
	while(aux != NULL){
		printf("PxM: %d,%d\n", aux->data.pxm[0], aux->data.pxm[1]);
		printf("Valor: %.2f\n", aux->data.valor);
		aux = aux->prox;
	}
}