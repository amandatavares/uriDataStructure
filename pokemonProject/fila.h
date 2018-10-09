#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FILA_H
#define FILA_H

int tam;

// STRUCT NODE
// criamos uma struct N� para criar os n�s da nossa estrutura de dados
// nela, existe o num, para guardar valores inseridos pelo usu�rio
// e um ponteiro do pr�prio tipo apontando para o proximo n� da estrutura
// caso aponte NULL, o n� � o �ltimo da fila ou a fila est� vazia
struct Node{
	char pokemon[30];
	struct Node *prox;
};
typedef struct Node node;

void iniciaNode(node *FILA);
int vaziaNode(node *FILA);
node *alocaNode();
void insereNode(node *FILA, char* pokemon);
node *retiraNode(node *FILA);
void exibeNode(node *FILA);

// ESSENTIALS
// funcao para verificar se a fila est� vazia, ou seja, de prox aponta para NULL. se estiver, retorna 1, true.
int vaziaNode(node *FILA)
{
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;
}

// aloca mem�ria para cada n� da nossa fila
node *alocaNode()
{
	node *novo =(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
    return novo;

}

// FILA CRUD
// ao iniciar, definimos o prox da fila como NULL, que � o mesmo que dizer que a fila est� vazia
// se a fila tivesse algum elemento, prox apontaria para o primeiro elemento
void iniciaNode(node *FILA)
{
	FILA->prox = NULL;
	tam=0;
}

// reservamos memoria para o elemento e definimos o seu prox como NULL para declarar que ele � o ultimo da fila
// usamos a funcao vazia() para verificar se h� elementos na fila. se nao houver, o prox da Fila ser� o novo n�
// se houver,  "tmp" que vai apontar para todos os elementos da fila em busca do �ltimo
// come�a no primeiro elemento, que est� em "FILA->prox". Se "tmp->prox" apontar para NULL, o ponteiro aponta para o �ltimo da fila.
// Senao, devemos seguir adiante com o ponteiro (tmp = tmp->prox) at� acharmos o �ltimo elemento.
// Achando, colocamos l� o novo n�, "novo".
void insereNode(node *FILA, char* pokemon)
{
	node *novo=alocaNode();
    strcpy (novo->pokemon, pokemon);
	novo->prox = NULL;

	if(vaziaNode(FILA))
		FILA->prox=novo;
	else{
		node *tmp = FILA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
	// aumentamos a variavel tam para usar na funcao exibe()
	tam++;
}

// de acordo com a logica da estrutura, o n� a ser retirado � o primeiro
// checamos se est� vazia. se nao estiver, identificamos o primeiro e segundo elemento
// "tmp" aponta para o primeiro elemento. Se "tmp" aponta para o primeiro elemento, "tmp->prox" aponta para o segundo ou NULL, caso a fila s� tenha um n�.
// definiremos que o novo primeiro elemento ser� o antigo segundo. assim, tiramos o primeiro elemento da nossa estrutura de dados.

// declaramos a fun��o "retira()" como sendo do tipo struct Node, pois � uma boa pr�tica retornar o n� que retiramos para trabalhar com ele
// retornamos ele para a funcao opcao() para exibir o n� retirado e liberar a mem�ria dele
node *retiraNode(node *FILA)
{
	if(FILA->prox == NULL){
		printf("Fila ja esta vazia\n");
		return NULL;
	}else{
		node *tmp = FILA->prox;
		FILA->prox = tmp->prox;
		tam--;
		return tmp;
	}

}

// exibir os numeros num em casa n�, para poder ver, adicionar ou retirar
// se nao ouver elementos, isso � sinalizado para o usu�rio
// se houver, pegamos o primeiro elemento em "tmp" e come�amos a imprimir os numeros um por um, at� o ultimo elemento (NULL)
// para saber o tanto de n�s existentes e a ordem,
// usamos "tam" que � incrementada quando adicionamos n� na fila em insere() e decrementada quando tiramos elemento em retira()
void exibeNode(node *FILA)
{
    system("clear");
	if(vaziaNode(FILA)){
		printf("Fila vazia!\n\n");
		return ;
	}

	node *tmp = FILA->prox;
	int count = 0;

	printf("Fila :\n");

    while(tmp != NULL){
        printf("%d - ", count+1);
		printf("%s", tmp->pokemon);
        printf("\n");
        count++;
		tmp = tmp->prox;
	}
	printf("\n\n");
}

#endif // FILA_H
