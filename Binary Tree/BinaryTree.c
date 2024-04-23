#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int conteudo;
    struct no* esquerda;
    struct no* direita;
} No;

typedef struct {
    No* raiz; // raiz da árvore binária
} BinaryTree;

void inserirEsquerda(No* no, int valor); // Protótipo da função inserirEsquerda
void inserirDireita(No* no, int valor);  // Protótipo da função inserirDireita

void inserir(BinaryTree* arv, int valor) {
    if (arv->raiz == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else {
        if (valor < arv->raiz->conteudo)
            inserirEsquerda(arv->raiz, valor);
        else
            inserirDireita(arv->raiz, valor);
    }
}

void inserirEsquerda(No* no, int valor) {
    if (no->esquerda == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }
    else {
        if (valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        else
            inserirDireita(no->esquerda, valor);
    }
}

void inserirDireita(No* no, int valor) {
    if (no->direita == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }
    else {
        if (valor < no->direita->conteudo)
            inserirDireita(no->direita, valor);
        else
            inserirEsquerda(no->direita, valor);
    }
}

void printar(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->conteudo);
        printar(raiz->esquerda);
        printar(raiz->direita);
    }
}

int main() {
    int op, valor;
    BinaryTree arv;
    arv.raiz = NULL;

    do {
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n");
        scanf_s("%d", &op);

        switch (op) {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("Digite um valor:");
            scanf_s("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            printf("\nImpressao da arvore:\n");
            printar(arv.raiz);
            break;
        }
    } while (op != 0);

    return 0;
}
1