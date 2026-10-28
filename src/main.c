#include "banco.h"
#include <stdio.h>

static void limpar_entrada(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

int main(void) {
    ContaBancaria conta;
    int opcao = 0;
    float valor = 0.0f;

    inicializar_conta(&conta, 1000.0f);

    do {
        exibir_menu();
        printf("Digite a opcao desejada: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
            limpar_entrada();
            opcao = 0;
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\n[CONSULTA] Seu saldo atual e: R$ %.2f\n", consultar_saldo(&conta));
                break;

            case 2:
                printf("\n[DEPOSITO] Digite o valor a depositar: R$ ");
                if (scanf("%f", &valor) != 1) {
                    printf("Valor invalido para deposito.\n");
                    limpar_entrada();
                    break;
                }

                if (depositar(&conta, valor)) {
                    printf("Deposito realizado com sucesso! Novo saldo: R$ %.2f\n", consultar_saldo(&conta));
                } else {
                    printf("Valor invalido para deposito.\n");
                }
                break;

            case 3:
                printf("\n[SAQUE] Digite o valor a sacar: R$ ");
                if (scanf("%f", &valor) != 1) {
                    printf("Valor invalido para saque.\n");
                    limpar_entrada();
                    break;
                }

                if (sacar(&conta, valor)) {
                    printf("Saque realizado com sucesso! Saldo restante: R$ %.2f\n", consultar_saldo(&conta));
                } else if (valor > consultar_saldo(&conta)) {
                    printf("Erro: Saldo insuficiente! O valor do saque excede o seu saldo disponivel (R$ %.2f).\n", consultar_saldo(&conta));
                } else {
                    printf("Valor invalido para saque.\n");
                }
                break;

            case 4:
                printf("\nEncerrando o sistema. Obrigado por utilizar o Banco Digital!\n");
                break;

            default:
                printf("\nOpcao invalida! Por favor, escolha uma opcao entre 1 e 4.\n");
                break;
        }

        limpar_entrada();
    } while (opcao != 4);

    return 0;
}
