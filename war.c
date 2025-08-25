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

    for (int i = 0; i < 5; i++) {
        printf("CADASTRO DO TERRITORIO %d\n", i + 1);

        printf("Nome: ");
        fgets(planeta[i].nome, 30, stdin);

        printf("Cor do exercito: ");
        fgets(planeta[i].cor, 10, stdin);

        planeta[i].nome[strcspn(planeta[i].nome, "\n")] = '\0';
        planeta[i].cor[strcspn(planeta[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &planeta[i].tropas);
        limparBufferEntrada();

    }

        printf("=================================== \n");
        printf("CADASTRO DOS TERRITORIOS CONCLUIDOS \n");
        printf("=================================== \n");

    for (int i = 0; i < 5; i++) {
        printf("Territorio %d: \n", i + 1);
        printf("Nome: %s\n", planeta[i].nome);
        printf("Cor do exercito: %s\n", planeta[i].cor);
        printf("Quantidade de tropas: %d\n", planeta[i].tropas);
    }

    return 0;
}