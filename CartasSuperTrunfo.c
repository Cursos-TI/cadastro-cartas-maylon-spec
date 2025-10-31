#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declaração das variáveis
    char estado1, estado2;
    char codigo1[10], codigo2[10];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2;

    srand(time(0));

    // Cadastro da primeira carta
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado1);
    printf("Codigo: ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("Populacao: ");
    scanf("%d", &populacao1);
    printf("Area (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // Cadastro da segunda carta
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    scanf(" %c", &estado2);
    printf("Codigo: ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Populacao: ");
    scanf("%d", &populacao2);
    printf("Area (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // Cálculo da densidade demográfica
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    int opcao1, opcao2;
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    float soma_c1, soma_c2;

    // Primeiro menu
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (menor vence)\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // Segundo menu dinâmico
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == opcao1) continue; // não mostrar o mesmo atributo
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Número de Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica (menor vence)\n"); break;
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2 || opcao1 < 1 || opcao1 > 5 || opcao2 < 1 || opcao2 > 5) {
        printf("\nOpções inválidas! Encerrando o programa.\n");
        return 0;
    }

    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Carta 1: %s\n", cidade1);
    printf("Carta 2: %s\n\n", cidade2);

    // Função auxiliar de comparação
    for (int rodada = 1; rodada <= 2; rodada++) {
        int opcao = (rodada == 1) ? opcao1 : opcao2;
        printf("Comparação %d:\n", rodada);
        switch (opcao) {
            case 1: // População
                printf("Atributo: População\n");
                printf("%s: %d habitantes\n", cidade1, populacao1);
                printf("%s: %d habitantes\n", cidade2, populacao2);
                valor1_c1 = populacao1;
                valor1_c2 = populacao2;
                break;
            case 2: // Área
                printf("Atributo: Área\n");
                printf("%s: %.2f km²\n", cidade1, area1);
                printf("%s: %.2f km²\n", cidade2, area2);
                valor1_c1 = area1;
                valor1_c2 = area2;
                break;
            case 3: // PIB
                printf("Atributo: PIB\n");
                printf("%s: %.2f bilhões de reais\n", cidade1, pib1);
                printf("%s: %.2f bilhões de reais\n", cidade2, pib2);
                valor1_c1 = pib1;
                valor1_c2 = pib2;
                break;
            case 4: // Pontos Turísticos
                printf("Atributo: Pontos Turísticos\n");
                printf("%s: %d pontos\n", cidade1, pontos1);
                printf("%s: %d pontos\n", cidade2, pontos2);
                valor1_c1 = pontos1;
                valor1_c2 = pontos2;
                break;
            case 5: // Densidade Demográfica
                printf("Atributo: Densidade Demográfica (menor vence)\n");
                printf("%s: %.2f hab/km²\n", cidade1, densidade1);
                printf("%s: %.2f hab/km²\n", cidade2, densidade2);
                valor1_c1 = densidade1;
                valor1_c2 = densidade2;
                break;
        }
        printf("\n");
        if (rodada == 1) {
            valor2_c1 = valor1_c1;
            valor2_c2 = valor1_c2;
        }
    }

    // Soma dos atributos
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    // Ajustar para densidade (menor vence)
    if (opcao1 == 5) soma_c1 = (densidade1 < densidade2) ? soma_c1 + 1 : soma_c1;
    if (opcao2 == 5) soma_c1 = (densidade1 < densidade2) ? soma_c1 + 1 : soma_c1;

    printf("=== SOMA DOS ATRIBUTOS ===\n");
    printf("%s: %.2f\n", cidade1, soma_c1);
    printf("%s: %.2f\n\n", cidade2, soma_c2);

    // Verificar vencedor final
    if (soma_c1 > soma_c2)
        printf("Vencedor final: %s\n", cidade1);
    else if (soma_c2 > soma_c1)
        printf("Vencedor final: %s\n", cidade2);
    else
        printf("Empate!\n");

    printf("\n=============================\n");

    return 0;
}
