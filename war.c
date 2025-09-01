#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// DEFINE A struct
typedef struct  {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void simularAtaque(Territorio *atacante, Territorio * defensor) {
    int dadoAtq = (rand() %6) + 1;

    int dadoDef = (rand() %6) + 1;

    printf("\n%s ataca %s\n", atacante->nome, defensor->nome);
    printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtq, dadoDef);

    if (dadoAtq > dadoDef) {
        defensor->tropas--;
        printf("Defensor perdeu uma tropa\n");
    } else {
        atacante->tropas--;
        printf("Atacante perdeu uma tropa\n");
    }    

}
// CÓDIGO PARA LIMPAR O BUFFER EVITANDO ERROS COM scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// FUNÇÃO PRINCIPAL
int main() {
    int opcao;
    int n;
    printf("Quantos territorios deseja cadastrar?: ");
    scanf("%d", &n);
    limparBufferEntrada();

    Territorio *planeta;
    planeta = (Territorio*) calloc(n, sizeof(Territorio));
    
    if (planeta == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
 
    // ENTRADA DE DADOS COM printf
    printf("\n======================================= \n");
    printf("CADASTRANDO TERRITORIOS PARA O SEU JOGO \n");
    printf("======================================= \n");
    
    // LOOP for PARA SAIDA DE DADOS NO CONSOLE COM printf, PERGUNTA E GUARDA AS INFORMAÇÕES DOS TERRITORIOS
    for (int i = 0; i < n; i++) {
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