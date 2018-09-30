#include <stdio.h>
#include <stdlib.h>

// criamos uma struct N� para criar os n�s da nossa estrutura de dados
// nela, existe o num, para guardar valores inseridos pelo usu�rio
// e um ponteiro do pr�prio tipo apontando para o proximo n� da estrutura
// caso aponte NULL, o n� � o �ltimo da fila ou a fila est� vazia 
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

// ao iniciar, definimos o prox da fila como NULL, que � o mesmo que dizer que a fila est� vazia
// se a fila tivesse algum elemento, prox apontaria para o primeiro elemento
void inicia(node *FILA)
{
	FILA->prox = NULL;
	tam=0;
}

// funcao para verificar se a fila est� vazia, ou seja, de prox aponta para NULL. se estiver, retorna 1, true.
int vazia(node *FILA)
{
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;
}

// aloca mem�ria para cada n� da nossa fila
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

// reservamos memoria para o elemento e definimos o seu prox como NULL para declarar que ele � o ultimo da fila
// usamos a funcao vazia() para verificar se h� elementos na fila. se nao houver, o prox da Fila ser� o novo n�
// se houver,  "tmp" que vai apontar para todos os elementos da fila em busca do �ltimo
// come�a no primeiro elemento, que est� em "FILA->prox". Se "tmp->prox" apontar para NULL, o ponteiro aponta para o �ltimo da fila.
// Senao, devemos seguir adiante com o ponteiro (tmp = tmp->prox) at� acharmos o �ltimo elemento.
// Achando, colocamos l� o novo n�, "novo".
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

// de acordo com a logica da estrutura, o n� a ser retirado � o primeiro
// checamos se est� vazia. se nao estiver, identificamos o primeiro e segundo elemento
// "tmp" aponta para o primeiro elemento. Se "tmp" aponta para o primeiro elemento, "tmp->prox" aponta para o segundo ou NULL, caso a fila s� tenha um n�.
// definiremos que o novo primeiro elemento ser� o antigo segundo. assim, tiramos o primeiro elemento da nossa estrutura de dados.

// declaramos a fun��o "retira()" como sendo do tipo struct Node, pois � uma boa pr�tica retornar o n� que retiramos para trabalhar com ele
// retornamos ele para a funcao opcao() para exibir o n� retirado e liberar a mem�ria dele
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

// exibir os numeros num em casa n�, para poder ver, adicionar ou retirar 
// se nao ouver elementos, isso � sinalizado para o usu�rio
// se houver, pegamos o primeiro elemento em "tmp" e come�amos a imprimir os numeros um por um, at� o ultimo elemento (NULL)
// para saber o tanto de n�s existentes e a ordem, 
// usamos "tam" que � incrementada quando adicionamos n� na fila em insere() e decrementada quando tiramos elemento em retira()
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

// vai no n� e libera a mem�ria alocada
// se a fila nao estiver vazia, criamos dois n�s, o atual e o proximo, que � o n� seguinte
// liberamos o n� atual, mas nao perdemos a fila porque o ponteiro proxNode agora � o atual, e o o prox � o � sua frente
// repetimos at� que o n� atual seja NULL (fim da fila).
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
