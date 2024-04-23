#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int conteudo;
	struct no *esquerda, *direito;
}No;

typedef struct {
	No* raiz; //raiz da árvore binária
}BinaryTree;

void inserirEsquerda(No* no, int valor) {

}

void inserirDireita(No* no, int valor) {

}

void inserir(BinaryTree* arv, int valor) {
	if (arv->raiz == NULL) {
		No* novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direito = NULL;
		arv->raiz = novo;
	}
	else {
		if (valor < arv->raiz->conteudo)
			inserirEsquerda(arv->raiz, valor);
		else
			inserirDireita(arv->raiz, valor);
	}
}

int main() {
	printf("Hello, World!");
}