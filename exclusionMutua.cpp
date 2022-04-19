#include<stdio.h>
#include<pthread.h>

//Definimos globalmente un número de filosofos
#define NUM_FILOSOFOS 5

// Metodo filosofo comer
void *comer (void *arg);

//Recurso principal
int variable = 0;

int main(void){
	char filo[20] = "Epicuro";
	char filo2[20] = "Confucio";
	
	pthread_t filosofos[NUM_FILOSOFOS];
	int identificadores[NUM_FILOSOFOS];

	int i;
	//Creacion de los filosofos
	for (i = 0; i < NUM_FILOSOFOS; i++){
		identificadores[i] = i+1;
		pthread_create(&filosofos[i], NULL, &comer, &identificadores[i]);
	}

	//Create Inicial
	//pthread_create(&epicurio, NULL, &filosofo, &filo);
	//pthread_create(&confucio, NULL, &filosofo, &filo2);

	//Llamada a la función filosofo, no es necesario, dado que 
	//es el comportamiento del thread.
	//filosofo(filo);
	//filosofo(filo2);
	
	//Joint del arreglo de filosofos
	for (i = 0; i < NUM_FILOSOFOS; i++){
		pthread_join(filosofos[i], NULL);	
	}
	//pthread_join(epicurio, NULL);
	//pthread_join(confucio, NULL);
	
	return 0;
}

//Se hace uso del recurso compartido
void *comer (void *arg){

	//char *nombre = (char *)arg;
	int ident = *((int *)arg);
	for (int i=1; i<=5; i++){
		variable = variable + 1;
		printf("Filósofo - %d está comiendo : %d . Variable = %d \n", ident, i, variable);
	}
	return NULL;
}
