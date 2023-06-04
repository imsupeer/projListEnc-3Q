#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arv {
    Arv esq;
    Item item;
    Arv dir;
};

Arv no(Arv A, Item x, Arv B) {
    Arv novo = malloc(sizeof(struct arv));
    novo->esq = A;
    novo->item = x;
    novo->dir = B;
    return novo;
}

void emOrdem(Arv A) {
    if (A != NULL) {
        emOrdem(A->esq);
        printf("%d ", A->item);
        emOrdem(A->dir);
    }
}

void preOrdem(Arv A) {
    if (A != NULL) {
        printf("%d ", A->item);
        preOrdem(A->esq);
        preOrdem(A->dir);
    }
}

void posOrdem(Arv A) {
    if (A != NULL) {
        posOrdem(A->esq);
        posOrdem(A->dir);
        printf("%d ", A->item);
    }
}

void nivelOrdem(Arv A) {
    if (A == NULL)
        return;

    Arv fila[100];
    int frente = 0;
    int tras = 0;

    fila[tras++] = A;

    while (frente < tras) {
        Arv no_atual = fila[frente++];
        printf("%d ", no_atual->item);

        if (no_atual->esq != NULL)
            fila[tras++] = no_atual->esq;

        if (no_atual->dir != NULL)
            fila[tras++] = no_atual->dir;
    }
}

void destroi(Arv *A) {
    if (*A != NULL) {
        destroi(&(*A)->esq);
        destroi(&(*A)->dir);
        free(*A);
        *A = NULL;
    }
}

void inserir(Item x, Arv *A) {
    if (*A == NULL) {
        *A = no(NULL, x, NULL);
    } else {
        if (x < (*A)->item) {
            inserir(x, &(*A)->esq);
        } else {
            inserir(x, &(*A)->dir);
        }
    }
}

int busca(Item x, Arv A) {
    if (A == NULL) {
        return 0;
    }

    if (x == A->item) {
        return 1;
    }

    if (x < A->item) {
        return busca(x, A->esq);
    } else {
        return busca(x, A->dir);
    }
}

Item removeMax(Arv *A) {
    if (*A == NULL) {
        abort();
    }
    while ((*A)->dir != NULL) {
        A = &(*A)->dir;
    }
    Arv aux = *A;
    Item x = aux->item;
    *A = aux->esq;
    free(aux);
    return x;
}

void remover(Item x, Arv *A) {
    if (*A == NULL) {
        printf("\nChave %d nao se encontra na arvore!\n", x);
        return;
    }
    if (x == (*A)->item) {
        Arv aux = *A;
        if (aux->esq == NULL) {
            *A = aux->dir;
        } else {
            if (aux->dir == NULL) {
                *A = aux->esq;
            } else {
                aux->item = removeMax(&aux->esq);
            }
            if (aux != *A) {
                free(aux);
            }
        }
    } else {
        if (x < (*A)->item) {
            remover(x, &(*A)->esq);
        } else {
            remover(x, &(*A)->dir);
        }
    }
}
