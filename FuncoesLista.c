#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define max 27
#define sinal -1
#define fantasma 36

typedef struct{
	int tam;
	unsigned char vetor[max];
}ListaP;

ListaP criarLista();
ListaP construirLista(int n);
ListaP appendLista(ListaP A, unsigned char y);
ListaP copyLista(ListaP A);
int countLista(ListaP A, unsigned char y);
int indexLista(ListaP A, unsigned char y);
ListaP insertLista(ListaP A, unsigned char y, int k);
int lenLista(ListaP A);
unsigned char maxlista(ListaP A);
//ListaP popLista(ListaP A, int k);
ListaP removerLista(ListaP A, unsigned char y);

void mostrarLista(ListaP A);


int main(){
	int k = 2;
	int n = 5;
	ListaP A;
	ListaP B;

	unsigned char y = 'A';
	
	A = criarLista();
	A = construirLista(n);

	A = appendLista(A,  y);
	
	B = copyLista(A);
	
	A = insertLista( A, y,k);

	mostrarLista(A);
//	mostrarLista(B);
//	A = popLista(A, k);
	A = removerLista(A, y);

	mostrarLista(A);

	
	int p = countLista(A, y);
	printf("Contador = %d\n", p);
	
	int w = indexLista(A,y);
	printf("Indice = %d\n", w);
	
	int m = lenLista(A);
	printf("Tamanho da lista = %d\n", m);
	
	unsigned char maior = maxlista(A);
	printf("Maior = %u\n", maior);



	return 0;
}

//criar lista
ListaP criarLista(){
	ListaP A;
	A.tam = 0;
	return A;
}
//construr uma lista para teste
ListaP construirLista(int n){
	ListaP A;
	
	if(n < max){
		srand(time(0));
		
		for(int i = 0;i < n; i++){
			char p = 65 + (char)rand() % 26;
			A.vetor[i] = p;
		}
	A.tam = n ;
	}
	return A;	
}
ListaP appendLista(ListaP A, unsigned char y){
	if(A.tam < max){
		int p = A.tam  ;
		A.vetor[p] = y;
		A.tam++;
				
		
	}
	return A;
	
}
ListaP copyLista(ListaP A){
	int i = 0;
	ListaP B;
	int p = A.tam;
	
	while(i < p){
		B.vetor[i] = A.vetor[i];
		i++;
	}
	B.tam = A.tam;
	return B;
}

int countLista(ListaP A, unsigned char y){
	int i = 1;
	int count = 0;
	
	int p = A.tam;
	while(i < p){
		if(A.vetor[i] == y){
			count++;
			
		}
		i++;
		
	}
	return count;
}
int indexLista(ListaP A, unsigned char y){
	int R;
	int p = A.tam;
	
	if(p > 0){
		int i = 0;
		
		while(i < p && A.vetor[i] != y ){
			i++;
		}
		
		if(A.vetor[i]  == y){
			R = i;
			
		}else{
			R = fantasma;
			
		}
			
	}else{
		R = fantasma;
		
	}

	return R;
		
}
ListaP insertLista(ListaP A, unsigned char y, int k){
		int p = A.tam;	
		if (p < max){
			if(p > 0 && k < p)	{
				for(int i = p ;i >  k; i--)	{
					A.vetor[i] ==A.vetor[i-1];			

				}
				A.vetor[k] = y;
				A.tam++;
				
			}	
		}else if(k == p){
			unsigned char aux =	A.vetor [k];
			A.vetor[k + 1] = aux;
			A.vetor[k] = y;
			A.tam++;
		}
		
	return A;
}
int lenLista(ListaP A){
	return A.tam;	
}
unsigned char maxlista(ListaP A){
		int p = A.tam;
		unsigned char maior = A.vetor[0];
		if(p > 0){
			for(int i = 1;i < p - 1; i++){
				if(maior < A.vetor[i]){
					maior = A.vetor[i];
				}
			}
		}else{
			maior = fantasma;
		}
	return maior;
}

/*ListaP popLista(ListaP A, int k){
		int p = A.tam;
		if(k < p){
			for(int i  = k; i < p; i++){
				A.vetor[i] = A.vetor[i + 1];
				
			}
			A.tam--;
			
		}
		return A;
}*/
ListaP removerLista(ListaP A, unsigned char y){
		int p = A.tam;
		int i = 0;
		if(p > 0){
			while(i < p && A.vetor[i] != y){
				i++;
			}
			
			if(A.vetor[i] == y){
				for(int j = i; j < p - 1; j++){
					A.vetor[j] = A.vetor[j + 1];
				}
				A.tam--;
			}
		}
		return A;
}
void mostrarLista(ListaP A){
	for(int i = 0; i < A.tam; i++){
		printf("%c\n", A.vetor[i]);
	}
	printf("\n");
}



