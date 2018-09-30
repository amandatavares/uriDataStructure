#ifndef FILA_H
#define FILA_H

int tam;

//int menu(void);
//void opcao(node *FILA, int op);

// STRUCT NODE
// criamos uma struct Nó para criar os nós da nossa estrutura de dados
// nela, existe o num, para guardar valores inseridos pelo usuário
// e um ponteiro do próprio tipo apontando para o proximo nó da estrutura
// caso aponte NULL, o nó é o último da fila ou a fila está vazia 
struct Node{
	int num;
	struct Node *prox;
};
typedef struct Node node;

void inicia(node *FILA);
int vazia(node *FILA);
node *aloca();
void insere(node *FILA);
node *retira(node *FILA);
void exibe(node *FILA);

//void libera(node *FILA);

#endif
