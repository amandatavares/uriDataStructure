#include <stdio.h>
#include <stdlib.h>

// criamos uma struct Nó para criar os nós da nossa estrutura de dados
// nela, existe o num, para guardar valores inseridos pelo usuário
// e um ponteiro do próprio tipo apontando para o proximo nó da estrutura
// caso aponte NULL, o nó é o último da fila ou a fila está vazia 
struct Node{
	int num;
	struct Node *prox;
};

typedef struct Node node;

int tam;

int menu(void);
void opcao(node *FILA, int op);
void inicia(node *FILA);
int vazia(node *FILA);
node *aloca();
void insere(node *FILA);
node *retira(node *FILA);
void exibe(node *FILA);
//void libera(node *FILA);

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

// ao iniciar, definimos o prox da fila como NULL, que é o mesmo que dizer que a fila está vazia
// se a fila tivesse algum elemento, prox apontaria para o primeiro elemento
void inicia(node *FILA)
{
	FILA->prox = NULL;
	tam=0;
}

// funcao para verificar se a fila está vazia, ou seja, de prox aponta para NULL. se estiver, retorna 1, true.
int vazia(node *FILA)
{
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;
}

// aloca memória para cada nó da nossa fila
node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}

// reservamos memoria para o elemento e definimos o seu prox como NULL para declarar que ele é o ultimo da fila
// usamos a funcao vazia() para verificar se há elementos na fila. se nao houver, o prox da Fila será o novo nó
// se houver,  "tmp" que vai apontar para todos os elementos da fila em busca do último
// começa no primeiro elemento, que está em "FILA->prox". Se "tmp->prox" apontar para NULL, o ponteiro aponta para o último da fila.
// Senao, devemos seguir adiante com o ponteiro (tmp = tmp->prox) até acharmos o último elemento.
// Achando, colocamos lá o novo nó, "novo".
void insere(node *FILA)
{
	node *novo=aloca();
	novo->prox = NULL;

	if(vazia(FILA))
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

// de acordo com a logica da estrutura, o nó a ser retirado é o primeiro
// checamos se está vazia. se nao estiver, identificamos o primeiro e segundo elemento
// "tmp" aponta para o primeiro elemento. Se "tmp" aponta para o primeiro elemento, "tmp->prox" aponta para o segundo ou NULL, caso a fila só tenha um nó.
// definiremos que o novo primeiro elemento será o antigo segundo. assim, tiramos o primeiro elemento da nossa estrutura de dados.

// declaramos a função "retira()" como sendo do tipo struct Node, pois é uma boa prática retornar o nó que retiramos para trabalhar com ele
// retornamos ele para a funcao opcao() para exibir o nó retirado e liberar a memória dele
node *retira(node *FILA)
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

// exibir os numeros num em casa nó, para poder ver, adicionar ou retirar 
// se nao ouver elementos, isso é sinalizado para o usuário
// se houver, pegamos o primeiro elemento em "tmp" e começamos a imprimir os numeros um por um, até o ultimo elemento (NULL)
// para saber o tanto de nós existentes e a ordem, 
// usamos "tam" que é incrementada quando adicionamos nó na fila em insere() e decrementada quando tiramos elemento em retira()
void exibe(node *FILA)
{
	if(vazia(FILA)){
		printf("Fila vazia!\n\n");
		return ;
	}

	node *tmp;
	tmp = FILA->prox;
	printf("Fila :");
	while( tmp != NULL){
		printf("%5d", tmp->num);
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

// vai no nó e libera a memória alocada
// se a fila nao estiver vazia, criamos dois nós, o atual e o proximo, que é o nó seguinte
// liberamos o nó atual, mas nao perdemos a fila porque o ponteiro proxNode agora é o atual, e o o prox é o à sua frente
// repetimos até que o nó atual seja NULL (fim da fila).
//void libera(node *FILA)
//{
//	if(!vazia(FILA)){
//		node *proxNode,
//			  *atual;
//
//		atual = FILA->prox;
//		while(atual != NULL){
//			proxNode = atual->prox;
//			free(atual);
//			atual = proxNode;
//			proxNode = proxNode->prox;
//		}
//	}
//}
