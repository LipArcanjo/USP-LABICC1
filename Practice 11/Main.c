/* Dia: 05/06/2018
 * 
 * Autor: Luan Ícaro Pinto Arcanjo
 * 
 * Universidade de São Paulo
 * 
 * 
 * 
 * 
 * 
 * */

#include <stdio.h>
#include <string.h>
typedef struct{
	int hora;
	int min;
	int seg;
}Tempo;

typedef struct{
	char nome[31];
	Tempo tempoInicio;
	Tempo tempoFim;
	Tempo Duracao;
}Competidor;

void calculaDuracao(Competidor* comp){
	//transforma o tempo em segundos
	int TempIniSegundos = (comp->tempoInicio.hora * 3600) + (comp->tempoInicio.min * 60) + comp->tempoInicio.seg;
	int TempFimSegundos = (comp->tempoFim.hora * 3600) + (comp->tempoFim.min * 60) + comp->tempoFim.seg;
	
	int DuracaoEmSegundos;
	if(TempFimSegundos > TempIniSegundos){
		DuracaoEmSegundos = TempFimSegundos - TempIniSegundos;
	}else{
	//se passar para o outro dia adiciona o tempo de um dia inteiro
		DuracaoEmSegundos = TempFimSegundos - TempIniSegundos + 86400;
	}
	
	
	comp->Duracao.seg = DuracaoEmSegundos % 60;
	
	comp->Duracao.hora = DuracaoEmSegundos / 3600;
	comp->Duracao.min =   (DuracaoEmSegundos / 60) - (comp->Duracao.hora * 60);
}

int main(){
	
	int quantCompetidores;
	scanf("%d",&quantCompetidores);
	Competidor Competidores[quantCompetidores];
	
	int i, j, numCompLidos = 0;
	//Entrada
	for(i = 0; i < quantCompetidores * 2; i++){
		
		char tempNome[31];
		int control = 0, numCompetidor;
		scanf("%s ",tempNome);
		//verifica se o nome lido já apareceu anteriormente
		for(j = 0;j < numCompLidos;j++){
			
			if (strcmp(Competidores[j].nome,tempNome) == 0){
				control = 1;
				numCompetidor = j;
				break;
			}
		}
		//Se for um nome já mostrado guarda o tempo Fim, se nao guarda o tempo inicio
		if(control == 1){
			scanf("%d:%d:%d", &Competidores[numCompetidor].tempoFim.hora,  &Competidores[numCompetidor].tempoFim.min,  &Competidores[numCompetidor].tempoFim.seg);
		}else{
			strcpy(Competidores[numCompLidos].nome,tempNome);
			scanf("%d:%d:%d", &Competidores[numCompLidos].tempoInicio.hora,  &Competidores[numCompLidos].tempoInicio.min,  &Competidores[numCompLidos].tempoInicio.seg);
			numCompLidos++;
		}
		
		control = 0;
		
	}
	
	for(i = 0; i < quantCompetidores; i++){
		calculaDuracao(&Competidores[i]);
		printf("%s levou %02d:%02d:%02d.\n",Competidores[i].nome, Competidores[i].Duracao.hora, Competidores[i].Duracao.min, Competidores[i].Duracao.seg);
	}
	
	return 0;
}
