#include "disco.h"

void DiscWrite(char *path, Lista *l){
    FILE *file;
    const char s[] = "A, ";
    char *tok;
    char linha[1024];
    char *res;
    
    file = fopen(path, "r");
    if(file == NULL){
        printf("Não foi possível abrir o arquivo!\n");
        return;
    }
    
    while(!feof(file)){ 
        Item *d = malloc (sizeof(Item));
        int aux = 0; 
        res = fgets(linha, 1024, file);
        tok = strtok(res, s);
        d->ind = atoi(tok);
        //printf("Indice: %d\n", d->ind);   
        while(tok != NULL){
            d->val[aux] = atoi(tok);     
            tok = strtok(NULL, s);
            aux++;
        } 
        ListInsert(l, *d);
    }
    fclose(file);
}

//void DiscRead(int ind, int info, Lista *l){

//}