#include "disco.h"
#include "memoria.h"

#define PATH "arquivos/arquivos_exemplo.txt"
#define PATH2 "arquivos/processos_exemplo.txt"

int main(){
    int opcao = 1;
    do{
        printf("--------------<MENU>--------------\n\n");
        printf("<1> Para carregar o disco!\n");
        printf("<2> Para executar os processos!\n");
        printf("<0> Para finalizar o programa!\n");
        printf("----------------------------------\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            Lista disco;
            ListMake(&disco);
            DiscWrite(PATH, &disco);
        }

        if(opcao == 2){
            Lista p;
            ListMake(&p);
            int numP = 0;
            int Processos = 0;
            Processos = NumProcess(PATH2, numP);
            int swap[Processos][MAXSWAP];
            int memory[Processos][MAX];
            InitMemory(Processos, memory);    
            InitSwap(Processos, swap);
            ExecProcess(PATH2, &p);
        }

        if(opcao == 0){
            printf("FIM!\n");
        }
        
    } while (opcao != 0);
    
    
    // ListPrint(&disco);
    // printf("\n");

    // Item *d = malloc(sizeof(Item));
    // d->ind = l.vet[0].ind;

    // listRemove(&l, *d);
    // listPrint(&l);

    // for(int j =0; j < 11;j++){
    //     printf("%d\t",d->val[j]);
    // }
   
    

    return 0;
}



