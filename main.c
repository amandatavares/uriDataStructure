#include <stdio.h>
#include <stdlib.h>
#include "menu.c"

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
