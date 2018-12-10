#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// arvore possui um vertice (num) e no da esquerda e da direita
typedef struct No Arvore;
struct No{
    int num;
    Arvore *esq;
    Arvore *dir;
};

// recebe a raiz da arvore. se for nulo, esta vazio
int arvoreVazia(Arvore *raiz){
    if(raiz == NULL) return TRUE;
    else return FALSE;
}

// recebe uma referencia para a arvore e um inteiro que sera o valor do no
// se nulo nao tem ainda, dai cria o nó, com esquerda, direita e vertice
// se ja existia arvore e o numero for menor, insere na esquerda
// se for maior, insere na direita
// a arvore binaria é ordenada
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

// recebe a arvore, o numero do vertice a pesquisar e um bool, que aqui é int
// se a arvore existir e o vertice nao tiver sido encontrado, procura-se
// codigo recursiva
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

// para mostrar em ordem, pegamos o no da esquerda, da raiz e depois da direita
void arvoreEmOrdem(Arvore *aux){
    if(aux != NULL){
        arvoreEmOrdem(aux->esq);
        printf("%d ", aux->num);
        arvoreEmOrdem(aux->dir);
    }
}

// para mostrar em pre ordem, pegamos, o no da raiz esquerda, depois da direita
void arvorePreOrdem(Arvore *aux){
    if(aux != NULL){
        printf("%d ", aux->num);
        arvorePreOrdem(aux->esq);
        arvorePreOrdem(aux->dir);
    }
}

// para mostrar em pos ordem, pegamos, o no da raiz esquerda, da direita e depois da raiz
void arvorePosOrdem(Arvore *aux){
    if(aux != NULL){
        arvorePosOrdem(aux->esq);
        arvorePosOrdem(aux->dir);
        printf("%d ", aux->num);
    }
}

// a remocao é a parte mais complexa da arvore
//criamos dois Nos auxiliares, p e p2
// procuramos o no

Arvore *remover(Arvore *aux, int num){
    Arvore *p, *p2;
    if(aux->num == num){
        if(aux->esq == aux->dir) {
            //raiz não tem filhos
            free(aux);
            return NULL;
        }
        else if(aux->esq == NULL){
            // raiz não tem filho para a esquerda
            p = aux->dir;
            free(aux);
            return p;
        }
        else if(aux->dir == NULL){
            // raiz não tem filho para a direita
            p = aux->esq;
            free(aux);
            return p;
        }
        else{
            //raiz tem filho para ambos os lados
            // coloca o no direito em cada auxiliar
            // se houver no esquerdo, um aux sera ele
            p2 = aux->dir;
            p = aux->dir;
            while(p->esq != NULL){
                p = p->esq;
            }
            // TODO: entender essa parte
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

// mostra os nos com seus filhos ou nao
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

