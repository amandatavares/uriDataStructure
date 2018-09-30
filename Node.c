// criamos uma struct Nó para criar os nós da nossa estrutura de dados
// nela, existe o num, para guardar valores inseridos pelo usuário
// e um ponteiro do próprio tipo apontando para o proximo nó da estrutura
// caso aponte NULL, o nó é o último da fila ou a fila está vazia 
struct Node{
	int num;
	struct Node *prox;
};

typedef struct Node node;

