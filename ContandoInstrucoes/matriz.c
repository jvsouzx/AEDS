#include "matriz.h"

void InitMatriz(int n, int matriz[n][n]){
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = rand()%99;
        }
    }
}

void PrintMatriz(int n, int matriz[n][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int Game(int n, int matriz[n][n]){
    int soma;
    int i = 0;
    int j = 0;
    soma = matriz[0][0];
    matriz[0][0] = -1;

    while(i < n && j < n){
        if(j == 0 && i < (n-1)){
            if((matriz[i][j+1] >= matriz[i+1][j]) && (matriz[i][j+1] != -1)){
                j++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
            }else{
                i++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
            }
        }else if(i == (n-1)){
            j++;
            soma += matriz[i][j];
            matriz[i][j] = -1;
        }else if(j == n-1){
            if((matriz[i][j-1] >= matriz[i+1][j]) && (matriz[i][j-1] != -1)){
                j--;
                soma += matriz[i][j];
                matriz[i][j] = -1;
            }else{
                i++;
                soma += matriz[i][j];
                matriz[i][j] = -1;
            }
        }else{
            if(matriz[i][j+1] == -1){
                if(matriz[i+1][j] >= matriz[i][j-1]){
                    i++;
                    soma += matriz[i][j];
                    matriz[i][j] = -1;
                }else{
                    j--;
                    soma += matriz[i][j];
                    matriz[i][j] = -1;
                }
            }else if(matriz[i][j-1] == -1){
                if(matriz[i+1][j] >= matriz[i][j+1]){
                    i++;
                    soma += matriz[i][j];
                    matriz[i][j] = -1;
                }else{
                    j++;
                    soma += matriz[i][j];
                    matriz[i][j] = -1;
                }
            }else{
                if((matriz[i+1][j] >=  matriz[i][j+1]) && (matriz[i+1][j] >= matriz[i][j-1])){
                    i++;
                    soma += matriz[i][j];
                    matriz[i][j] = -1;
                }else if((matriz[i][j+1] >= matriz[i+1][j]) && (matriz[i][j+1] >= matriz[i][j-1])){
                    j++;
                    soma += matriz[i][j];
                    matriz[i][j] = -1;
                }else if((matriz[i][j-1] >= matriz[i+1][j]) && (matriz[i][j-1] >= matriz[i][j+1])){
                    j--;
                    soma += matriz[i][j];
                    matriz[i][j] = -1;
                }
            }
        }
    }
    return soma;
}