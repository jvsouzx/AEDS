#include "file.h"

void fileMinMax(char *path, int *min, int *max){
	FILE *file;
	file = fopen(path, "r");
	char linha[200];
	char *res;
	char *tok;
	const char s[] = ",\n";
	tok = strtok(fgets(linha, 100, file), s);
	*min = atoi(tok);

	if(file == NULL){
		printf("ERRO");
	} else {
		while(!feof(file)){
			res = fgets(linha, 100, file);
			tok = strtok(res, s);
			if(atoi(tok) >= *max ){
				*max = atoi(tok);
			}
			while(tok != NULL){
				tok = strtok(NULL,s);
			}
		}
	}

	fclose(file);
}

void searchInFile(char *path, int src){
    FILE *file;
	file = fopen(path, "r");
	char linha[200];
	char *res;
	char *tok;
	const char s[] = ",\n";

	if(file == NULL){
		printf("ERRO");
	} else {
		while(!feof(file)){
			res = fgets(linha, 100, file);
			tok = strtok(res, s);
            if(src == atoi(tok)){
                printf("CPF: %s\t", res);
				tok = strtok(NULL,s);
				printf("IDADE: %s\t", tok);
				tok = strtok(NULL,s);
				printf("NOME: %s\n", tok);
                return;
            }
		}
	}

	fclose(file);
}

void separa(char *path){
	char filename[100];
	char *res;
	char linha[1024];

	int cont = 0;
	int aux = 1;

	FILE *sep;
	FILE *dat;
	sprintf(filename, "./database/data%d.txt", aux);
	dat = fopen(path, "r");
	sep = fopen(filename, "w");
	
	if(dat == NULL){
     	printf("Erro, Database Inexistente!\n");
    }else{
		while(!feof(dat)){

			if(cont == 10 && aux < 101){
				cont = 0;
				fclose(sep);
				aux++;
				sprintf(filename, "./database/data%d.txt", aux);
				sep = fopen(filename, "w");
			}
			res = fgets(linha, 1024, dat);
			fprintf(sep, "%s", res);
			cont++;
		}
	}
	fclose(dat);
}
