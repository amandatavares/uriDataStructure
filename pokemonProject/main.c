#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void opcao(pokemao *LISTA, int op);
int menu(void);
int main(void);

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar lista\n");
	printf("2. Exibir lista\n");
//	printf("3. Adicionar Pokémon no inicio\n");
	printf("3. Adicionar Pokémon no final\n");
//	printf("5. Escolher onde inserir\n");
//	printf("6. Retirar Pokémon do inicio\n");
//	printf("7. Retirar Pokémon do fim\n");
	printf("4. Escolher de onde tirar\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(pokemao *LISTA, int op)
{
    char nomePokemon[30];
	pokemao *tmp;

	switch(op){
		case 0:
			libera(LISTA);
			break;

		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;

		case 2:
			exibe(LISTA);
			break;

		case 3:
		    printf("Novo pokemon \n");
            printf("Nome \n"); scanf("%s", nomePokemon);
			insereFim(LISTA,nomePokemon);
			break;

		case 4:
			tmp= retira(LISTA);
			printf("Transferido: %s\n\n", tmp->nome);
			break;

		default:
			printf("Comando invalido\n\n");
	}
}

int main(void) {
    pokemao *LISTA = (pokemao *) malloc(sizeof(pokemao));
	if(!LISTA){
		printf("!\n");
		exit(1);
	}else{
	inicia(LISTA);
	int opt;

	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);

	free(LISTA);
	return 0;
	}
}
