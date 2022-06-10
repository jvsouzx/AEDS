#include "problema1.h"
#include "problema2.h"
#include "problema3.h"
#include "problema4.h"

int main(){
    int op = 1;
    do{
        printf("-------------------------------------\n");
		printf("-------|      PRATICA 2      |-------\n");
		printf(" ------|(1) Listas           |-------\n");
		printf(" ------|(2) Pilhas           |-------\n");
		printf(" ------|(3) Filas            |-------\n");
        printf(" ------|(4) Problema 4       |-------\n");
		printf(" ------|(0) para sair        |-------\n");
		printf("-------------------------------------\n");
		scanf("%d", &op);
		printf("\n\n");

        if(op == 1){
            ListMain();
            op = 0;
        }else if(op == 2){
            PilhaMain();
            op = 0;
        }else if(op == 3){
            FilaMain();
            op = 0;
        }else if(op == 4){
            problema4();
            op = 0;
        }
    } while (op != 0);

    return 0;
}