/*	Autor: Luan Ícaro Pinto Arcanjo
 * 
 * 	Dia: 26/06/2018
 * 
 * 	Universidade de Sao Paulo
 * */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int ano_atual;
	scanf("%d", &ano_atual);
	int potenciaDeDez;
	int i = 0;
	//Procura a potencia de 10 mais proxima e acima do ano dado
	for(i = 0; i < 10; i++){
		if(pow(10,i) > ano_atual){
			potenciaDeDez = i;
			break;
		}
	}
	//pega o algorismo de maior valor do ano dado
	int ult_algarismo;
	// divide pela potencia de 10 mais proxima por baixo do ano
	ult_algarismo = (int)ano_atual / (int)pow(10, potenciaDeDez - 1); 
	
	
	//ano sorte vai ser dado pela forma a seguir
	//
	int ano_sorte;
	ano_sorte = (ult_algarismo + 1) * (pow(10,potenciaDeDez - 1));
	//diferenca ehh quantos anos faltam para o ano de sorte
	int diferenca = ano_sorte - ano_atual;
	
	if(diferenca == 1){
		printf("Falta %d ano.", diferenca);
	}else{
		printf("Faltam %d anos.", diferenca);
	}
	
	
	return 0;
}

