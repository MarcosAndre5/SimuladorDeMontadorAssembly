#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_CARAC = 1000;
const int MAX_LINHAS = 1000;

int main(int argc, char **argv) {
	char linha[MAX_CARAC];
	char palavra[3][MAX_CARAC];
	int endereco[MAX_LINHAS];
	int i;
	FILE *arquivo;

	if(argc != 2) {
		printf("Uso: %s <arquivo.asm>\n", argv[0]);
		return 0;
	}

	if((arquivo = fopen(argv[1], "r")) == NULL) {
		printf("Erro ao abrir o arquivo %s\n", argv[1]);
		return 0;
	}

	i = 0;
	while(fgets(linha, MAX_CARAC, arquivo) != NULL) {
		int qtd = 0;

		qtd = sscanf(linha, "%s %s %s", palavra[0], palavra[1], palavra[2]);

		
		if(i == 0 && strcmp(palavra[1], "START") == 0) {
			endereco[0] = atoi(palavra[2]);
			endereco[1] = endereco[0];
		} else if(strcmp(palavra[1], "STA") == 0) {
			endereco[i + 1] = endereco[i] + 3;
		} else if(strcmp(palavra[1], "LDA") == 0) {
			endereco[i + 1] = endereco[i] + 3;
		} else
			endereco[i + 1] = endereco[i];
		printf("%x: %d [%s] [%s] [%s]\n", endereco[i], qtd, palavra[0], palavra[1], palavra[2]);
		i++;

	}
	return 0;
}
