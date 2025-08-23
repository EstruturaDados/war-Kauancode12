#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIO 5

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio planeta[MAX_TERRITORIO];
    int totalTerritorios = 0;

    printf("======================================= \n");
    printf("CADASTRANDO TERRITORIOS PARA O SEU JOGO \n");
    printf("======================================= \n");

    for (int i = 1; i <= 5; i++) {
        printf("CADASTRO DO TERRITORIO %d\n", i);
    }
}