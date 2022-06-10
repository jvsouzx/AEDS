#include "problema1.h"

void ListA(Lista *par, Lista *imp, Lista *conc){
	int aux1 = 0;

	srand((unsigned)time(NULL));
	while(aux1 != MAXTAM){
		Item d;
		d.val = rand()%99;
		if(d.val % 2 == 0 && d.val != 0){
			ListInsert(par, d);
			aux1++;
		}
	}

	int aux2 = 0;
	while(aux2 != MAXTAM){
		Item d;
		d.val = rand()%99;
		if(d.val % 2 == 1 && d.val != 0){
			ListInsert(imp, d);
			aux2++;
		}
	}

	char str[10];
	int result;
	for(int i = par->first; i < par->last; i++){
		Item c;
		//printf("(%d,%d) \n", par->vet[i].val, imp->vet[i].val);
		sprintf(str, "%d%d",  par->vet[i].val, imp->vet[i].val);
		result = strtol(str, NULL, 10);
		c.val = result;
		ListInsert(conc, c);
	}
}

void GameB(Listab *l1, Listab *l2, Listab *l3, Listab *l4, int random){
	int result1 = 0;
	int result2 = 0;
	int vet1[3],vet2[3];

	for(int i = l1->first; i < l1->last; i++){
		vet1[i] = random - l1->vet[i].val;
		result1 = result1+(random - l1->vet[i].val);
	}
	for(int i = l2->first; i < l2->last; i++){
		vet2[i] = random - l2->vet[i].val;
		result2 = result2+(random - l2->vet[i].val); 
	}

	for(int i = 0; i < MAXTAMB; i++){
		Item d;
		d.val = vet1[i];
		ListBInsert(l3, d);
	}
	for(int i = 0; i < MAXTAMB; i++){
		Item d;
		d.val = vet2[i];
		ListBInsert(l4, d);
	}

	if(result1 > result2){
		printf("L1 é o ganhador! \n\n");
	}else if(result2 > result1){
		printf("L2 é o ganhador! \n\n");
	}else if(result1 == result2){
		printf("Empate!");
	}
	
	PrintListB(l3,l4);
}


