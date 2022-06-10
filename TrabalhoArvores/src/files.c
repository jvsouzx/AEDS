#include "files.h"

double rand_float(){
    return ((double)(rand() % 2000000)) / ((double)1000000);
}

bool exist(double values[], int tam, double value){
    for(int i = 0; i < tam; i++){
        if(values[i] == value){
            return true;
        }
    }
    return false;
}

void file1(char *path){
    srand(time(NULL));
    double values[1000];
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        double value;
        for(int i = 0; i < 1000; i++){
            value = rand_float();
            while(exist(values, i, value)){
                value = rand_float();
            }
            values[i] = value;
            fprintf(arq, "%lf\n", value);
        }
    }
    fclose(arq);
}

void file2(char *path){
    srand(time(NULL));
    double values[10000];
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        double value;
        for(int i = 0; i < 10000; i++){
            value = rand_float();
            while(exist(values, i, value)){
                value = rand_float();
            }
            values[i] = value;
            fprintf(arq, "%lf\n", value);
        }
    }
    fclose(arq);
}
    
void file3(char *path){
    srand(time(NULL));
    double values[1000000];
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        double value;
        for(int i = 0; i < 1000000; i++){
            value = rand_float();
            while(exist(values, i, value)){
                value = rand_float();
            }
            values[i] = value;
            fprintf(arq, "%lf\n", value);
        }
    }
    fclose(arq);    
}

void search1(char *path){
    srand(time(NULL));
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        for(int i = 0; i < 5000; i++){
            fprintf(arq, "%lf\n", rand_float());
        }
    }
    fclose(arq); 
}

void search2(char *path){
    srand(time(NULL));
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        for(int i = 0; i < 10000; i++){
            fprintf(arq, "%lf\n", rand_float());
        }
    }
    fclose(arq); 
}

void search3(char *path){
    srand(time(NULL));
    FILE *arq;
    arq = fopen(path, "a");

    if(arq == NULL){
        printf("Erro, arquivo inexistente!\n");
    }else{
        for(int i = 0; i < 100000; i++){
            fprintf(arq, "%lf\n", rand_float());
        }
    }
    fclose(arq); 
}

