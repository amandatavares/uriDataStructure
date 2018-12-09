#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct No Arvore;
struct No{
    int num;
    Arvore *esq;
    Arvore *dir;
};

int arvoreVazia(Arvore *raiz){
    if(raiz == NULL) return TRUE;
    else return FALSE;
}

Arvore *inserir (Arvore *aux, int num){
    if(aux == NULL){
        aux = malloc(sizeof(Arvore));
        aux->num = num;
        aux->dir = NULL;
        aux->esq = NULL;
    }
    else if(num < aux->num)
        aux->esq = inserir(aux->esq, num);
    else
        aux->dir = inserir(aux->dir, num);
    return aux;
}

int consultar(Arvore *aux, int num, int achou){
    if(aux != NULL && achou == 0){
        if(aux->num == num){
            achou = 1;
        }if(num < aux->num){
            achou = consultar(aux->esq, num, achou);
        }else{
            achou = consultar(aux->dir, num, achou);
        }
    }return achou;
}

void arvoreEmOrdem(Arvore *aux){
    if(aux != NULL){
        arvoreEmOrdem(aux->esq);
        printf("%d ", aux->num);
        arvoreEmOrdem(aux->dir);
    }
}

void arvorePreOrdem(Arvore *aux){
    if(aux != NULL){
        printf("%d ", aux->num);
        arvorePreOrdem(aux->esq);
        arvorePreOrdem(aux->dir);
    }
}

void arvorePosOrdem(Arvore *aux){
    if(aux != NULL){
        arvorePosOrdem(aux->esq);
        arvorePosOrdem(aux->dir);
        printf("%d ", aux->num);
    }
}

Arvore *remover(Arvore *aux, int num){
    Arvore *p, *p2;
    if(aux->num == num){
        if(aux->esq == aux->dir) {
            //raiz n�o tem filhos
            free(aux);
            return NULL;
        }
        else if(aux->esq == NULL){
            // raiz n�o tem filho para a esquerda
            p = aux->dir;
            free(aux);
            return p;
        }
        else if(aux->dir == NULL){
            // raiz n�o tem filho para a direita
            p = aux->esq;
            free(aux);
            return p;
        }
        else{
            //raiz tem filho para ambos os lados
            p2 = aux->dir;
            p = aux->dir;
            while(p->esq != NULL){
                p = p->esq;
            }
            p->esq = aux->esq;
            free(aux);
            return p2;
        }
    }
    else if(aux->num < num){
        aux->dir = remover(aux->dir, num);
    }
    else{
        aux->esq = remover(aux->esq, num);
    }
    return aux;
}

Arvore *desalocar(Arvore *aux){
    if(aux != NULL){
        aux->esq = desalocar(aux->esq);
        aux->dir = desalocar(aux->dir);
        free(aux);
    }
    return NULL;
}

void mostrarNos(Arvore *aux){
    int r, d=0, e=0;
    if(aux != NULL){
        r = aux->num;
        if(aux->dir != NULL) {
            d = aux->dir->num;
        }if(aux->esq != NULL) {
            e = aux->esq->num;
        }
        printf("{%d[%d, %d]} ", r, e, d);
        mostrarNos(aux->esq);
        mostrarNos(aux->dir);
    }
}

