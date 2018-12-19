/* 	Resolução do exercicio :
*	O ângulo entre dois vetores, em qualquer dimensão, pode ser calculado utilizando-se o produto escalar entre eles, ou seja, angle, em que:
*
*   u e v representam os vetores;
*   é o produto escalar, dado pelo produto entre cada coordenada do vetor;
*   |u| é a norma do vetor, dada pela raiz quadrada da soma dos quadrados das coordenadas do vetor;
*   θ é o do ângulo formado entre os vetores, que queremos calcular
*
*	Para esse exercício, você deve criar uma função que receba como parâmetro os vetores a serem processados e retorne o ângulo formado entre eles, em graus.
*
*	A entrada do seu programa será um inteiro d, representando a dimensão em que se está calculando o ângulo, seguido de uma linha com d valores de ponto flutuante, 
* 	representando as coordenadas do primeiro vetor e outra linha com as d coordenadas do segundo vetor. A saída do seu programa deve imprimir o ângulo entre os dois vetores (em graus), 
* 	utilizando duas casas decimais.
* 
* 	Autor: Luan Icaro Pinto Arcanjo
* 	Data: 08/05/2018
*/
#include <stdio.h>
#include <math.h>

double angulo(int d,float * u,float* v){
	
	double prod_escalar = 0,  mod_u = 0, mod_v = 0, mod_uv, cos, rad, ang;
	int i;
	for(i = 0; i < d; i++){
		prod_escalar += u[i] * v[i];
		mod_u += u[i] * u[i];
		mod_v += v[i] * v[i];
	}
	mod_u = sqrt(mod_u);
	mod_v = sqrt(mod_v);
	mod_uv = mod_u * mod_v;
	
	cos = prod_escalar / mod_uv;
	
	rad = acos(cos);
	
	ang =  (rad * 180) / acos(-1);
	
	return ang;
}

int main(){
	int d;
	scanf("%d", &d);
	
	float u[d];
	float v[d];
	int i;
	for(i = 0; i < d; i++){
		scanf("%f", &u[i]);
	}
	for(i = 0;i < d; i++){
		scanf("%f", &v[i]);
	
	}
	
	
	double ang = angulo(d, u, v); 
	
	printf("%.2lf graus.",ang);
	return 0;
}
