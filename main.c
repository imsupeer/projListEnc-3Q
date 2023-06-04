#include <stdio.h>
#include "arvore.h"

int main() {
    Item x;
    Arv t = NULL;

    printf("Informe a chave a ser inserida ou -1 para encerrar: ");
    scanf("%d", &x);
    while (x != -1) {
        inserir(x, &t);
        printf("Informe a chave a ser inserida ou -1 para encerrar: ");
        scanf("%d", &x);
    }

    printf("\n");
    printf("Em ordem: ");
    emOrdem(t);
    printf("\nPre ordem: ");
    preOrdem(t);
    printf("\nPos ordem: ");
    posOrdem(t);
    printf("\nOrdem em nivel: ");
    nivelOrdem(t);

    printf("\n\nInforme a chave a ser removida: \n");
    scanf("%d", &x);
    remover(x, &t);

    printf("\nDepois da remocao\n\n");
    printf("Em ordem: ");
    emOrdem(t);
    printf("\nPre ordem: ");
    preOrdem(t);
    printf("\nPos ordem: ");
    posOrdem(t);
    printf("\nOrdem em nivel: ");
    nivelOrdem(t);

    destroi(&t);

    return 0;
}
