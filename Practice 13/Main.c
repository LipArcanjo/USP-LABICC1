/* Autor: Luan Icaro Pinto Arcanjo.
 * 
 * Dia: 19/06/2018
 * 
 * Universidade De São Paulo
 * 
 * 
 * 
 * */

#include <stdio.h>
#include <string.h>

int verificaPalindromo(char* frase, int posEsq, int posDir){
	
	
	//Este bloco faz ignorar o espaço da frase
	int true = 1;
	while(true == 1){
		if(frase[posEsq] == ' '){
			posEsq++;
		}else{
			true = 0;
		}
	}
	true = 1;
	while(true == 1){
		if(frase[posDir] == ' '){
			posDir--;
		}else{
			true = 0;
		}
	}
	
	//caso de parada
	if(posEsq > posDir){
		return 0;
	}
	else{
		//transforma o caracter em maiusculo
		if((int)frase[posEsq] > 90){
			frase[posEsq] = (int)frase[posEsq] - 32;
		}
		if((int)frase[posDir] > 90){
			frase[posDir] = (int)frase[posDir] - 32;
		}
		
		//faz  a recursão se os dois caracteres forem iguais
		if(frase[posEsq] == frase[posDir]){
			return verificaPalindromo(frase, posEsq + 1,posDir - 1);
		}else{
			return 1;
		}	
	} 
	
}

int main(){
	
	char frase[1024];
	//leitura
	fgets(frase,1024,stdin);
	
	int verPalindromo = 0;
	//fuscao recursiva
	verPalindromo = verificaPalindromo(frase,0,strlen(frase) - 1);
	
	if(verPalindromo == 0){
		printf("PALINDROMO!");
	}else{
		printf("Nao e palindromo. Ufa!");
	}
	
	return 0;
}
