#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;
struct no{
    int valor;
    NO *esq, *dir;
};

NO* inserir(NO *raiz, int valor){
    if(raiz == NULL){
        raiz = malloc(sizeof(NO));
        raiz->valor = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }else if(valor < raiz->valor){
        raiz->esq = inserir(raiz->esq,valor);
    }else{
        raiz->dir = inserir(raiz->dir,valor);
    }
    return raiz;
}
int estaVazia(NO *raiz){
    if(raiz == NULL){
        return 1;
    }
    return 0;
}
NO* buscaItem(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    if(raiz->valor == valor)
        return raiz;
    if(valor > raiz->valor)
        return buscaItem(raiz->dir,valor);
    else
        return buscaItem(raiz->esq,valor);

}
int buscaEmOrdem(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    buscaEmOrdem(raiz->esq,valor);
    if(raiz->valor == valor)
        printf("valor %d encontrado \n",raiz->valor);
    buscaEmOrdem(raiz->dir,valor);
    
}
int buscaPreOrdem(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    if(raiz->valor == valor)
        printf("valor %d encontrado \n",raiz->valor);
    buscaPreOrdem(raiz->esq,valor);    
    buscaPreOrdem(raiz->dir,valor); 
}
int buscaPosOrdem(NO *raiz, int valor){
    if(raiz == NULL)
        return 0;
    buscaPosOrdem(raiz->esq,valor);    
    buscaPosOrdem(raiz->dir,valor);   
    if(raiz->valor == valor)
        printf("valor %d encontrado \n",raiz->valor); 
}
void emOrdem(NO *raiz){
    if(raiz == NULL)
        return;
    emOrdem(raiz->esq);
    printf("%d \n",raiz->valor);
    emOrdem(raiz->dir);
}
void preOrdem(NO *raiz){
    if(raiz == NULL)
        return;
    printf("%d \n",raiz->valor);
    preOrdem(raiz->esq);    
    preOrdem(raiz->dir);    
}
void posOrdem(NO *raiz){
    if(raiz == NULL)
        return;
    posOrdem(raiz->esq);    
    posOrdem(raiz->dir);   
    printf("%d \n",raiz->valor); 
}
NO *minVal(NO *raiz){
    if(raiz == NULL)
        return raiz;
    if(raiz->esq == NULL)
        return raiz;
    return minVal(raiz->esq);
}
NO *excluir(NO *raiz, int valor){
    NO *tmp;
    if(raiz == NULL)
        return raiz;
    if(valor < raiz->valor){
        raiz->esq = excluir(raiz->esq,valor);
    }else{
        if(valor > raiz->valor){
            raiz->dir = excluir(raiz->dir,valor);
        }else{
            if(raiz->dir && raiz->esq){
                tmp = minVal(raiz->dir);
                raiz->valor = tmp->valor;
                raiz->dir = excluir(raiz->dir, raiz->valor);
            }else{
                tmp = raiz;
                if(raiz->esq == NULL){
                    raiz = raiz->dir;
                }else{
                    if(raiz->dir == NULL){
                        raiz = raiz->esq;
                    }
                    free(tmp);
                }
            }
        }
    }
    return raiz;
}
void esvaziar(NO *raiz){
    if(raiz == NULL)
        return;
    esvaziar(raiz->esq);
    esvaziar(raiz->dir);
    free(raiz);
}

int main(int argc, char** argv){
    NO *raiz = NULL;//cria arvore
    
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 7);
    
    printf("Em ordem\n");
    emOrdem(raiz);
    // if(buscar(raiz,1)==NULL){
    //     printf("Valor nao encontrado\n");
    // }else{
    //     printf("Valor encontrado\n");
    // }
    printf("Busca em ordem\n");
    buscaEmOrdem(raiz,25);
    buscaPreOrdem(raiz,10);
    buscaPosOrdem(raiz,7);
    printf("\nBusca item\n");
    if(buscaItem(raiz,7)!=NULL)
        printf("Valor encontrado\n");
    else
        printf("Valor nao encontrado\n");
    if(buscaItem(raiz,70)!=NULL)
        printf("Valor encontrado\n");
    else
        printf("Valor nao encontrado\n");
    // printf("\nBusca Pre ordem\n");
    // buscaPreOrdem(raiz,25);
    printf("Excluir item\n");
    excluir(raiz,25);
    if(buscaItem(raiz,25)!=NULL)
        printf("Valor encontrado\n");
    else
        printf("Valor nao encontrado\n");
    printf("Esvaziando arvore...\n");
    esvaziar(raiz);
    return (EXIT_SUCCESS);
}
