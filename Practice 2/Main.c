#include <stdio.h>

int main(){
	int a,b,c,d, idade1, idade2,control,i,j;
	scanf("%d %d",&a,&b);
	
	for(i = 0; i <1000;i++){
		
		for(j = 0; j < 1000; j++){
			c = i + j;
			d = i * j;
			if(c == a && d == b){

					idade1 = i;
					idade2 = j;
				
			}
		}
	}
	
	if(idade1 > idade2){
		control = idade1;
		idade1 = idade2;
		idade2 = control;
	}
	
	printf("As idades sao %d e %d anos.",idade1,idade2);
}
