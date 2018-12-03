#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void opcao(NO *raiz, int op);
int menu(void);
int main(void);

int menu(void) {
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar arvore\n");
	printf("2. Exibir arvore\n");
	printf("3. Adicionar Folha\n");
	printf("4. Excluir No\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(NO *raiz, int op) {
    int num;
    NO *tmpNode;

	switch(op){
	    // fecha o programa
		case 0:
			printf("Ate logo! \n");
    		esvaziar(raiz);
    		exit(1);
			break;

        // zera arvore
		case 1:
			printf("Esvaziando arvore...\n");
    		esvaziar(raiz);
			break;

        // exibir arvore
		case 2:
			printf("Em ordem\n");
    		emOrdem(raiz);
			break;

        // adicionar nos a arvore
		case 3:
		    printf("Nova folha \n");
            printf("Numero \n"); scanf("%d", num);
			raiz = inserir(raiz, num);
			//free(num);
			break;
			
		// buscar folha na arvore
		case 4: 
			printf("Numero que deseja buscar \n"); scanf("%d", num);
			if(buscaItem(raiz,num)!=NULL)
		        printf("Valor encontrado\n");
		    else
		        printf("Valor nao encontrado\n");			
			//free(num);
			break;
			
        // retirar no da arvore
		case 5:
			emOrdem(raiz);
            printf("\n Numero que deseja excluir \n"); scanf("%d", num);
			if(buscaItem(raiz,num)!=NULL)
				excluir(raiz,num);
				//printf("Transferido: %s\n\n", tmpNode->valor);
			else
		        printf("Valor nao encontrado\n");
			//free(num);	
			break;
			
		default:
			printf("Comando invalido\n\n");
	}
}

int main(void) {
    NO *raiz = NULL; //cria arvore
    
	int opt;

	do{
		opt=menu();
		opcao(raiz, opt);
	} while(opt);

	free(raiz);
	return 0;
}