void ListC(Lista1 *l1, Lista2 *l2, Lista3 *l3){
	Item1* p1 = malloc(sizeof(Item1));
	Item1* p2 = malloc(sizeof(Item1));
	Item1* p3 = malloc(sizeof(Item1));
	Item1* p4 = malloc(sizeof(Item1));
	Item2* m1 = malloc(sizeof(Item2));
	Item2* m2 = malloc(sizeof(Item2));
	Item2* m3 = malloc(sizeof(Item2));
	Item3* v1 = malloc(sizeof(Item3));
	Item3* v2 = malloc(sizeof(Item3));
	Item3* v3 = malloc(sizeof(Item3));
	Item3* v4 = malloc(sizeof(Item3));
	Item3* v5 = malloc(sizeof(Item3));
	Item3* v6 = malloc(sizeof(Item3));

	p1->prd = "arroz";
	p1->id = 9;
	p1->qtd = 5;
	ListC1Insert(l1, *p1);
	p2->prd = "feijao";
	p2->id = 8;
	p2->qtd = 4;
	ListC1Insert(l1, *p2);
	p3->prd = "batata";
	p3->id = 7;
	p3->qtd = 3;
	ListC1Insert(l1, *p3);
	p4->prd = "cenoura";
	p4->id = 6;
	p4->qtd = 2;
	ListC1Insert(l1, *p4);
	m1->mercado = "ABC";
	m1->idm = 1;
	ListC2Insert(l2, *m1);
	m2->mercado = "BH";
	m2->idm = 2;
	ListC2Insert(l2, *m2);
	m3->mercado = "Rena";
	m3->idm = 3;		
	ListC2Insert(l2, *m3);
	v1->pxm[0] = p1->id;
	v1->pxm[1] = m1->idm;
	v1->valor = 3.1;
	ListC3Insert(l3, *v1);
	v2->pxm[0] = p2->id;
	v2->pxm[1] = m1->idm;
	v2->valor = 2.1;
	ListC3Insert(l3, *v2);
	v3->pxm[0] = p1->id;
	v3->pxm[1] = m2->idm;
	v3->valor = 1.1;
	ListC3Insert(l3, *v3);
	v4->pxm[0] = p2->id;
	v4->pxm[1] = m2->idm;
	v4->valor = 4.1;
	ListC3Insert(l3, *v4);
	v5->pxm[0] = p1->id;
	v5->pxm[1] = m3->idm;
	v5->valor = 5.1;
	ListC3Insert(l3, *v5);
	v6->pxm[0] = p2->id;
	v6->pxm[1] = m3->idm;
	v6->valor = 6.1;
	ListC3Insert(l3, *v6);
	//List1Print(l1);
	//List2Print(l2);
	//List3Print(l3);
	Block3 *aux;
	Block3 *aux2;
	aux2 = l3->first->prox;
	aux = l3->first->prox;
	while(aux != NULL){
		if(aux->data.pxm[0] == 9){
			Item1 d1;
			d1.id = 9;
			if(aux->data.valor > aux2->data.valor){
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux2->data.valor);
				//printf("%d\n", aux2->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}else{
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux->data.valor);
				//printf("%d\n", aux->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}
		}else if(aux->data.pxm[0] == 8){
			Item1 d1;
			d1.id = 8;
			if(aux->data.valor > aux2->data.valor){
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux2->data.valor);
				//printf("%d\n", aux2->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}else{
				List1Search(l1, &d1);
				printf("Preço: %.2f\n", aux->data.valor);
				//printf("%d\n", aux->data.pxm[1]);
				Item2 d2;
				d2.idm = aux2->data.pxm[1];
				List2Search(l2, &d2);
			}
		}
		aux = aux->prox;
	}
}	

void ListMain(){
	int op = 1;
	do
	{	
		printf("-------------------------------------\n");
		printf("-------| PROBLEMA 1 : LISTAS |-------\n");
		printf(" ------|(1) letra a          |-------\n");
		printf(" ------|(2) letra b          |-------\n");
		printf(" ------|(3) letra c          |-------\n");
		printf(" ------|(0) para sair        |-------\n");
		printf("-------------------------------------\n");
		scanf("%d", &op);
		printf("\n\n");

		if(op == 1){
			Lista par;
    		Lista imp;
    		Lista conc;

    		EmptyList(&par);
    		EmptyList(&imp);
    		EmptyList(&conc);

    		ListA(&par, &imp, &conc);
			printf("\n\n");
			printf("Lista Par: \n");
			PrintList(&par);
			printf("\n\n");
			printf("Lista Impar: \n");
			PrintList(&imp);
			printf("\n\n");
			printf("Lista Concatenada: \n");
			PrintList(&conc);
			printf("\n\n");

			op = 0;

		}else if(op == 2){
			Listab l1, l2, l3, l4;

			EmptyListB(&l1);
			EmptyListB(&l2);
			EmptyListB(&l3);
			EmptyListB(&l4);
			ListB(&l1, &l2);
			printf("L1 & L2: \n\n");
			PrintListB(&l1, &l2);

			srand((unsigned)time(NULL));
			int random = (rand()%12)+1;
			printf("\n");
			printf("NUMERO RANDOMICO: %d", random);
			printf("\n\n");

			GameB(&l1, &l2, &l3, &l4, random);

			op = 0;
		}else if(op == 3){
			Lista1 l1;
			Lista2 l2; 
			Lista3 l3;

			EmptyListC(&l1, &l2, &l3);

			ListC(&l1, &l2, &l3);

			op = 0;
		}else if(op == 0){
			printf("Finalizando programa!\n");
		}else{
			printf("Opção inválida! \n");
			printf("Finalizando programa!\n");
			op = 0;	
		}
		
	} while (op != 0);
		
}