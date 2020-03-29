#include <stdio.h>

/* Escreva um programa para permita ler e imprimir uma lista de alunos.
 */

typedef struct Aluno{
	char nome[120];
} Aluno;

Aluno getAluno(Aluno[], int);
void printAluno(Aluno[], int);

int main(void){

	int i, qtd;
	Aluno aluno[10];

	printf("Insira a quantidade de alunos: ");
	scanf("%d", &qtd);

	for (i = 0; i < qtd; i++) {
		aluno[i] = getAluno(aluno, i);	
	}

	for (i = 0; i < qtd; i++) {
 		printAluno(aluno, i);	
	}

	return 0;
}

Aluno getAluno(Aluno aluno[], int i){

	int c;
	c++;

	printf("\nInsira o nome do aluno %d: ", c);
	scanf("\n%[^\n]", aluno[i].nome);
	c++;

	return aluno[i];
}

void printAluno(Aluno aluno[], int i){

	int c = i;
	c++;

	printf("\nNome do aluno %d: ", c, aluno[i].nome);
}
