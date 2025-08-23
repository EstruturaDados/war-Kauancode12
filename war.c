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
    int totalTerritorios = 0
}