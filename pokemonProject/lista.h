#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//struct Node{
//	char pokemon[30];
//	struct Node *prox;
//};
//typedef struct Node node;

struct Pokemon {
    char nome[30];
    struct Pokemon *prox;
};
typedef struct Pokemon pokemao;

int tam;

void inicia(pokemao *LISTA);
pokemao *criaNo();
void insereFim(pokemao *LISTA, char* pokemon);
void exibe(pokemao *LISTA);
void libera(pokemao *LISTA);
pokemao *retira(pokemao *LISTA);

void inicia(pokemao *LISTA)
{
	LISTA->prox = NULL;
	tam=0;
}

int vazia(pokemao *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

pokemao *aloca()
{
	pokemao *novo=(pokemao *) malloc(sizeof(pokemao));
	if(!novo){
		printf("Sem Pokémon disponivel!\n");
		exit(1);
	}
	return novo;

}

void insereFim(pokemao *LISTA, char* pokemon)
{
	pokemao *novo=aloca();
    strcpy (novo->nome, pokemon);
	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		pokemao *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
	tam++;
}

void exibe(pokemao *LISTA)
{
	system("clear");
	if(vazia(LISTA)){
		printf("PokeStorage vazio!\n\n");
		return ;
	}

	pokemao *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL){
		printf("%s", tmp->nome);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tam ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tam ; count++)
		printf("%5d", count+1);


	printf("\n\n");
}

void libera(pokemao *LISTA)
{
	if(!vazia(LISTA)){
		pokemao *proxPokemon,
			  *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxPokemon = atual->prox;
			free(atual);
			atual = proxPokemon;
		}
	}
}
pokemao *retiraInicio(pokemao *LISTA)
{
	if(LISTA->prox == NULL){
		printf("PokeStorage ja esta vazio\n");
		return NULL;
	}else{
		pokemao *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		tam--;
		return tmp;
	}

}
pokemao *retira(pokemao *LISTA)
{
	int opt,
		count;
	printf("Que Pokémon, [de 1 ate %d] voce deseja retirar: ", tam);
	scanf("%d", &opt);

	if(opt>0 && opt <= tam){
		if(opt==1)
			return retiraInicio(LISTA);
		else{
			pokemao *atual = LISTA->prox,
				 *anterior=LISTA;

			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}

		anterior->prox=atual->prox;
		tam--;
		return atual;
		}

	}else{
		printf("Pokémon invalido\n\n");
		return NULL;
	}
}

#endif // LISTA_H_INCLUDED
