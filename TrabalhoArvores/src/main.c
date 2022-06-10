#include "files.h"
#include "binary.h"
#include "avl.h"
#include "rb.h"

void menu(){
    printf(" ---------------------------------------------- \n");
    printf("|       Algoritmos e Estrutura de Dados        |\n");
    printf("|   Trabalho sobre estruturas do tipo árvore   |\n");
    printf("| Para prosseguir informe a estrutura desejada |\n");
    printf("| 1 - Árvore Binária                           |\n");
    printf("| 2 - Árvore AVL                               |\n");
    printf("| 3 - Árvore Rubro Negra (Red-Black)           |\n");
    printf("| 9 - Exit                                     |\n");
    printf(" ---------------------------------------------- \n");
}

int main(){
    int op = 0;
    
    do{
        menu();
        scanf("%d", &op);

        if(op == 1){
            binaryMain();
            op = 9;

        }else if(op == 2){
            avlMain();
            op = 9;

        }else if(op == 3){
            rbMain();
            op = 9;

        }else{
            op = 9;
        }

    }while(op != 9);
    
return 0;    
}