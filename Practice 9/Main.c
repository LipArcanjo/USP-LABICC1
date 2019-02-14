#include <stdio.h>
#include <stdlib.h>

int* CriaVetor(int n){
	int* v = (int *)malloc(sizeof(int)*n);
	
	return v;
}

int main(){
	int dias, recPerDia, arqRestantes = 0,recDia = 0,arqDia;
	int controle = 0;
	scanf("%d", &dias);
	scanf("%d", &recPerDia);
	
	int* vetArquivos;
	vetArquivos = CriaVetor(4);
	
	int i,j;
	for (i = 0; i < dias; i++)
	{
		scanf("%d",&arqDia);
		
		vetArquivos = (int *)realloc(vetArquivos, sizeof(int) * (arqDia + arqRestantes));
		
		
		
		for (j = 0; j < arqDia; j++)
		{
			scanf("%d",&vetArquivos[(arqRestantes + j)]);
		}
		
		for (j = (arqDia + arqRestantes); j > 0 ; j--)
		{
			recDia += vetArquivos[j -1];
			
			if(recDia > recPerDia){
				arqRestantes = j;
				controle = 1;
				break;
				
			}else{
				controle = 0;
			}
		}
		if(controle == 0){
			arqRestantes = 0;
		}
		
		if(arqRestantes <= 0){
			printf("Todos os arquivos foram processados.\n");
		}else if(arqRestantes > 1){
			printf("Restam %d arquivos.\n",arqRestantes);
		}else{
			printf("Resta %d arquivo.\n",arqRestantes);
		}
		
		recDia = 0;
		
	}
	free(vetArquivos);
	return 0;
}
