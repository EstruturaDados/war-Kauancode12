#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIO 5

// DEFINE A struct
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};
// CÓDIGO PARA LIMPAR O BUFFER EVITANDO ERROS COM scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// FUNÇÃO PRINCIPAL
int main() {
    struct Territorio planeta[MAX_TERRITORIO];
    int totalTerritorios = 0;
    
    // ENTRADA DE DADOS COM printf
    printf("======================================= \n");
    printf("CADASTRANDO TERRITORIOS PARA O SEU JOGO \n");
    printf("======================================= \n");
    
    // LOOP for PARA SAIDA DE DADOS NO CONSOLE COM printf, PERGUNTA E GUARDA AS INFORMAÇÕES DOS TERRITORIOS
    for (int i = 0; i < 5; i++) {
        printf("\nCADASTRO DO TERRITORIO %d\n", i + 1);

        printf("Nome: ");
        fgets(planeta[i].nome, 30, stdin);

        printf("Cor do exercito: ");
        fgets(planeta[i].cor, 10, stdin);

        planeta[i].nome[strcspn(planeta[i].nome, "\n")] = '\0';
        planeta[i].cor[strcspn(planeta[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &planeta[i].tropas);
        limparBufferEntrada();// LIMPA O ENTER QUE FICA NO BUFFER

    }

        printf("\n=================================== \n");
        printf("CADASTRO DOS TERRITORIOS CONCLUIDOS \n");
        printf("=================================== \n");

    // EXIBE AS INFORMAÇÕES DOS TERRITORIOS APÓS O CADASTRO
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d: \n", i + 1);
        printf("Nome: %s\n", planeta[i].nome);
        printf("Cor do exercito: %s\n", planeta[i].cor);
        printf("Quantidade de tropas: %d\n", planeta[i].tropas);
    }

    return 0;
}