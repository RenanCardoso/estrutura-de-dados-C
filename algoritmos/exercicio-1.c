#include<stdio.h>

int main (void){

     int i, qtd, soma = 0, media, num[50];

     printf("Insira quantas notas serao lidas: \n");
     scanf("%d", &qtd);

     for (i = 0; i < qtd; ++i)
     {
     	printf("Insira a nota da posicao [%d]: \n", i);
     	scanf("%d", &num[i]);
     	soma += num[i];
     }

     media = soma / qtd;

     printf("O valor da media eh: %d\n", media);

    return 0;
}
