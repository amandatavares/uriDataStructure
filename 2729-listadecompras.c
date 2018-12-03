#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 2729 URI - Lista de compras

//Desenvolvendo um código que exclua os itens duplicados da lista de compras e que os ordene alfabeticamente.
//
//Entrada
//um inteiro N (N < 100) que indica a quantidade de casos de teste. Cada lista de compra consiste de uma única linha que contém de 1 a 1000 itens ou palavras compostas apenas de letras minúsculas (de 1 a 20 letras), sem acentos e separadas por um espaço.
//
//Saída
//A saída contém N linhas, cada uma representando uma das listas de compras de Valentina, sem itens repetidos e em ordem alfabética.

int main(int argc, char *argv[]) {
	int nTestes, i; // i=aux for ntestes
	char lista[10000], listaProdutos[1000][100] *produto;
    int cont1, cont2;

	printf("Quantas listas deseja fazer?: ");
	scanf("%d", &nTestes);

	for(i=0,i<nTestes,i++) {

		printf("Digite sua lista");
		fflush(stdout);
        produto = strtok(nome, " ");
        while(produto != NULL) {
            strcpy(listaProdutos[cont1], produto);
			cont1++;
			produto = strtok(NULL, " ");
        }
        qsort((void*)listaProdutos, )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       \
		if (!(fgets(lista, sizeof lista, stdin) != NULL)) {
		    fprintf(stderr, "Error reading Name.\n");
		    exit(1);
		}
		printf("%s",lista);
		i++;
	}
	return 0;
}
