#include "radix.h"


void Initialize(Vector *v){
	
	//Porque 42? Leia o guia definitivo do mochileiro das galáxias :).
	srand(42); 
    
    v->itens = (int*)malloc(MAXSIZE*sizeof(int));
	for(int i=0; i<MAXSIZE; i++)
		v->itens[i] = rand()%100;
}


void Imprime(Vector *v){
	for(int i=0; i<MAXSIZE; i++)
		printf("%d\t", v->itens[i]);
	printf("\n");
}


int GetDecimal(int value, int exp){
	return (value / exp) % 10;
}


void Contagem(Vector *v, int exp){ 
	int i, j;
	int bucket[10] = { 0 };
	int *aux = (int*)malloc(MAXSIZE*sizeof(int));

	for (i=0; i<MAXSIZE;i++){ 
		j = GetDecimal(v->itens[i], exp);
		bucket[j]++;
  	}
  	
  	for (i=1; i<10; i++)
		bucket[i] += bucket[i-1];
  	
  	for (i=MAXSIZE-1; i>=0; i--){ 
		j = GetDecimal(v->itens[i], exp);
		aux[--bucket[j]] = v->itens[i];
    }
	
	for (i=0; i<MAXSIZE; i++) 
		v->itens[i] = aux[i];

	free(aux);
}


void RadixSort(Vector *v){ 
	int i;
	int maior=0;
	int exp = 1;

	for (i=0; i<MAXSIZE; i++) {
		if (v->itens[i] > maior)
			maior = v->itens[i];
	}

	while(maior/exp > 0){
		Contagem(v, exp);
		Imprime(v);
		exp*=10;
	}

}


