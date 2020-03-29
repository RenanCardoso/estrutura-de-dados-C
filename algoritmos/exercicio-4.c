#include <stdio.h>

/* Fazer um algoritmo que irá receber dois arrays distintos e irá ordenar todos os elementos de ambos arrays.
 */

typedef struct Array{
	int array1[10];
	int array2[10];
	int array3[20];
} Array;

Array getArray(int);
Array orderArray(int, Array);

int main(void){

	int i, qtd;
	Array array;


	printf("Insira quantos numeros serao lidos para todos os arrays: ");
	scanf("%d", &qtd);

	printf("\n");

	//metodo para ler os numeros do array
	array = getArray(qtd);

	//metodo para ordenar os numeros do array
	array = orderArray(qtd, array);

	printf("\n\nNovo array ordenado \n");
	for (i = 0; i < qtd * 2; ++i)
		printf("posicao %d valor: %d\n", i, array.array3[i]);

	
	return 0;
}

Array getArray(int qtdNum){

	int i;

	Array array;

	for (i = 0; i < qtdNum; ++i){
		printf("Insira o valor da posicao [%d] do primeiro array: ", i);
		scanf("%d", &array.array1[i]);
	}

	printf("\n");

	for (i = 0; i < qtdNum; ++i){
		printf("Insira o valor da posicao [%d] do segundo array: ", i);
		scanf("%d", &array.array2[i]);
	}

	return array;
}

Array orderArray(int qtdNum, Array array){

	int i, c, aux;

	// logica usada para guardar os valores dos dois arrays em um array só
	for (i = 0; i < qtdNum; ++i){
		array.array3[i] = array.array1[i];
	}

	for (c = 0; c < qtdNum; ++c){
		array.array3[i] = array.array2[c];
		i++;
	}


	// logica para ordenar o array
	for (i = 0; i < qtdNum * 2; ++i){

		for (c = i; c < qtdNum * 2; ++c){

			if (array.array3[c] < array.array3[i]){
				aux = array.array3[i];
				array.array3[i] = array.array3[c];
				array.array3[c] = aux;
			}
		}
	}

	return array;
}


