#include<stdio.h>

// Metodo filosofo comer
void filosofo (char *arg);

int main(void){
	char filo[20] = "Epicuro";
	char filo2[20] = "Confucio";

	filosofo(filo);
	filosofo(filo2);
	
	return 0;
}

void filosofo (char *arg){
	for (int i=1; i<=5; i++){
		printf("%s estoy comiendo : %d \n", arg, i);
	}
}
