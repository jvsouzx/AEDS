#include "problema2.h"

void Verify(char *str, Pilha *p1){

	for(int i = 0; str[i] != '\0'; i++){
		Itemp d;
		d.val = str[i];
		if(str[i] == '('){
			PUSH(p1, d);
		}else if(str[i] == ')'){
			POP(p1, &d);
		}
	}
	for(int i=p1->top-1; i>=p1->base; i--){
		if(p1->base == p1->top){
			printf("Parenteses balanceados!\n");
		}else if(p1->vet[i].val == '('){
			printf("Parenteses Desbalanceados!\n");
			printf("Parenteses que nao se fecham:\n");
			PilhaImprime(p1);
		}
	}	
}

void Transfer(PilhaD *P1, PilhaD *P2){
	Blockpd *aux;
	aux = P1->top;

	DPush(P2, aux->prox->prox->prox->prox->prox->prox->prox->prox->prox->data);
	DPop(P1, &aux->data);
	DPush(P2, aux->prox->prox->prox->prox->prox->prox->prox->prox->data);
	DPop(P1, &aux->prox->data);
	DPush(P2, aux->prox->prox->prox->prox->prox->prox->prox->data);
	DPop(P1, &aux->prox->prox->data);
	DPush(P2, aux->prox->prox->prox->prox->prox->prox->data);
	DPop(P1, &aux->prox->prox->prox->data);
	DPush(P2, aux->prox->prox->prox->prox->prox->data);
	DPop(P1, &aux->prox->prox->prox->prox->data);
	DPush(P2, aux->prox->prox->prox->prox->data);
	DPop(P1, &aux->prox->prox->prox->prox->prox->data);
	DPush(P2, aux->prox->prox->prox->data);
	DPop(P1, &aux->prox->prox->prox->prox->prox->prox->data);
	DPush(P2, aux->prox->prox->data);
	DPop(P1, &aux->prox->prox->prox->prox->prox->prox->prox->data);
	DPush(P2, aux->prox->data);
	DPop(P1, &aux->prox->prox->prox->prox->prox->prox->prox->prox->data);
	DPush(P2, aux->data);
	DPop(P1, &aux->prox->prox->prox->prox->prox->prox->prox->prox->prox->data);
	
}

void Totient(PilhaD *p){
	const int N = 1e5+2;
	int tot[N];

	for(int i = 0; i < N; i++){
		tot[i] = i;
	} 

	for(int i = 2; i < N; i++){
		if(tot[i] == i){
			for (int j = 2*i; j < N; j+=i){
				tot[j] *= i-1;
				tot[j] /= i;
			}
			tot[i] = i-1;
		}
	}
	Blockpd *aux;
	aux = p->top;
	printf("Totiente: \n");
	while(aux != p->base){
		DPop(p, &aux->data);
		printf("%d\n", tot[aux->data.val]);
		aux = aux->prox;
	}
	
}

void PilhaMain(){
    int op = 1;
	do{
        printf("-------------------------------------\n");
		printf("-------| PROBLEMA 2 : PILHAS |-------\n");
		printf(" ------|(1) letra a          |-------\n");
		printf(" ------|(2) letra b          |-------\n");
		printf(" ------|(3) letra c          |-------\n");
		printf(" ------|(0) para sair        |-------\n");
		printf("-------------------------------------\n");
		scanf("%d", &op);
		printf("\n\n");

        if(op == 1){
			Pilha p1;
    		PilhaVazia(&p1);
            char str[] = "(())(())(";
            Verify(str, &p1);
            op = 0;
        }else if(op == 2){
			PilhaD P1;
			PilhaD P2;
			PilhaDVazia(&P1);
			PilhaDVazia(&P2);
			srand((unsigned)time(NULL));
			for(int i = 1; i < 11; i++){
				Itempd d;
				d.val = (rand()%20)+1;;
				DPush(&P1, d);
			}
			printf("ANTES\n");
			printf("P1: \n");
			PilhaDImprime(&P1);
			printf("\n");
			printf("P2: \n");
			PilhaDImprime(&P2);
			printf("\n");
			Transfer(&P1, &P2);
			printf("DEPOIS\n");
			printf("P1: \n");
			PilhaDImprime(&P1);
			printf("\n");
			printf("P2: \n");
			PilhaDImprime(&P2);
			printf("\n");

            op = 0;
        }else if(op == 3){
			PilhaD p;
			PilhaDVazia(&p);
			srand((unsigned)time(NULL));
			for (int i = 0; i < 20; i++){
				Itempd d;
				d.val = (rand()%99)+1;
				DPush(&p, d);
			}
			printf("Pilha: \n");
			PilhaDImprime(&p);
			printf("\n\n");
			Totient(&p);
			
            op = 0;
        }else if(op == 0){
            op = 0;
        }
    }while(op != 0);
}