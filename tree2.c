#include <stdlib.h>
#include <stdio.h>

typedef struct registro_st{         // sequ�ncia de objetos do mesmo tipo
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
    nodo* novo = malloc(sizeof(nodo)); //agora sem cast pois � desnecess�rio
    if(novo == NULL){
        return; // � void logo n�o pode ter tipo de retorno
    }

    novo->dado = registro; //o dado � o registro todo em si
    novo->dir = NULL;
    novo->esq= NULL;

    if(*raiz == NULL){ //ver se o valor do ponteiro � null, logo arvore vazia
        *raiz = novo;
        return;
    }

    nodo* atual = *raiz;
    nodo* ant = NULL;

    while(atual != NULL){ // la�o/ciclo agora s� para navegar at� ao sitio correto
        ant = atual;

        //o valor a ser inserido vem no pr�prio registro, com registro->valor
        if (registro->valor == atual->dado->valor){
            free(novo);
            return; // � void logo n�o pode ter tipo de retorno
        }

        if(registro->valor > atual->dado->valor){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }

    //ap�s navegar � feita a inser��o pelo no anterior.
    if (registro->valor > ant->dado->valor){ //se maior que o anterior fica a direita
        ant->dir = novo;
    }
    else { //sen�o fica a esquerda
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
