#include <stdio.h>
#include <stdbool.h>

/* exercicio 2
 * Escreva um programa que leia um array de 100 elementos. Escreva todos os pares de
 * elementos tal que sua suma seja menor que 50.
 */

typedef struct Array{
	int array[100];
} Array;

//variável utilizada para os indices do array que será lido
static int qtd = 100;

Array popularArray(int);
void somarElementos(Array);

int main(void){

	int decisao;
    Array array;

    printf("\nCaso queira inserir os valores do array insira '1', caso nao queira inserir os valores insira '0': ");
    printf("(os valores serao preenchidos automaticamente)\n");
    scanf("%d", &decisao);

	//metodo para popular o array
	array = popularArray(decisao);

	//metodo para para somar os elementos do array
	somarElementos(array);

	return 0;
}

Array popularArray(int decisao){

	int i, count = 1;

	Array array;

    if (decisao == 1) {
        for (i = 0; i < qtd; ++i){
		printf("Insira o valor do indice %d do array: ", i);
		scanf("%d", &array.array[i]);
	    }
    } else {
        for (i = 0; i < qtd; i++) {
            array.array[i] = count;
            count++;
        }
    }

	return array;
}

void somarElementos(Array array){

	int i, count = 1, somaarray = 0;

    for (i = 0; i < qtd; i++) {
        somaarray = array.array[i] + array.array[count];
        if (somaarray < 50) {
            printf("\nIndice do array[%d] valor: %d, ", i, array.array[i]);
            printf("indice do array posterior[%d], valor %d, ", count, array.array[count]);
            printf("soma dos pares: %d\n\n", somaarray);
        }
        count++;
    }
}
