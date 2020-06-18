#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// criar uma função devolve, passo o conteúdo e devolve o ponteiro para o nó com a mesma informação
// função Altura da árvore
// função Grau da árvore
// função é cheia?

char retorno[10];

typedef struct no {
    char info;
    char caminho[10];
    struct no *esq;
    struct no *dir;
} No;

/*typedef struct arvore {
    No *raiz;
} Arvore;

No *criaByProf() {
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    // AQUI?
    a->raiz = NULL;
    return a;
}*/

No *criaNo(){
    No *no = (No*) malloc(sizeof(No));
    no->info = ' ';
    strcpy(no->caminho,"");
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

/*Arvore *cria_vazia() {
    return NULL;
}*/

/*Arvore *cria (char c, Arvore *sae, Arvore *sad) {
    Arvore *p = (Arvore*) malloc(sizeof(Arvore));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}*/

int eh_vazia (No *a) {
    return a == NULL;
}

/*Arvore *libera (Arvore *a){
    if (!eh_vazia(a)){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}*/

void pertence (No *a, char c){
    if (eh_vazia(a)) return;
    if (a->info == c){
        strcpy(retorno, a->caminho);
        return;
    }
    pertence(a->esq, c);
    pertence(a->dir, c);
}

void imprime (No *a) {
    if (!eh_vazia(a)) {
        if (a->info != ' '){
            printf("%c", a->info);
        }
        imprime(a->esq);
        imprime(a->dir);
    }
}

#endif // ARVORE_H_INCLUDED
