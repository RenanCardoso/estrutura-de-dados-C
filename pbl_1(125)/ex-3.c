#include <stdio.h>

/*
 * Considere um array Notas[20][5] que armazena as notas de 20 estudantes in 5
 * disciplinas. Escreva um programa que permita:
 * Achar a média de cada uma das notas.
 * Achar a média das notas de cada estudante.
 * Achar o número de estudantes que possui menos de 50 em sua média.
 * Imprimir as notas obtidas por cada estudante.
 */

typedef struct Aluno{
	float nota[5];
	float mediaaluno;
} Aluno;

typedef struct Disciplina{
	float mediadisc;
} Disciplina;


static int qtddisc = 2;
int qtdreprov[0];

Aluno getNotaEstudante(Aluno[], int);
Aluno calcMediaEstudante(Aluno[], int);
void verifyReprov(Aluno[], int);
Disciplina calcMediaDisc(Aluno[], Disciplina[], int, int);
void printAlunos(Aluno[], int);
void printDisc(Disciplina[], int);

int main(){

	int i, qtd;
	Aluno aluno[20];
	Disciplina disc[qtddisc];

	printf("Insira a quantidade de estudantes: ");
	scanf("%d", &qtd);

	for (i = 0; i < qtd; i++) {
		aluno[i] = getNotaEstudante(aluno, i);
	}

	for (i = 0; i < qtd; i++) {
		aluno[i] = calcMediaEstudante(aluno, i);
	}

	for (i = 0; i < qtddisc; i++) {
		disc[i] = calcMediaDisc(aluno, disc, i, qtd);
	}

	printf("\n\nSegue abaixo as medias dos alunos: \n");
	for (i = 0; i < qtd; i++) {
		printAlunos(aluno, i);	
	}

	printf("\nA quantidade de reprovados foi de: %d", qtdreprov[0]);

	printf("\n\nSegue abaixo as medias das disciplinas: \n\n");
	for (i = 0; i < qtddisc; i++) {
		printDisc(disc, i);	
	}

	return 0;
}

Aluno getNotaEstudante(Aluno aluno[], int i){

	int k, j = 1, c = i;
	c++;

	printf("\n");
	for (k = 0; k < qtddisc; k++){
		printf("Insira a nota do estudante %d na disciplina %d: ", c, j);
		scanf("%f", &aluno[i].nota[k]);
		j++;
	}

	return aluno[i];
}


// calcular a media do aluno em todas as disciplinas
Aluno calcMediaEstudante(Aluno aluno[], int i){

	int c;
	float somanotas = 0;

	for (c = 0; c < qtddisc; c++){
		somanotas += aluno[i].nota[c];
	}

	aluno[i].mediaaluno = somanotas / qtddisc;

	// metodo para verificar quantos alunos foram reprovados
	verifyReprov(aluno, i);

	return aluno[i];
}

void verifyReprov(Aluno aluno[], int i){

	if (aluno[i].mediaaluno < 5){
		qtdreprov[0]++;
	}
}

// calcular a media de todas as disciplinas
Disciplina calcMediaDisc(Aluno aluno[], Disciplina disc[], int i, int qtd){

	int c;
	float somanotas = 0;

	for (c = 0; c < qtddisc; c++){
		somanotas += aluno[c].nota[i];
	}

	disc[i].mediadisc = somanotas / qtd;

	return disc[i];
}


void printAlunos(Aluno aluno[], int i){

	int c = i;

	printf("O aluno %d teve uma media de %.2f\n", ++c, aluno[i].mediaaluno);
}


void printDisc(Disciplina disc[], int i){

	int c = i;

	printf("A media da disciplina %d foi de %.2f\n", ++c, disc[i].mediadisc);	
}