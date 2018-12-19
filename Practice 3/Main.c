#include <stdio.h>

int main(){
	float massa,altura,imc,aux;
	
	scanf("%f %f",&massa,&altura);
	
	aux = altura * altura;
	
	imc = massa / aux;
	
	if(imc < 17){
		printf("Muito abaixo do peso.");
	}
	else if(imc < 18.5){
		printf("Abaixo do peso.");
	}
	else if(imc < 25){
		printf("Peso normal.");
	}
	else if(imc < 30){
		printf("Acima do peso.");
	}
	else if(imc < 35){
		printf("Obesidade tipo 1.");
	}
	else if(imc < 40){
		printf("Obesidade tipo 2.");
	}
	else{
		printf("Obesidade tipo 3.");
	}
	
	
	return 0;
}
