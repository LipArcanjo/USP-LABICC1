#include <stdio.h>

int main(){
	int n = 0;
	
	scanf("%d",&n);
	int cas[n];
	cas[0] = 0;
	
	
	
	int i = 0,cont = 0,aux = 0;
	for (i = 0; i < n; i++)
	{
		cas[i] = 0;
	}
	while(i != -1){
	
		scanf("%d",&aux);
		if(aux != -1){
			cas[aux] = cas[aux] + 1;
		}
		cont++;
		i = aux;
		
	}
	
	
	printf("%d coelhos catalogados:\n",(cont -1));
	for (i = 0; i < n; i++)
	{
		printf("Casa %d: %d\n",i,cas[i]);
	}
	
	
	
	
	return 0;
	
}
