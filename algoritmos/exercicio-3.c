#include<stdio.h>

typedef struct Array{
     int array[51];
} Array;

Array getArray(int);
Array orderArray(int, Array, int);

int main (void){

     int i, qtd, num;
     Array array;

     printf("Insira quantos numeros serao lidos: ");
     scanf("%d", &qtd);

     printf("\n");
     array = getArray(qtd);

     printf("\nInsira um numero que sera ordenado: \n");
     scanf("%d", &num);

     array = orderArray(qtd, array, num);


     printf("\n\nSegue abaixo o array ordenado: \n");

     for (i = 0; i <= qtd; ++i){
          printf("Array da posicao %d: %d\n", i, array.array[i]);
     }


     return 0;
}

Array getArray(int qtdNum){

     int i;

     Array array;

     for (i = 0; i < qtdNum; ++i){
          printf("Insira o valor da posicao [%d] do array: ", i);
          scanf("%d", &array.array[i]);
     }

     return array;
}


Array orderArray(int qtdnum, Array array, int num){

     int i, c, aux, indice = 0;

     // logica para ordenar o array
     for (i = 0; i < qtdnum; ++i){

          for (c = i; c < qtdnum; ++c){

               if (array.array[c] < array.array[i]){
                    aux = array.array[i];
                    array.array[i] = array.array[c];
                    array.array[c] = aux;
               }
          }
     }


     // variavel auxiliar para pegar a proxima posicao do array
     aux = 1;

     // percorrendo array
     for (i = 0; i < qtdnum; ++i){

          // logica para verificar entre quais posicoes esta o meu numero e guardar o indice
          if (num >= array.array[i] && num <= array.array[aux]){
               indice = ++i;
          }

          aux++;
     }

     // fiz dessa forma para que nao altera-se o valor da variavel qtdnum
     aux = qtdnum;
     aux--;

     // logica para reordernar os array
     for (i = qtdnum; i >= 0 ; i--){

          while (i > indice){

               if (aux >= 0){
                    array.array[i] = array.array[aux];
               }

               i--; aux--;
          }

          if (i == indice && aux >= 0){
               array.array[indice] = num;
          }

          // caso o usuario insira um novo numero diferente dos numeros do array
          else if (i == indice && aux < 0){
               array.array[indice] = num;
          }

          else if (i < indice && aux >= 0){
               array.array[i] = array.array[i];
          }

          aux--;
     }


     return array;
}
