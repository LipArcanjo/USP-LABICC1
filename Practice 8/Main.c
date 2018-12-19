/* Este programa resolve o exercicio:
 * O jogo de campo minado é jogado em uma campo n x m, n sendo o número de linhas, e m o número de colunas. Nesse campo são escondidas k minas em posições distintas. 
 * função do jogador é selecionar posições do campo em que não hajam minas escondidas, caso contrário, ele perde o jogo. Caso uma posição sem mina seja escolhida, 
 * um inteiro entre 0 e 8 aparece, revelando quantas bombas estão presentes na região adjacente ou diagonalmente adjacente à posição escolhida.
 * 
 * Sua tarefa aqui é escrever a configuração final de um campo minado, aplicando as regras descritas acima. 
 * A entrada do seu programa serão dois inteiros n e m correspondendo ao tamanho do campo a ser lido. Em seguida, uma matriz contendo os elementos do campo,
 *  sendo que . representa os espaços sem bomba e * representa as minas escondidas. Como saída do programa, você deve imprimir a matriz que representa a configuração final do campo
 * , substituindo os caracteres de espaço sem bomba . pelo número correto.
 * 
 * Autor: Luan Icaro Pinto Arcanjo
 * Data: 08/05/2018
 * 
 * */

#include <stdio.h>

char celula(int n,int m,char mat[n][m],int i,int j){
	
	if(mat[i][j] == '*'){
		return '*';
	}
	else{
		int a,b;
		int contador = 0;
		for(a = -1;a < 2;a++){
			for (b = -1; b < 2;b ++){
				
				if(i + a >= 0 && j + b >= 0 && i + a < n && j + b < m){
					if(mat[i + a][j + b] == '*')
					contador += 1;
					
				}
			}
		}
		
		char c = contador + '0';
		return c;
	}
	
	
	
}

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
		
	char mat[n][m];
	char matf[n][m];
	for(i = 0;i < n; i++){
		for (j = 0; j < m;j++){
			scanf(" %c",&mat[i][j]);
		}
	}
	
	for(i = 0;i < n; i++){
		for (j = 0; j < m;j++){
		matf[i][j] =	celula(n,m,mat,i,j);
		}
		
	}
	
	for(i = 0;i < n; i++){
		for (j = 0; j < m;j++){
			printf("%c ",matf[i][j]);
		}		
		printf("\n");
	}
	
	
}
