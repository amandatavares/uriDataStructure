#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "arvore.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Arvore *raiz = NULL;
    int op, achou, num, menu=1, q, i;
    do{
        printf("\nÁRVORE BINARIA \n");
        printf("1- Inserir nós na árvore \n");
        printf("2- Consultar nó na árvore \n");
        printf("3- Listar árvore em ordem \n");
        printf("4- Listar árvore em pré-ordem \n");
        printf("5- Listar árvore em pós-ordem \n");
        printf("6- Excluir nó na árvore \n");
        printf("7- Esvaziar árvore \n");
        printf("0- Sair da aplicação \n");
        printf("\n -> Escolha sua opção: ");
        scanf("%d", &op);
        fflush(stdin);

        switch(op){
        case 1:
            printf("\nINSERIR NÓS NA ÁRVORE\n");
            printf(" -> Quantos nós a inserir? ");
            scanf("%d", &q);
            fflush(stdin);
            for(i=1; i<=q; i++){
                printf(" -> Digite o valor do nó %d: ", i);
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    printf("  NÓ já inserido!\n");
                    i--;
                }
                else{
                raiz = inserir(raiz, num);
                }
            }
            printf("  Nós inseridos na �rvore! \n");
            printf("  Árvore: ");
            mostrarNos(raiz);
            printf("\n");
            break;

        case 2:
            printf("\nCONSULTAR NÓ NA �RVORE\n");
            if(!arvoreVazia(raiz)){
                printf(" -> Digite o nó a ser consultado: ");
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    printf("  Nó encontrado na �rvore!\n");
                }
                else{
                    printf("  Nó não encontrado!\n");
                }
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 3:
            printf("\nLISTAR ÁRVORE EM ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvoreEmOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 4:
            printf("\nLISTAR ÁRVORE EM PRÉ-ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvorePreOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 5:
            printf("\nLISTAR ÁRVORE EM PÓS-ORDEM\n");
            if(!arvoreVazia(raiz)){
                printf("  Listando elementos... { ");
                arvorePosOrdem(raiz);
                printf("}\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 6:
            printf("\nEXCLUIR NÓ DA ÁRVORE\n");
            if(!arvoreVazia(raiz)){
                printf(" -> Digite o nó a ser excluido: ");
                scanf("%d", &num);
                fflush(stdin);
                achou = 0;
                achou = consultar(raiz, num, achou);
                if(achou){
                    raiz = remover(raiz, num);
                    printf("  Nó excluído!\n");
                    printf("  Árvore: ");
                    mostrarNos(raiz);
                    printf("\n");
                }
                else printf("  Nó não encontrado!\n");
            }
            else{
                printf("  Árvore vazia!\n");
            }
            break;

        case 7:
            printf("\nESVAZIAR ÁRVORE\n");
            if(!arvoreVazia(raiz)){
                raiz = desalocar(raiz);
                printf("  Árvore esvaziada!\n");
            }
            else{
                printf("  Árvore vazia! \n");
            }
            break;

        case 0:
            printf("\n -> DESEJA SAIR DA APLICAÇÃO(1-SIM // 2-NÃO)? ");
            scanf("%d", &num);
            fflush(stdin);
            if(num == 1){
                printf("  Saindo da aplicação...\n");
                menu = 0;
            }
            break;

        default:
            printf("  OPÇÃO INVÁLIDA! \n");
            break;
        }
    }while(menu);
    /*
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 14);
    arvoreEmOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 3);
    arvoreEmOrdem(raiz);
    raiz = desalocar(raiz);
    if(raiz == NULL) printf("Vazia!");
    */
    return 0;
}
