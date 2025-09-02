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

void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoAtq = (rand() %6) + 1;

    int dadoDef = (rand() %6) + 1;

    printf("\n%s ataca %s\n", atacante->nome, defensor->nome);
    printf("Dado atacante: %d | Dado defensor: %d\n", dadoAtq, dadoDef);

    if (dadoAtq >= dadoDef) {
        defensor->tropas--;
        printf("Defensor perdeu uma tropa\n");
    } else {
        atacante->tropas--;
        printf("Atacante perdeu uma tropa\n");
    }

    if (defensor->tropas <= 0) {
        printf("%s Foi conquistado pelo exercito %s\n", defensor->nome, atacante->cor);
        defensor->tropas = 1;
        strcpy(defensor->cor, atacante->cor);
    }

}
// CÓDIGO PARA LIMPAR O BUFFER EVITANDO ERROS COM scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// FUNÇÃO PRINCIPAL
int main() {
    srand(time(NULL));

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

    do {
        printf("\n==Territorios==\n");
        for (int i = 0; i < n; i++) {
            printf("%d - %s (%d tropas do exercito %s)\n", i + 1, planeta[i].nome, planeta[i].tropas, planeta[i].cor);
        }

        printf("\nEscolha o atacante (1 a %d ou 0 para sair): ", n);
        scanf("%d", &opcao);
        if (opcao == 0) break;
        int atq = opcao - 1;

        printf("\nEscolha o defensor (1 a %d ou 0 para sair): ", n);
        scanf("%d", &opcao);
        if (opcao == 0) break;
        int def = opcao - 1;
        
        if (atq < 0 || atq >= n || def < 0 || def >= n || atq == def) {
            printf("Escolha invalida\n");
            continue;
        }

        if (planeta[atq].tropas <= 1) {
            printf("Voce não pode atacar com apenas 1 tropa\n");
            continue;
        }

        if (strcmp(planeta[atq].cor, planeta[def].cor) == 0) {
            printf("Voce não pode atacar um territorio que já conquistou\n");
            continue;
        }

        atacar(&planeta[atq], &planeta[def]);

        printf("Status: %s (%d tropas) x %s (%d tropas)\n", planeta[atq].nome, planeta[atq].tropas, planeta[def].nome, planeta[def].tropas);
        printf("Pressione Enter para prosseguir...");
        limparBufferEntrada();
        getchar();

    } while (1);

    free(planeta);
    printf("Programa encerrado. \n");

    return 0;
}