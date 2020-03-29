#include <stdio.h>

/* exercicio 1
 * Escreva um programa que permita trocar o segundo elemento do array com o segundo
 * último elemento.
 */

typedef struct Array{
	int array[10];
} Array;


Array getArray(int);
Array trocarElemento(int, Array);

int main(void){

	int i, qtd;
	Array array;


	printf("Insira quantos numeros serao lidos para o array (minimo de 4 numeros): ");
	scanf("%d", &qtd);

	if (qtd < 4){
		printf("Deve ser inserido no minimo 4 numeros, o programa sera encerrado. Por favor tente novamente.\n");
		return 0;				
	}

	printf("\n");

	//metodo para ler os numeros do array
	array = getArray(qtd);

	//metodo para trocar o segundo e o penultimo elemento do array
	array = trocarElemento(qtd, array);


	printf("\n\nSegue o array com o segundo elemento e o segundo ultimo elemento trocados: \n");
	for (i = 0; i < qtd; ++i){
		printf("Indice %d: %d\n", i, array.array[i]);
	}

	return 0;
}

Array getArray(int qtd){

	int i;

	Array array;

	for (i = 0; i < qtd; ++i){
		printf("Insira o valor da posicao [%d] do array: ", i);
		scanf("%d", &array.array[i]);
	}

	return array;
}

Array trocarElemento(int qtd, Array array){

	int i, aux, segelem = 0, penelem = 0;

	aux = qtd - 2;
	for (i = 0; i < qtd; ++i){
		if (i == 1){
			segelem = array.array[i];
		}
		else if (i == aux){
			penelem = array.array[i];
		}
	}

	aux = qtd - 2;
	for (i = 0; i < qtd; ++i){
		if (i == 1){
			array.array[i] = penelem;
		}
		else if (i == aux){
			array.array[i] = segelem;
		}
	}

	return array;
}
