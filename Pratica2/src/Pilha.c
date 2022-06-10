#include "Pilha.h"

void PilhaVazia(Pilha *p){
	p->top   = 0;
	p->base  = 0;
}

void PUSH(Pilha *p, Itemp d){
	if (p->top >= MAXTAMP){
		printf("PILHA CHEIA!\n");
	}else{
		p->vet[p->top] = d;
		p->top ++;
	}
}

void POP(Pilha *p, Itemp *d){
	if(p->base == p->top)
		printf("PILHA VAZIA!\n");
	else{
		p->top --;
	 	*d = p->vet[p->top];
	}
}

void PilhaImprime(Pilha *p){
	for(int i=p->top-1; i>=p->base; i--)
		printf("%c\n", p->vet[i].val);
	printf("\n");
}