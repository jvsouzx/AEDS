#include "btree.h"
#include "file.h"

void menu(){
	printf("        		 (B Tree) 				\n");
	printf("[1] - Carregar a árvore com os dados.   \n");
	printf("[2] - Imprimir árvore.				    \n");
	printf("[3] - Buscar um CPF.					\n");
	//printf("[4] - Cadastrar um CPF.				    \n");
	//printf("[5] - Remover um CPF.					\n");
	printf("[9] - Sair.							    \n");
}

int main(){

	int op = 0;
	Record *r = malloc(sizeof(Record));
  	Pagina *btree = CreateBTree();
	int *min = malloc(sizeof(int)); 
	int *max = malloc(sizeof(int));

	do{
		menu();
		scanf("%d", &op);

		if(op == 1){
			for(int i=1; i<101; i++){
				char *filename = malloc(sizeof(char*));
				sprintf(filename, "./database/data%d.txt", i);
				fileMinMax(filename, min, max);
     			r->key = i;
				r->min = *min;
				r->max = *max; 
				r->fileName = filename; 
     			Insere(&btree, *r);
			}

		}else if(op == 2){
			Imprime(&btree, 0);

		}else if(op == 3){
			int cpf = 0;
			printf("Informe o CPF:");
			scanf("%d", &cpf);
			searchBTree(btree, cpf);

		}else if(op == 4){
			op = 9;
		}else if(op == 5){
			op = 9;
		}else if(op == 9){
			printf("Saindo...\n");

		}else{
			printf("Opção inválida!\n");
			printf("Saindo...\n");

		}
		
	}while(op != 9);

return 0;
}