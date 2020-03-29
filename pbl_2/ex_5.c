#include <stdio.h>

/* Escreva um programa que permita a leitura e escrita de um conjunto de alunos em uma
 * turma. Cada aluno deve estar representado por RA, Nome, Telefone e Endereco
 */

typedef struct Aluno{
    int RA;
	char nome[120];
    int telefone;
    char endereco[300];
} Aluno;

Aluno getAluno(Aluno[], int);
void printAluno(Aluno[], int);

int main(void){

	int i, qtd;
	Aluno aluno[10];

	printf("Insira a quantidade de alunos na turma: ");
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

    int c = i;
    c++;

    printf("\nInsira o RA do aluno %d: ", c);
    scanf("%d", &aluno[i].RA);

    printf("Insira o nome do aluno %d: ", c);
    scanf("\n%[^\n]", aluno[i].nome);

    printf("Insira o telefone do aluno %d: ", c);
    scanf("%d", &aluno[i].telefone);

    printf("Insira o endereco do aluno %d: ", c);
    scanf("\n%[^\n]", aluno[i].endereco);

	return aluno[i];
}

void printAluno(Aluno aluno[], int i){

    int c = i;
    c++;

	printf("\nRA do aluno %d: %d", c, aluno[i].RA);
	printf("\nNome do aluno %d: %s", c, aluno[i].nome);
	printf("\nTelefone do aluno %d: %d", c, aluno[i].telefone);
	printf("\nEndereco do aluno %d: %s", c, aluno[i].endereco);
    printf("\n");
}