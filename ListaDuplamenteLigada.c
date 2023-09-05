#include <stdio.h>
#include <stdlib.h>
#include "booleano.h"
#define ghost 0

typedef struct Celula{
	char prim;
	struct Celula* suc;
	struct Celula* pre;
	
}Celula;

typedef struct {
	int tamanho;
	Celula* inicio;
	Celula* fim;	
}Lista;

Lista criarLista();//o construtor cria a lista
void mostrarLista(Lista A);// mostra o conteudo da lista a partir do inicio
void mostrarListaDE(Lista A);// mostra o conteudo da lista a partir do fim
bool listaVazia(Lista A);// devolve TRUE se a lista estiver vazia
void inserir(Lista* A, char y);//acrescenta o intem no incio da lista
void inserirFim(Lista* A, char y);//acrescenta o intem no fim da lista
void RemovePos(Lista* A, char y);//remove item de ordem k

int main(){
	Lista A;
	char y = 'v';
	
	A = criarLista();
	mostrarLista(A);
	
	
	
	inserir(&A, y);
	
	inserir(&A, 'c');
	
	inserir(&A, 'k');
	
	//mostrarListaDE(A);
	inserirFim(&A, 'x');
	
	RemovePos(&A, 'c');
	mostrarLista(A);
	
	
}

Lista criarLista(){
	Lista A;
	A.inicio = NULL;
	A.fim = NULL;
	A.tamanho = 0;
	return A;
}
void mostrarLista(Lista A){
	Celula* p = A.inicio;
	if(p == NULL){
		printf("A lista esta vazia!\n");
		
	}else{
		while(p != NULL){
			printf("registros: %c\n",p->prim);
			p = p->suc;
			
		}
	}
}
void mostrarListaDE(Lista A){
	Celula* p = A.fim;
	if(p == NULL){
		printf("A lista esta vazia!\n");
		
	}else{
		while(p != NULL){
			printf("registros: %c\n",p->prim);
			p = p->pre;
			
		}
	}
}

bool listaVazia(Lista A){
	bool p = FALSE;
	if(A.inicio == NULL){
		p = TRUE;
	}
	return p;
}
void inserir(Lista* A, char y){
	Celula* p;
	p = malloc(sizeof(Celula));
	
	if(A->inicio == NULL){
		p->pre = NULL;
		p->suc = NULL;
		A->inicio = p;
		A->fim = p;
		
		p->prim = y;
		
		
	}else{
		A->inicio->pre = p;
		p->pre = NULL;
		p->suc = A->inicio;
		A->inicio = p;
		p->prim = y;
	}
	A->tamanho++;	
			
}
void inserirFim(Lista* A, char y){
	Celula* p;
	p = malloc(sizeof(Celula));
	
	if(A->inicio == NULL){
		p->pre = NULL;
		p->suc = NULL;
		A->inicio = p;
		p->prim = y;
		
		
	}else{
		A->fim->suc = p;	
		p->pre = A->fim;
		p->suc = NULL;
		A->fim = p;
		p->prim = y;
				
	}
	A->tamanho++;	
	
}
void RemovePos(Lista* A, char y){
	if(A->inicio == NULL){
		printf("Lista vazia!");
	}else{
		Celula* p = A->inicio;
		int i = 1;
	
		while(p != NULL && p->prim != y){
			p = p->suc;
			i++;
		}
		if(i == 1){
			A->inicio = A->inicio->suc;
			p->pre = NULL;
			A->tamanho--;
		}else if(i == A->tamanho){	
				Celula *antigo;
				
				antigo = A->fim;
				A->fim = A->fim->pre;//guarda em fim o endereco da nova ultima celula
				p = p->pre;// aponta para o novo último celula na lista
				p->suc = NULL;//coloca null no espaco suc da novq ultima celula
				A->tamanho--;

				free(antigo);
				
		}else{
			Celula *meio;
			meio = p;
			p->pre->suc = p->suc;
			p->suc->pre = p->pre;
			A->tamanho--;
			free(meio);
		}
	}
}
