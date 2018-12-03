#include <stdlib.h>
#include <stdio.h>

typedef struct registro_st{         // sequência de objetos do mesmo tipo
    char login[50];
    char nome[50];
    float valor;
    struct registro *prox;
} registro;

typedef struct nodo_st{
    registro *dado;
    struct nodo_st *dir;
    struct nodo_st *esq;
} nodo;

typedef struct Lista_st{
    nodo *cabeca;
    nodo *cauda;
    int tamanho;
} lista;

//A raiz passou a **raiz, e registro a *registro
void insere_Arvore(nodo **raiz, struct registro_st *registro) {
    nodo* novo = malloc(sizeof(nodo)); //agora sem cast pois é desnecessário
    if(novo == NULL){
        return; // é void logo não pode ter tipo de retorno
    }

    novo->dado = registro; //o dado é o registro todo em si
    novo->dir = NULL;
    novo->esq= NULL;

    if(*raiz == NULL){ //ver se o valor do ponteiro é null, logo arvore vazia
        *raiz = novo;
        return;
    }

    nodo* atual = *raiz;
    nodo* ant = NULL;

    while(atual != NULL){ // laço/ciclo agora só para navegar até ao sitio correto
        ant = atual;

        //o valor a ser inserido vem no próprio registro, com registro->valor
        if (registro->valor == atual->dado->valor){
            free(novo);
            return; // é void logo não pode ter tipo de retorno
        }

        if(registro->valor > atual->dado->valor){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }

    //após navegar é feita a inserção pelo no anterior.
    if (registro->valor > ant->dado->valor){ //se maior que o anterior fica a direita
        ant->dir = novo;
    }
    else { //senão fica a esquerda
        ant->esq = novo;
    }
}
void exibirEmOrdem(nodo **raiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esquerda);
        printf("\n%i", pRaiz->numero);
        exibirEmOrdem(pRaiz->direita);
    }
} 
int main(){
    nodo *arvore = NULL;

    registro *reg = malloc(sizeof(registro));
    strcpy(reg->nome, "O nome aqui");
    strcpy(reg->login, "O login aqui");
    reg->valor = 10;

    insere_Arvore(&arvore, reg);
    
}
