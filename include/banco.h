#ifndef BANCO_H
#define BANCO_H

typedef struct {
    float saldo;
} ContaBancaria;

void inicializar_conta(ContaBancaria *conta, float saldo_inicial);
float consultar_saldo(const ContaBancaria *conta);
int depositar(ContaBancaria *conta, float valor);
int sacar(ContaBancaria *conta, float valor);
void exibir_menu(void);

#endif
