#include "PilhaD.h"

void PilhaDVazia(PilhaD *p){
	p->base = (Blockpd*) malloc (sizeof(Blockpd));
	p->top  = p->base;
	p->base->prox = NULL;
}

void DPush(PilhaD *p, Itempd d){
	Blockpd *aux = (Blockpd*) malloc (sizeof(Blockpd));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void DPop(PilhaD *p, Itempd *d){
	Blockpd *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
}

void PilhaDImprime(PilhaD *p){
	Blockpd *aux;

	aux = p->top;
	while(aux != p->base){
		printf("%d\n", aux->data.val);
		aux = aux->prox;
	}
}
