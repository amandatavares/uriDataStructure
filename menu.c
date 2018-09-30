int menu(void)
{
	int opt;

	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar fila\n");
	printf("2. Exibir fila\n");
	printf("3. Adicionar Elemento na Fila\n");
	printf("4. Retirar Elemento da Fila\n");
	printf("Opcao: "); scanf("%d", &opt);

	return opt;
}

void opcao(node *FILA, int op)
{
	node *tmp;
	switch(op){
		// sair
		case 0:
			free(FILA);
			break;

		// zerar a fila
		case 1:
			free(FILA);
			inicia(FILA);
			break;

		// exibir a fila
		case 2:
			exibe(FILA);
			break;

		// adicionar elemento na fila
		case 3:
			insere(FILA);
			break;

		// retirar elemento da fila
		case 4:
			tmp= retira(FILA);
			if(tmp != NULL){
				printf("Retirado: %3d\n\n", tmp->num);
				free(tmp);
			}
			break;

		default:
			printf("Comando invalido\n\n");
	}
}



