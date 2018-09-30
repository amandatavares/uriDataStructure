#include <stdio.h>
#include <stdlib.h>
#include "menu.c"

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
