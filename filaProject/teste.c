#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar fila\n");
	printf("2. Exibir fila\n");
	printf("3. Adicionar Elemento na Fila\n");
	printf("4. Retirar Elemento da Fila\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *FILA, int op)
{
	node *tmp;
	switch(op){
		// sair
		case 0:
			free(FILA);
			break;

		// zerar a fila
		case 1:
			free(FILA);
			inicia(FILA);
			break;

		// exibir a fila
		case 2:
			exibe(FILA);
			break;

		// adicionar elemento na fila
		case 3:
			insere(FILA);
			break;

		// retirar elemento da fila
		case 4:
			tmp= retira(FILA);
			if(tmp != NULL){
				printf("Retirado: %3d\n\n", tmp->num);
				free(tmp);
			}
			break;

		default:
			printf("Comando invalido\n\n");
	}
}

// main chama o menu no loop while
// a opcao escolhida é pega em menu() e passada para opcao(), que recebe a fila e a opcao do usuário
// opcao() possui um switch, que chama a funcao equivalente à escolha do usuário
int main(void)
{
	// malloc() serve para alocar memoria, ou seja, reserva um numero especifico de memoria, dependendo do tipo do ponteiro que chama a funcao
	// A funçao reserva o número de bytes que queremos alocar na memória , e retorna um ponteiro void * para o primeiro byte alocado.
	// Se não houver memória suficiente para alocar a memória requisitada a função malloc() retorna um ponteiro nulo

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

	// liberando memória ao término da funcao conforme recomendado com a função free()
	free(FILA);
	return 0;
	}
}
