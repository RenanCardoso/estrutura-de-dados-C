#include <stdio.h>

/* Escreva um programa que permita a leitura de um array NÂO rodenado. Como parte do
 * programa um elemento deve ser definido como dado e esse elemento deve ser eliminado
 * do array. O resultado final deve ser a impressão do array sem esse elemento eliminado.
 */

typedef struct Array{
     int array1[10];
     int array2[10];
} Array;

Array getArray(int, Array);
Array deleteNumberArray(int, Array, int);

int main (void){

     int i, qtd, del;
     Array array;

     printf("Insira quantos numeros serao lidos: ");
     scanf("%d", &qtd);

     printf("\n");
     array = getArray(qtd, array);

     printf("Insira qual o vetor que voce quer eliminar: ");
     scanf("%d", &del);

     array = deleteNumberArray(qtd, array, del);

     printf("\n\nSegue abaixo os vetores na ordem que foram inseridos: \n");

     for (i = 0; i < qtd; ++i)
          printf("Valor do vetor %d: %d\n", i, array.array1[i]);

     printf("\n\nSegue abaixo os vetores reordenados: \n");
     for (i = 0; i < qtd-1; ++i)
          printf("Valor do vetor %d: %d\n", i, array.array2[i]);


    return 0;
}

Array getArray(int qtd, Array array){

     int i;

     for (i = 0; i < qtd; ++i){
          printf("Insira o valor da posicao [%d] do array: ", i);
          scanf("%d", &array.array1[i]);
     }

     return array;
}


Array deleteNumberArray(int qtd, Array array, int del){

     int i, aux;

     //variável auxiliar para pegar o valor do próximo vetor e guardá-lo no vetor que foi deletado.
     aux = del + 1;

     //laço para aplicar lógica acima em todos os vetores.
     for (i = 0; i < qtd; ++i) {
          array.array2[i] = array.array1[i];

          if (i == del) {
               array.array2[del] = array.array1[aux];
               del++, aux++;
          }

     }

     return array;
}