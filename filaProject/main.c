#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// MENU

int menu(void);
void opcao(node *FILA, int op);

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Exibir fila\n");
	printf("2. Adicionar Elemento na Fila\n");
	printf("3. Retirar Elemento da Fila\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}
// main chama o menu no loop while
// a opcao escolhida � pega em menu() e passada para opcao(), que recebe a fila e a opcao do usu�rio
// opcao() possui um switch, que chama a funcao equivalente � escolha do usu�rio
int main(void)
{
	// malloc() serve para alocar memoria, ou seja, reserva um numero especifico de memoria, dependendo do tipo do ponteiro que chama a funcao
	// A fun�ao reserva o n�mero de bytes que queremos alocar na mem�ria , e retorna um ponteiro void * para o primeiro byte alocado.
	// Se n�o houver mem�ria suficiente para alocar a mem�ria requisitada a fun��o malloc() retorna um ponteiro nulo

	node *FILA = (node *) malloc(sizeof(node));
	if(!FILA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(FILA);
	int opt;

	do{
		opt=menu();
		opcao(FILA,opt);
	}while(opt);

	// liberando mem�ria ao t�rmino da funcao conforme recomendado com a fun��o free()
	free(FILA);
	return 0;
	}
}

void opcao(node *FILA, int op)
{
	node *tmp;
	char nomePokemon[30];

	switch(op){
		// sair
		case 0:
			free(FILA);
			break;

		// exibir a fila
		case 1:
            exibe(FILA);
			break;

		// adicionar elemento na fila
		case 2:
			printf("Novo pokemon \n");
            printf("Nome \n"); scanf("%s", nomePokemon);
			insere(FILA,nomePokemon);
			break;

		// retirar elemento da fila
		case 3:
            tmp = retira(FILA);
			if(tmp != NULL){
				printf("Retirado: %20s\n\n", tmp->pokemon);
				free(tmp);
			}
			break;

		default:
			printf("Comando invalido\n\n");
	}
}

