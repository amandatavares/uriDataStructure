#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "fila.h"

void opcao(pokemao *LISTA, node *FILA, int op);
int menu(void);
int main(void);

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar lista\n");
	printf("2. Exibir lista\n");
	printf("3. Adicionar Pokemon\n");
	printf("4. Transferir Pokemon\n");
	printf("5. Selecionar Pokemon para time\n");
	printf("6. Exibir time Pokemon\n");
	printf("7. Retirar Pokemon do time\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(pokemao *LISTA, node *FILA, int op)
{
    char nomePokemon[30];
	pokemao *tmp;
    node *tmpNode;

	switch(op){
	    // fecha o programa
		case 0:
			libera(LISTA);
			break;

        // zera a lista de pokemons
		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;

        // exibir pokemons da Pokestorage
		case 2:
			exibe(LISTA);
			break;

        // adicionar pokemon a Pokestorage
		case 3:
		    printf("Novo pokemon \n");
            printf("Nome \n"); scanf("%s", nomePokemon);
			insereInicio(LISTA,nomePokemon);
			break;

        // transferir (retirar) pokemon da lista
		case 4:
            exibe(LISTA);
			tmp= retira(LISTA);
			printf("Transferido: %s\n\n", tmp->nome);
			break;

        // adicionar pokemon ao Time (fila)
        case 5:
            exibe(LISTA);
			strcpy(nomePokemon,selecionarParaBatalha(LISTA));
			insereNode(FILA, nomePokemon);
			break;

        // mostrar time (fila)
        case 6:
            exibeNode(FILA);
			break;

        // retirar pokemon do time
        case 7:
            tmpNode = retiraNode(FILA);
			if(tmpNode != NULL){
				printf("Retirado: %20s\n\n", tmpNode->pokemon);
				free(tmpNode);
			}
			break;
		default:
			printf("Comando invalido\n\n");
	}
}

int main(void) {
    pokemao *LISTA = (pokemao *) malloc(sizeof(pokemao));
   	node *FILA = (node *) malloc(sizeof(node));

	if(!LISTA){
		printf("!\n");
		exit(1);
	}else{
	inicia(LISTA);
	}

	if(!FILA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	iniciaNode(FILA);
	}

	int opt;

	do{
		opt=menu();
		opcao(LISTA, FILA, opt);
	}while(opt);

	free(LISTA);
	free(FILA);
	return 0;
}
