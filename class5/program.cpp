#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int transferencia(int saida){	
	if(saida <= 0){
		return 0;
	}
	else if(saida > 0){
		return 1; 
	}
}

struct Values{
	
	int entradas[3];
	int expected;
	int ponderado;
	int saida;
};

int main(){
	int pesos[3];
	struct Values values[4]; 
	int x = 0;

	// pelé
	values[0].entradas[0] = 0;
	values[0].entradas[1] = 0;
	values[0].entradas[2] = 1;

	
	values[0].expected = 0;


	// Zico

	values[1].entradas[0] = 0;
	values[1].entradas[1] = 1;
	values[1].entradas[2] = 1;

	values[1].expected = 0;
	
	// Senna 

	values[2].entradas[0] = 1;
	values[2].entradas[1] = 0;
	values[2].entradas[2] = 1;

	values[2].expected = 1;

	// Piquet

	values[3].entradas[0] = 1;
	values[3].entradas[1] = 1;
	values[3].entradas[2] = 1;

	values[3].expected = 1;

	//pesos

	pesos[0] = -1; 
	pesos[1] = -1; 
	pesos[2] = 1;


	while(values[0].saida != values[0].expected || values[1].saida != values[1].expected || values[2].saida != values[2].expected || values[3].saida != values[3].expected){

		values[x].ponderado = (pesos[0] * values[x].entradas[0]) + (pesos[1] * values[x].entradas[1]) + (pesos[2] * values[x].entradas[2]);
		values[x].saida = transferencia(values[x].ponderado);

		if(values[x].saida != values[x].expected){

			for(int y=0; y < sizeof(pesos); y++){
				pesos[y] = pesos[y] + 1 * (values[x].expected - values[x].saida) * values[x].entradas[y];
			}

		}

		if(x == 3){
			x = 0;
		}else{
			x++;
		} 
		printf("* \n");
	}

	int op;

	do{
		printf("\n informe qual deseja ver: \n");
		printf("1 - pelé \n");
		printf("2 - Zico \n");
		printf("3 - Senna \n");
		printf("4 - Piquet \n");
		printf("5 - Sair \n");
		

		scanf("%d", &op);
		fflush(stdin);

		switch(op){
			case 1: 
				printf("saida : %d \n", values[0].saida);
				break;
			case 2:
				printf("saida : %d \n", values[1].saida);
				break;
			case 3:
				printf("saida : %d \n", values[2].saida);
				break;
			case 4:
				printf("saida : %d \n", values[3].saida);
				break;
		}
	}while(op != 5);

	return 1;
}