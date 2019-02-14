/*Autor: Luan Icaro Pinto Arcanjo
 * 
 *Dia: 12/06/2018 
 * 
 * 
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char *strArqLido = (char *)malloc(sizeof(char) * 100);
	scanf("%s ",strArqLido);
	
	FILE *fpr,*fpw;
	//le o aruivo com o nome recebido, se nao conseguir printa erro e da exit
	if ((fpr = fopen(strArqLido, "r")) == NULL){
		printf("Opa.. Erro ao ler o arquivo original%s \n", strArqLido);
		exit(0);
	}
	//tenta criar o arquivo, se nao der da exit
	if ((fpw = fopen("msgDescriptografada.txt", "w")) == NULL){
		printf("Opa.. Erro ao abrir o arquivo destino msgDescriptografada.txt \n");
		exit(0);
	}
	//vetor de strings
	char palavraIgn[50][100];
	char *tempPalavra = (char *)malloc(sizeof(char) * 100);
	int cont = 0;
	//enquanto tiver entrada no stdin
	while(scanf("%s ",tempPalavra) != EOF){
		strcpy(palavraIgn[cont], tempPalavra);
		cont++;
	}
	//contadores
	int palavraLidas = 0, palavraIgnoradas = 0; 
	//enquanto tiver entrada no arquivo encriptografado
	while(fscanf(fpr,"%s ",tempPalavra) != EOF){
		
		palavraLidas++;
		//ehPalavra funciona como bool
		int i,ehPalavraIgn = 0;
		
		for(i = 0; i < cont; i++){
			//se a palavra lida for da lista de palavras ignoradas
			if(strcmp(tempPalavra,palavraIgn[i]) == 0){
				ehPalavraIgn = 1;
				break;
			}
		}
		
		
		
		if(!ehPalavraIgn){
			//escreve no arquivo de saida
			fputs(tempPalavra, fpw);
			fputs(" ", fpw);
			
		}else{
			palavraIgnoradas++;
		}
		//volta ao valor padrao
		ehPalavraIgn = 0;
	}
	
	printf("Palavras lidas: %d\n",palavraLidas);
	printf("Palavras ignoradas: %d\n",palavraIgnoradas);
	//liberacao de memoria
	free(tempPalavra);
	free(strArqLido);
	fclose(fpr);
	fclose(fpw);
	return 0;
}
