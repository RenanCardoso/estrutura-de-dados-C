#include <stdio.h>

/* Escreva um programa que permita a leitura de um array ordenado. Como parte do
 * programa um elemento deve ser definido como dado e esse elemento deve ser
 * eliminado do array. O resultado final deve ser a impressão do array sem esse elemento
 * eliminado. Note-se que para procurar o elemento dentro de array é suficiente procurar
 * nos elementos menores ao elemento procurado
 */

typedef struct Array{
     int array1[10];
     int array2[10];
} Array;

Array getArray(int, Array);
Array deleteNumberArray(int, Array, int);
Array orderArray(int, Array);

int main (void){

     int i, qtd, del;
     Array array;

     printf("Insira quantos numeros serao lidos: ");
     scanf("%d", &qtd);

     printf("\n");
//  metodo para ler os numeros do array
     array = getArray(qtd, array);

//  metodo para ordenar o array 
     array = orderArray(qtd, array);

     printf("Insira qual o vetor que voce quer eliminar: ");
     scanf("%d", &del);

// metodo para deletar um numero do array
     array = deleteNumberArray(qtd, array, del);

     printf("\n\nSegue abaixo os vetores na ordem que foram inseridos: \n");

     for (i = 0; i < qtd; ++i)
          printf("Valor do vetor %d: %d\n", i, array.array1[i]);

     printf("\n\nSegue abaixo os vetores reordenados: \n");
//  utilizei qtd-1 pois como foi eliminado um elemento do array eu terei uma posicao de memoria a menos para percorrer
     for (i = 0; i < qtd-1; ++i){
        printf("Valor do vetor %d: %d\n", i, array.array2[i]);
     }

    return 0;
}

Array getArray(int qtd, Array array){

     int i;

    printf("Nao se preocupe, seu array sera ordenado automaticamente.\n\n");
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


Array orderArray(int qtdnum, Array array){

     int i, c, aux, indice = 0;

     // logica para ordenar o array
     for (i = 0; i < qtdnum; ++i){
        for (c = i; c < qtdnum; ++c){
               if (array.array1[c] < array.array1[i]){
                    aux = array.array1[i];
                    array.array1[i] = array.array1[c];
                    array.array1[c] = aux;
                }
        }
    }

    return array;
}