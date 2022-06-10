#include "FilaD.h"


void FilaDVazia(FilaD *f){
	f->first = (Blockf*) malloc (sizeof(Blockf));
	f->last  = f->first;
	f->first->prox = NULL;
}

void Enfileira(FilaD *f, Itemf d){
	f->last->prox = (Blockf*) malloc (sizeof(Blockf));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(FilaD *f, Itemf *d){
	Blockf *aux;

	if(f->first == f->last || f == NULL || f->first->prox == NULL){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first;
	f->first = f->first->prox;
	d->k   = aux->data.k;
    d->x   = aux->data.x;
    d->y   = aux->data.y;
	free(aux);
}


void FilaDImprime(FilaD *f){
	Blockf *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("(%c+%c)^%d\n", aux->data.x, aux->data.y, aux->data.k);
		aux = aux->prox;
	}

}

void FilaResVazia(FilaDR *f){
	f->first = (BlockR*) malloc (sizeof(BlockR));
	f->last  = f->first;
	f->first->prox = NULL;
}

void EnfileiraRes(FilaDR *f, ItemR d){
	f->last->prox = (BlockR*) malloc (sizeof(BlockR));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void FilaResImprime(FilaDR *f){
	BlockR *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%s", aux->data.result);
		aux = aux->prox;
	}
}

void FilaBVazia(FilaDb *f){
	f->first = (Blockfb*) malloc (sizeof(Blockfb));
	f->last  = f->first;
	f->first->prox = NULL;
}

void EnfileiraB(FilaDb *f, Itemfb d){
	f->last->prox = (Blockfb*) malloc (sizeof(Blockfb));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void FilaBImprime(FilaDb *f){
	Blockfb *aux;

	aux = f->first->prox;
	while(aux != NULL){
		printf("\n");
		printf("Atributo:\n");
		printf("%d\n", aux->data.val);
		printf("Vetor Peso:\n");
		for(int i = 0; i < 5; i++)
			printf("%d\t", aux->data.peso[i]);
		printf("\n");
		aux = aux->prox;
	}
}