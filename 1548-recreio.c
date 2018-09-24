#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TRUE  1
#define FALSE 0

int main() {
	int  Ncasos= 0, Malunos = 0, c, d, k, aux, qtd; // n = num de casos, M = num de alunos, aux
	int vAntes[1000], vDepois[1000];
	char trocas;

	scanf("%d", &Ncasos);

	for(c=0; c < Ncasos; c++) 
	{
		qtd=0;
		scanf("%d", &Malunos); // Pega o numero de alunos

		for(d=0; d < Malunos; d++)
		{
			scanf("%d", &vAntes[d]); // pega a nota de cada aluno na ordem de chegada
			vDepois[d] = vAntes[d]; // iguala a lista que sera ordenada
		}

		do
		{
			trocas = FALSE;
			k = 0;
			while (k < Malunos - 1) 
			{	if (vDepois[k] < vDepois[k + 1]) // se o numero for menor que o proximo
				{	aux = vDepois[k]; 
					vDepois[k] = vDepois[k + 1];
					vDepois[k + 1] = aux; 

					trocas = TRUE; // troca de lugar e indica que ainda ha trocas a fazer
				}
				k++;
			}
		} while (trocas == TRUE);

		for(d=0; d < Malunos; d++)
			if (vAntes[d] == vDepois[d]) // analisa o numero das duas listas ao mesmo tempo, se esta igual nao trocou de lugar
				qtd++;

		printf("%d\n", qtd);
	}

	return 0;
}
