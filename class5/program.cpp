#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int transfer(int sum){	
	if(sum <= 0){
		return 0;
	}
	else if(sum > 0){
		return 1; 
	}
}

struct Values{
	
	// inputs[0] to [2] are the input values.
	// input[3] is the viés.

	int inputs[3];
	int expected;
	int sum;
	int output;
};

int main(){
	int weight[3];
	struct Values values[4]; 
	int x = 0;

	// pelé
	values[0].inputs[0] = 0;
	values[0].inputs[1] = 0;
	values[0].inputs[2] = 1;

	
	values[0].expected = 0;


	// Zico

	values[1].inputs[0] = 0;
	values[1].inputs[1] = 1;
	values[1].inputs[2] = 1;

	values[1].expected = 0;
	
	// Senna 

	values[2].inputs[0] = 1;
	values[2].inputs[1] = 0;
	values[2].inputs[2] = 1;

	values[2].expected = 1;

	// Piquet

	values[3].inputs[0] = 1;
	values[3].inputs[1] = 1;
	values[3].inputs[2] = 1;

	values[3].expected = 1;

	//weight

	weight[0] = -1; 
	weight[1] = -1; 
	weight[2] = 1;



	while(values[0].output != values[0].expected || values[1].output != values[1].expected || values[2].output != values[2].expected || values[3].output != values[3].expected){

		values[x].sum = (weight[0] * values[x].inputs[0]) + (weight[1] * values[x].inputs[1]) + (weight[2] * values[x].inputs[2]);
		values[x].output = transfer(values[x].sum);

		if(values[x].output != values[x].expected){

			for(int y=0; y < sizeof(weight); y++){
				weight[y] = weight[y] + 1 * (values[x].expected - values[x].output) * values[x].inputs[y];
			}

		}

		if(x == 3){
			x = 0;
		}else{
			x++;
		} 
	}

	int op;
	do{
		// The neuron will respond based on the input and its training. 
		// Pelé and Zico are soccer players (0) , Senna and Piquet are F1 racers(1)
		
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
				printf("output : %d \n", values[0].output);
				break;
			case 2:
				printf("output : %d \n", values[1].output);
				break;
			case 3:
				printf("output : %d \n", values[2].output);
				break;
			case 4:
				printf("output : %d \n", values[3].output);
				break;
		}
	}while(op != 5);

	return 1;
}