#include <stdio.h>
#include <stdlib.h>

void jogador(int *x, int *y, int *x2, int *y2, int t){

	if(t == 0){
		printf("\nJogador 01\n");
		printf("Digite a posicao Y:");
		scanf("%d",y);
		printf("Digite a posicao X:");
		scanf("%d",x);
	}else if(t == 1){
		printf("\nJogador 02\n");
		printf("Digite a posicao Y:");
		scanf("%d",y2);
		printf("Digite a posicao X:");
		scanf("%d",x2);
	}
	
}

void geraMatriz(char tabuleiro[][3]){
	
	int linhas=3,colunas=3,l,j;
	
	for(l=0;l<linhas;l++){
		for(j=0;j<colunas;j++){
			tabuleiro[l][j] = '.';
		}
	}
}

void printMatriz(char tabuleiro[][3]){
	
	int linhas=3,colunas=3,l,j,u=-1;
	
	printf("\n");
	printf("\t Y   Y   Y\n");
	printf("\t 0   1   2\n");
	for(l=0;l<linhas;l++){
		printf("\t");
		for(j=0;j<colunas;j++){
			if(j>0){
				printf("|");
			}
			printf(" %c ",tabuleiro[l][j]);
		}
		u = u+1;
		printf(" %d  X",u);
		printf("\n");
	}
}

void vitoria(char m[][3], int *q){
	
	
	// Vitória por x Jogador 01 -----------------------------------
	if(m[0][0] == 'x' && m[0][1] == 'x' && m[0][2] == 'x'){
		printf("***Jogador 01 Ganhou!***");
		*q = 1;
	}
	if(m[1][0] == 'x' && m[1][1] == 'x' && m[1][2] == 'x'){
		printf("***Jogador 01 Ganhou!***");
		*q = 1;
	}
	if(m[2][0] == 'x' && m[2][1] == 'x' && m[2][2] == 'x'){
		printf("Jogador 01 Ganhou!");
		*q = 1;
	}
	// Vitória por x jogador 2 -----------------------------------
	if(m[0][0] == 'o' && m[0][1] == 'o' && m[0][2] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	if(m[1][0] == 'o' && m[1][1] == 'o' && m[1][2] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	if(m[2][0] == 'o' && m[2][1] == 'o' && m[2][2] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	// Vitória por y jogador 1 -----------------------------------
	if(m[0][0] == 'x' && m[1][0] == 'x' && m[2][0] == 'x'){
		printf("***Jogador 01 Ganhou!***");
		*q = 1;
	}
	if(m[0][1] == 'x' && m[1][1] == 'x' && m[2][1] == 'x'){
		printf("***Jogador 01 Ganhou!***");
		*q = 1;
	}
	if(m[0][2] == 'x' && m[1][2] == 'x' && m[2][2] == 'x'){
		printf("***Jogador 01 Ganhou!***");
		*q = 1;
	}
	// Vitória por y jogador 2 -----------------------------------
	if(m[0][0] == 'o' && m[1][0] == 'o' && m[2][0] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	if(m[0][1] == 'o' && m[1][1] == 'o' && m[2][1] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	if(m[0][2] == 'o' && m[1][2] == 'o' && m[2][2] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	// Vitória por diagonal Jogador 01 -----------------------------------
	if(m[0][0] == 'x' && m[1][1] == 'x' && m[2][2] == 'x'){
		printf("***Jogador 01 Ganhou!***");
		*q = 1;
	}
	if(m[0][2] == 'x' && m[1][1] == 'x' && m[2][0] == 'x'){
		printf("***Jogador 01 Ganhou!***");
		*q = 1;
	}
	
	// Vitória por diagonal Jogador 02 -----------------------------------
	if(m[0][0] == 'o' && m[1][1] == 'o' && m[2][2] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	if(m[0][2] == 'o' && m[1][1] == 'o' && m[2][0] == 'o'){
		printf("***Jogador 02 Ganhou!***");
		*q = 1;
	}
	
		
		
}

int main(void){
	
	char Mat[3][3];
	int i,x1=0,y1=0,x2,y2,troca,repete = 0,quebra = 0;
	
	geraMatriz(Mat);
	printMatriz(Mat);
	
	do{
	troca = 0;
	jogador(&x1,&y1,&x2,&y2,troca);
	Mat[x1][y1] = 'x';
	system("cls");
	printMatriz(Mat);
	vitoria(Mat,&quebra);
	
	troca = 1;
	jogador(&x1,&y1,&x2,&y2,troca);
	Mat[x2][y2] = 'o';
	system("cls");
	printMatriz(Mat);
	vitoria(Mat,&quebra);

	repete++;
	
	if(quebra == 1){
		repete = 10;
	}
	
	}while(repete < 9);
	
	
	return 0;
}
