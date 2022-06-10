# Árvores B
Trabalho realizado para a disciplina de Algoritmo e Estrutura de Dados 2 sobre o assunto de árvore B.

# Compilação
Para compilar
```
make clean
make
make run
```

## Problema Proposto
Conforme observamos em sala de aula, uma das funções da estrutura em árvore B é prover capacidade de manipulação de inúmeros arquivos, muitas vezes grandes, sob uma hierarquia de sub-conjuntos de entradas menores, cada qual representado por um nó da estrutura. Sua função é simular um banco de dados. Nesse, teremos apenas uma única tabela, composta por nome, idade, cpf que chamaremos de clientes. Nossa tabela deve ter dados aleatórios, o quais podem vir de um banco qualquer da internet ou produzido por vocês a partir de um processo randômico. Teremos nesta tabela 1.000 entradas e cada página da árvore B (i.e., arquivo separado dessa tabela)  sendo representada por 10 dessas entradas de forma ordenada. 

Aplicação: A aplicação de vocês deve ser capaz de mapear esses arquivos com 10 entradas sob o conceito que trabalhamos em sala. Para tanto, considere que cada arquivo seja mapeado por um código que consiga identificar o range de cpfs que estão salvos nele. Nossa árvore tem fator de crescimento m = 2, logo, cada página guardará de 1 a 3 códigos desses. Sua função é prover um menu que consiga: Inserir, Remover e Pesquisar pessoas nesse grupo de arquivos, mantendo sempre a integridade da estrutura e tamanho máximo do arquivo. 

## Database
Para o trabalho sugerido foi montada uma base dados fictícia onde existem cpfs de 0 a 999 e a idade, para fins de facilitar a montagem da estrutura não foram inseridos os nomes no arquivo mas caso adicionado o programa seria capaz de mostrar o mesmo, para demonstrar o arqivo data1.txt, que é referente aos 10 primeiros cpfs da database conterá nomes.

## Separação do Database
Para inserir os dados na árvore seguindo as regras propostas no trabalho é necessário dividir a database em arquivos menores, para tal foi implementado o código abaixo:
```
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
``` 

## Estrutura da Árvore
Para atender o que foi solicitado no trabalho foram feitas alterações na struct da árvore, a fim de facilitar posteriormente a busca das informações, sendo assim foram adicionados os valores minimos e máximos presentes em cada arquivo, além do endereço para o arquivo em questão. A segir está a struct utilizada:
```
struct Record {
  int key;
  char *fileName;
  int min;
  int max;
};
```

## Método de Busca

Para pesquisar na estrutura modificada da árvore B foi necessário fazer alterações no método de busca da mesma

```
void searchBTree(Pagina *p, int cpf){
    short i = 1;

    if(p == NULL){
        printf("[ERROR]: Node not found!");
        return;
    }

    while (i < p->n && cpf > p->r[i-1].max) i++;

    if ((cpf >= p->r[i-1].min) && (cpf <= p->r[i-1].max)){ 
        printf("File Found:%s\n", p->r[i-1].fileName);
        searchInFile(p->r[i-1].fileName, cpf);
        return;
    }

    if (cpf < p->r[i-1].min) 
        searchBTree(p->p[i-1], cpf);
    else 
        searchBTree(p->p[i], cpf);
}
```
Abaixo um exemplo de busca com o CPF fictício 3:
![Capturar](https://user-images.githubusercontent.com/60747654/148835448-8423e4da-2f76-4365-a57a-2a38fb559400.PNG)



