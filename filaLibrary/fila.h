#ifndef FILA_H
#define FILA_H

int tam;

//int menu(void);
//void opcao(node *FILA, int op);

// STRUCT NODE
// criamos uma struct N� para criar os n�s da nossa estrutura de dados
// nela, existe o num, para guardar valores inseridos pelo usu�rio
// e um ponteiro do pr�prio tipo apontando para o proximo n� da estrutura
// caso aponte NULL, o n� � o �ltimo da fila ou a fila est� vazia 
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
