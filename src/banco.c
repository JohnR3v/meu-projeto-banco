#include "banco.h"
#include <stdio.h>

void inicializar_conta(ContaBancaria *conta, float saldo_inicial) {
    if (conta == NULL) {
        return;
    }

    conta->saldo = saldo_inicial;
}

float consultar_saldo(const ContaBancaria *conta) {
    if (conta == NULL) {
        return 0.0f;
    }

    return conta->saldo;
}

int depositar(ContaBancaria *conta, float valor) {
    if (conta == NULL || valor <= 0.0f) {
        return 0;
    }

    conta->saldo += valor;
    return 1;
}

int sacar(ContaBancaria *conta, float valor) {
    if (conta == NULL || valor <= 0.0f) {
        return 0;
    }

    if (valor > conta->saldo) {
        return 0;
    }

    conta->saldo -= valor;
    return 1;
}

void exibir_menu(void) {
    printf("\n--- MENU DO CAIXA ELETRONICO ---\n");
    printf("1. Consultar Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sacar\n");
    printf("4. Sair\n");
}
