#include<stdio.h>
#include "Booleano.h"
#define Max 101
#define ghost 63
#define sinal 0

typedef struct{
	int topo;
	unsigned char vetor[Max];
}Pilha;

void criarPilha(Pilha* A);
bool pilhaVazia(Pilha* A);
unsigned char acessarPilha(Pilha* A);
void pushPilha(Pilha* A, unsigned char y);
void popPilha(Pilha* A);
//void esvaziarPilha(Pilha* A);
void adicionarPilha(Pilha* A);
void inverterPilha(Pilha* A);
void copiarPilha(Pilha* A,Pilha* B);

void mostrarPilha(Pilha* A);

int main(){
	Pilha A;
	Pilha B;
	unsigned char y = '2';
	
	criarPilha(&A);
	
	bool R = pilhaVazia(&A);
	printf("R = %d\n", R);
	
	unsigned char T = acessarPilha(&A);
	printf("T = %u\n", T);
	
	pushPilha(&A, y);
	printf("char = %u\n", A.vetor[A.topo]);
	
	popPilha(&A);
	printf("char = %u\n", A.vetor[A.topo]);
	
	//esvaziarPilha(&A);
	adicionarPilha(&A);
	//mostrarPilha(&A);

	printf("\n");
	
	inverterPilha(&A);
	
	copiarPilha(&A,&B);

	mostrarPilha(&A);
	printf("\n");

	mostrarPilha(&B);


	return 0;

}
void criarPilha(Pilha* A){
	A->topo = sinal;
	A->vetor[0] = Max - 1;//capacidade da pilha
}

bool pilhaVazia(Pilha* A){
	bool R = FALSE;
	if(A->topo == 0){
		R = TRUE;
	}
	return R;
}
unsigned char acessarPilha(Pilha* A){
	unsigned char R;
	if(A->topo == sinal){
		R = ghost;
	}else{
		int p = A->topo;
		R = A->vetor[p];
	
	}
	return R;
}

void pushPilha(Pilha* A, unsigned char y){
	int p = A->topo;
	if(p != A->vetor[0]){
		A->vetor[p+1] = y;
		A->topo++;
	}
}

void popPilha(Pilha* A){
	
	int p = A->topo;
	if(p != sinal){
		A->topo--;

	}
	
	
}
void adicionarPilha(Pilha* A){
	if(A->topo == sinal){
	
		for(int i = 1; i <= 6; i++){
			A->vetor[i] = i;
		}
		A->topo = 6;
	}
}
void mostrarPilha(Pilha* A){
	if(A->topo != sinal){
		int p = A->topo;
		for(int i = p; i >= 1; i--){
			printf("%u\n",A->vetor[i] );
		}
	}
}
void inverterPilha(Pilha* A){
	int p = A->topo;
	Pilha aux;
	int j = 1;
	if(p != sinal){
		for(int i = p; i >= 1; i--){
			aux.vetor[j] = A->vetor[i];
			j++;
		}
		for(int i = 1; i <= p; i++){
			A->vetor[i] = aux.vetor[i];
		}
	}
}
void copiarPilha(Pilha* A,Pilha* B){
	int p = A->topo;
	if(p != sinal){
		for(int i = 1;i <= p; i++){
			B->vetor[i] = A->vetor[i];

			
		}
		B->topo = A->topo; 
	}
}

/*void esvaziarPilha(Pilha* A){
	A->topo  = 0;
}*/