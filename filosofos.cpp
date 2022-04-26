#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Definimos globalmente un número de filosofos
#define NUM_FILOSOFOS 5

// Metodo filosofo comer
void *comer (void *arg);

//Método para imprimir acción
void printAccion (int acc, char* nom);

//Método para encontrar la posición del Filósofo
int posicion(char* nom);

//Método para coger los tenedores
void tomarTenedor(char* nom);

//Recurso principal
int variable = 0;

//Tenedores
int tenedores[NUM_FILOSOFOS];

//Acciones de los filosofos
//0 = pensar
//1 = tomar tenedor derecho
//2 = tomar tenedor izquierdo
//3 = comer
int accion_Filo[NUM_FILOSOFOS];

//Nombres de los filósofos
char nomFilo[10][20] = {"Confucio", "Pitágoras", "Platón", "Sócrates", "Epicurio", "Tales", "Heráclito", "Diógenes", "Sófocles", "Zenón"};

int main(void){
	//Array de nombres de filósofos
	
	int i;
	int j;

	//Estado de los nombres
	int estNom[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	printf("Variable: %d \n", variable);
	
	pthread_t filosofos[NUM_FILOSOFOS];
	//int identificadores[NUM_FILOSOFOS];
	
	//Inicialización de los tenedores y estado de los filosofos
	for (i = 0; i < NUM_FILOSOFOS; i++){
		tenedores[i] = i;
		accion_Filo[i] = 0;
	}

	//Creacion de los filosofos
	for (i = 0; i < NUM_FILOSOFOS; i++){
		//Si el nombre no ha sido usado, NUM_FILOSOFOS < 10
		if (i%10 == 0){
			j = 0;
		}
		if (estNom[j] == 0){
			pthread_create(&filosofos[i], NULL, &comer, &nomFilo[j]);
			estNom[j] += 1;
			accion_Filo[i] = 0;
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

//Imprimir acción
void printAccion(int acc, char* nom){
	if (acc == 0){
		printf("Filósofo %s está pensando", nom);
	}else if(acc == 1){
		printf("Filósofo %s levanta tenedor derecho", nom);
	}else if (acc == 2){
		printf("Filósofo %s levanta tenedor izquierdo", nom);
	}else if (acc == 3){
		printf("Filósofo %s está comiendo", nom);
	}
}

//Encontrar posición del filósofo
int posicion(char* nom){
	int pos = 0;
	for (int i = 0; i < NUM_FILOSOFOS; i++){
		if (nomFilo[i] == nom){
			pos = i;
			break;
		}
	}
	return pos;
}

//Tomar el tenedor
void tomarTenedor(char* nom){
	
}

//Se hace uso del recurso compartido
void *comer (void *arg){

	char *nombre = (char *)arg;
	//int ident = *((int *)arg);
	/*for (int i=1; i<=3; i++){
		variable = variable + 1;
		printf("Filósofo %s está comiendo : %d . Variable = %d \n", nombre, i, variable);
	}*/
	//Levanta el tenedor derecho
	
	
	return NULL;
}
