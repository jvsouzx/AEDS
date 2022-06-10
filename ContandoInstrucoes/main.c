#include "matriz.h"

int main(){
    int n = 0;
    int soma;
    printf("Informe o N:\n");
    scanf("%d", &n);
    printf("\n");
    int matriz[n][n];
    InitMatriz(n, matriz);
    printf("Matriz NxN:\n");
    PrintMatriz(n, matriz);
    soma = Game(n, matriz);
    printf("Caminho realizado:\n");
    PrintMatriz(n, matriz);
    printf("\n\nSOMA: %d\n\n", soma);

    return 0;
}