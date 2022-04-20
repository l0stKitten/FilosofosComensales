#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

//Definimos globalmente un número de filosofos
#define NUM_FILOSOFOS 5

// Metodo filosofo comer
void *comer (void *arg);

//Recurso principal
int variable = 0;

int main(void){
	//Array de nombres de filósofos
	char nomFilo[10][20] = {"Confucio", "Pitágoras", "Platón", "Sócrates", "Epicurio", "Tales", "Heráclito", "Diógenes", "Sófocles", "Zenón"};
	
	//Estado de los nombres
	int estNom[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	printf("Variable: %d \n", variable);
	
	pthread_t filosofos[NUM_FILOSOFOS];
	//int identificadores[NUM_FILOSOFOS];

	int i;
	int j;
	//Creacion de los filosofos
	for (i = 0; i < NUM_FILOSOFOS; i++){
		//Si el nombre no ha sido usado, NUM_FILOSOFOS < 10
		if (i%10 == 0){
			j = 0;
		}
		if (estNom[j] == 0){
			pthread_create(&filosofos[i], NULL, &comer, &nomFilo[j]);
			estNom[j] += 1;
		//Si el nombre ha sido usado, NUM_FILOSOFOS > 10
		} else{
			char num[1];
			snprintf(num, sizeof(num), "%d", estNom[j]);
			strcat(nomFilo[j], num);
			pthread_create(&filosofos[i], NULL, &comer, &nomFilo[j]);
			estNom[i] += 1;
		}
		j++;
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
	
	printf("Variable: %d \n", variable);

	return 0;
}

//Se hace uso del recurso compartido
void *comer (void *arg){

	char *nombre = (char *)arg;
	//int ident = *((int *)arg);
	for (int i=1; i<=3; i++){
		variable = variable + 1;
		printf("Filósofo - %s está comiendo : %d . Variable = %d \n", nombre, i, variable);
	}
	return NULL;
}
