#include "memoria.h"

int NumProcess(char *path, int numP){
    FILE *file;
    const char s[] = "P";
    char *tok;
    char linha[1024];
    char *res;
    
    file = fopen(path, "r");
    if(file == NULL){
        printf("Não foi possível abrir o arquivo!\n");
    }
    
    while(!feof(file)){ 
        res = fgets(linha, 1024, file);
        tok = strtok(res, s);
          
        while(tok != NULL){
            tok = strtok(NULL, s);
        } 
        numP++;
    }
    fclose(file);

    return numP;
}

void InitMemory(int numP, int memory[numP][MAX]){
    for (int i = 0; i < numP; i++){
        for (int j = 0; j < MAX; j++){
            memory[i][j] = 0;
        }
    }
}

void InitSwap(int numP, int swap[numP][MAXSWAP]){
    for (int i = 0; i < numP; i++){
        for (int j = 0; j < MAX; j++){
            swap[i][j] = 0;
        }
    }
}

void ExecProcess(char *path, Lista *p/*, int numP,int memory[numP][MAX], int swap[numP][MAXSWAP]*/){
    FILE *file;
    //const char s[] = "P";
    const char s1[] = "PA<,0>";
    char *tok;
    char linha[1024];
    char *res;
 
    file = fopen(path, "r");
    if(file == NULL){
        printf("Não foi possível abrir o arquivo!\n");
    }
    
    while(!feof(file)){
        Item *d = malloc (sizeof(Item)); 
        int aux = 0;
        res = fgets(linha, 1024, file);
        tok = strtok(res, s1);
        d->ind = atoi(tok);
        while(tok != NULL){  
            d->proc[aux] = atoi(tok);
            tok = strtok(NULL, s1);
            aux++;
        }
        ListInsert(p, *d);
    }
    fclose(file);
}


