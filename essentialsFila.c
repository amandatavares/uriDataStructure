// funcao para verificar se a fila est� vazia, ou seja, de prox aponta para NULL. se estiver, retorna 1, true.
int vazia(node *FILA)
{
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;
}

// aloca mem�ria para cada n� da nossa fila
node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}

