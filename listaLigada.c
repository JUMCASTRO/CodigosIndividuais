#include <stdio.h>
#include "booleano.h"
#define ghost 0

typedef struct Celula{
	int info;//item
	struct Celula *next;//ponter para a proxima celula
}Celula;

typedef struct {
	int tamanho;//guarda o numero de registros existentes na lista
	Celula *inicio;//inicio é um pointer que guarda o endereco do primeiro registro
}Lista;

Lista crisrLista();// o construtor cria a lista vazia ok
void mostrarLista(Lista A);// mostra o conteudo da lista
bool listaVazia(Lista A);// devolve TRUE se a Lista estuver vazia
int obterTamanho(Lista A);// devolve o comprimento da lista 
int buscarItem(Lista A, int y);// devolve a ordem do item ou zero
void inserir(Lista* A, int y);//acrescenta o item no inicio da lista
//void buscaRemove(Lista* A, int y);// remove a primeir aocorrencia do item

int main(){
	Lista A = crisrLista();
	int y = 2;
	
	inserir(&A, 5);

	inserir(&A, y);
	
	mostrarLista(A);
	listaVazia(A);
		

	int tam = obterTamanho(A);
	printf("Tamanho = %d\n", tam);
	
	int posicao = buscarItem(A, y);	
	printf("Posicao = %d\n", posicao);
	
	inserir(&A, y);
	

}
Lista crisrLista(){
	Lista A;
	A.tamanho = 0;
	A.inicio = NULL;
	return A;
}
void mostrarLista(Lista A){
	Celula* p = A.inicio;
	while(p !=NULL){
		printf("Registros: %d\n",p->info);
		p = p->next;
	}
	
}
bool listaVazia(Lista A){
	bool p = FALSE;
	if(A.inicio == NULL){
		p = TRUE;
		printf("Lista vazia");
		
	}
	return p;
}
int obterTamanho(Lista A){
	return A.tamanho;
}
int buscarItem(Lista A, int y){
	Celula* p = A.inicio;
	int i = 1;
	int res;
	
	while(p != NULL && p->info != y){
		p = p->next;
		i++;
	}
	if(p->info == y){
		res = i;
	}else{
		res = ghost;
	}
	
	return res;
	
}
void inserir(Lista* A, int y){
	Celula* p;
	
	p = malloc(sizeof(Celula));
	p->next = A->inicio;
	A->inicio = p;
	p->info = y;
	A->tamanho++;
	
}