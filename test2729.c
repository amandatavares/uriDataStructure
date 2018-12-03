#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ordena(const void *a, const void *b);

int main(int argc, char** argv)
{
	char vetor_nomes[1700][100], nome[1000000], *ponteiro, auxiliar[1700][100];
	int teste, cont1, cont2;
	scanf("%d", &teste);
	while(teste--)
	{
		getchar();
		scanf("%[^\n]", nome);
		cont1 = 0, cont2 = 0;
		ponteiro = strtok(nome, " ");
		while(ponteiro != NULL)
		{
			strcpy(vetor_nomes[cont1], ponteiro);
			cont1++;
			ponteiro = strtok(NULL, " ");
		}
		qsort((void*)vetor_nomes, cont1, sizeof(vetor_nomes[0]), ordena);
		for(int i = 0; i < cont1; i++)
		{
			if(!strcmp(vetor_nomes[i], vetor_nomes[i + 1]) == 0)
			{
				strcpy(auxiliar[cont2], vetor_nomes[i]);
				cont2++;
			}
		}
		printf("%s", auxiliar[0]);
		for(int i = 1; i < cont2; i++)
		{
			printf(" %s", auxiliar[i]);
		}
		printf("\n");
	}
	return 0;
}

int ordena(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}
