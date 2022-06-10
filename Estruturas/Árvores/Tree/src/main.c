#include "tree.h"

int main(){
	int reg[] = {5,3,7,2,4,6,1};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;

	printf("ELEMENTOS DA ARVORE: { ");
  for(int i=0; i< 7; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
    printf("%d ", reg[i]);
	}
  printf("}\n\n");

	printf("METODO PREORDEM: { ");
  preordem(raiz);
  printf("}\n\n");


  printf("METODO CENTRAL: { ");
  central(raiz);
	printf("}\n\n");

  printf("METODO POSORDEM: { ");
  posordem(raiz);
  printf("}\n\n");


	r.key = 2;
	pesquisa(&raiz, &aux, r);
	
	printf("PESQUISA 2 E IMPRIME A SUBARVORE { ");
	central(aux);
	printf("}\n\n");

	r.key = 3;
	removeTree(&raiz, r);

	printf("REMOVE 3 E IMPRIME A ARVORE { ");
	central(raiz);
	printf("}\n\n");

}