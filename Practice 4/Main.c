#include <stdio.h>

int main(){

	char notacao,operador;
	int n1,n2,n3,aux;

	scanf("%c",&notacao);

	switch(notacao){
		case 'E':
			scanf(" %c %d %d",&operador,&n1,&n2);
		break;
		case 'I':
			scanf("%d %c %d",&n1,&operador,&n2);
		break;
		case 'O':
			scanf("%d %d %c",&n1,&n2,&operador);
		break;
		default:
			scanf("%c %d %d",&operador,&n1,&n2);

	}

	switch(operador){

		case '+':
			n3 = n1 + n2;
		break;
		case '-':
			n3 = n1 - n2;
		break;
		case ':':
			n3 = n1 / n2;
		break;
		case 'x':
			n3 = n1 * n2;
		break;
		default:
			n3 = n1 * n2;
	}

	aux = n3 % 2;

	switch(aux){
		case 0:
			printf("O resultado %d eh par.",n3);
		break;
		default:
			printf("O resultado %d eh impar.",n3);
	}

	return 0;
}