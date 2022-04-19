#include<stdio.h>
#include<pthread.h>

// Metodo filosofo comer
void *filosofo (void *arg);

int main(void){
	char filo[20] = "Epicuro";
	char filo2[20] = "Confucio";
	
	pthread_t epicurio, confucio;
	pthread_create(&epicurio, NULL, &filosofo, &filo);
	pthread_create(&confucio, NULL, &filosofo, &filo2);

	//Llamada a la función filosofo, no es necesario, dado que 
	//es el comportamiento del thread.
	//filosofo(filo);
	//filosofo(filo2);
	
	pthread_join(epicurio, NULL);
	pthread_join(confucio, NULL);
	
	return 0;
}

void *filosofo (void *arg){

	char *nombre = (char *)arg;
	for (int i=1; true; i++){
		printf("%s estoy comiendo : %d \n", nombre, i);
	}
	return NULL;
}
