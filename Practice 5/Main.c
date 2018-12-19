#include <stdio.h>
#include <math.h>
int main(){
	
	int n,j;
	double fatorial = 1;
	double x,aux,seno,divisao,diferenca;
	double potencia = 1;
	int control = 1;
	int oi;
	
	scanf("%lf %d",&x,&n);
	
	
	seno = sin(x);
	int i;
	for(i = 0;i < n;i++ ){
		
		oi = (2 * i) + 1;
		
		for(j = 1;j <= oi;j++){
			fatorial = fatorial * j;
		}
		potencia = pow(x,oi);
		divisao = potencia / fatorial;
			
			
			
		if(control == 0){
			control = 1;
			aux = aux - divisao;
		}else if (control == 1){
			control = 0;
			aux = aux + divisao;
		}
			
		fatorial = 1;
		potencia = 1;
	}
	
	diferenca = fabs(aux - seno);
	
	printf("O erro obtido eh %e.\n",diferenca);
	
	return 0;
}
