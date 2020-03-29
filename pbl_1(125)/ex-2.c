#include <stdio.h>
#include <stdbool.h>

/* exercicio 2
 * Escreva um programa que leia um array de 100 elementos. Escreva todos os pares de
 * elementos tal que sua suma seja 50.
 */

typedef struct Array{
	int array1[100];
	int array2[100];
	int qtdelementos;
	int indice[100];
	int condicao;
} Array;

//variável utilizada para os indices do array que será lido
static int qtd = 100;

Array popularArray();
Array somarElementos(Array);

int main(void){

	int i, aux = 1;
	Array array;
	int soma50;

	//metodo para popular o array
	array = popularArray();

	//metodo para trocar o segundo e o penultimo elemento do array
	array = somarElementos(array);

	//utilizado para verificar se na leitura do array houve algum cujo a condicao foi verdadeira
	soma50 = array.condicao;

	if (soma50 == 1){
		printf("\n\nSegue o array cujo a soma dos pares de elementos e igual a 50: \n");
		for (i = 0; i < array.qtdelementos; ++i){
			printf("Array de indice %d: %d array de indice %d: %d soma = %d\n", array.indice[i], array.array2[i], array.indice[aux], array.array2[aux], (array.array2[i] + array.array2[aux]));
			aux++;
		}
	} else {
		printf("\n\nNao houve um array cujo a soma dos pares de elementos seja igual a 50 !!!\n\n");
	}



	return 0;
}

Array popularArray(){

	int i;

	Array array;

	for (i = 0; i < qtd; ++i){
		printf("Insira o valor do indice %d do array: ", i);
		scanf("%d", &array.array1[i]);
	}

	return array;
}

Array somarElementos(Array array){

	int i, qtdelemen = 0, aux = 1, c = 0, caux = 1;;

	array.condicao = 0;

	for (i = 0; i < qtd; ++i){
		if (array.array1[i] + array.array1[aux]  == 50){
			array.condicao = 1;
			array.array2[c] = array.array1[i];
			array.indice[c] = i;

			array.array2[caux] = array.array1[aux];
			array.indice[caux] = aux;
			qtdelemen++; caux++;
		}
		aux++;
	}

	array.qtdelementos = qtdelemen;
	return array;
}
