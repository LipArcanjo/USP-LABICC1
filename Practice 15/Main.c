/*	Autor: Luan Ícaro Pinto Arcanjo
 * 
 * 	Dia: 26/06/2018
 * 
 * 	Universidade de Sao Paulo
 * */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	int idade = 0;
	scanf("%d",&idade);
	
	int* velas;
	velas = (int *)malloc(sizeof(int) * idade);
	
	for(i = 0; i < idade; i++){
		
		velas[i] = 0;
		
	}
	
	int tempVela;
	for(i = 0; i < idade; i++){
		
		scanf("%d",&tempVela);
		velas[tempVela] = velas[tempVela] + 1;
		
	}
	//esse for faz  com que o maior valor que tem no velas fique na velas[idade - 1]
	for(i = 0; i < idade - 1; i++){
		if(velas[i] > velas[i + 1]){
			
			tempVela = velas[i];
			velas[i] = velas[i + 1];
			velas[i + 1] = tempVela;
		}
	}
	
	if(velas[idade - 1] == 1){
		printf("%d desejo realizado.", velas[idade - 1]);
	}else{
		printf("%d desejos realizados.", velas[idade - 1]);
	}
	
	free(velas);
	return 0;
}
