#include <iostream>
#include <string>
#include "ContaBancaria.h"


    ContaBancaria::ContaBancaria(int numero, const Cliente& titular, double saldo) // Iniciar uma conta com saldo definido
    : numero(numero), titular(titular), saldo(saldo) {}

    ContaBancaria::ContaBancaria(int numero, const Cliente& titular) // Iniciar uma conta com saldo não definido (0)
    : numero(numero), titular(titular), saldo(0) {}

    void ContaBancaria::depositar(double valor) {
        if (valor > 0)
            saldo += valor;
    }


// Ação Sacar:
    void ContaBancaria::sacar(double valor) {
        if (valor > 0 && valor <= saldo) { // Verificação de valor e saldo válidos
            saldo -= valor; // Retira o valor de saque do saldo atual
        } else {
            cout << "Saldo insuficiente para o saque requisitado. Seu saldo atual é de " << saldo <<" R$. Revise a operação."  << endl;
        }
    }

// Ação Transferir:
    void ContaBancaria::transferir(double valor, ContaBancaria& destino) {
        if (valor > 0 && valor <= saldo) {
            saldo = saldo - valor;
            destino.depositar(valor); // Insere o valor informado na conta desejada
        
        } else {
            cout << "Saldo insuficiente para a transferência requisitada. Seu saldo atual é de " << saldo <<" R$. Revise a operação."  << endl;
    
        }
    }

    void ContaBancaria::transferir(double valor, ContaBancaria& destino1, ContaBancaria& destino2) {
        double metade = valor / 2.0; // Divide o valor informado para que seja destinado às duas contas

        if (valor > 0 && valor <= saldo) {
            saldo = saldo - valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
        
        } else {
            cout << "Saldo insuficiente para a transferência requisitada. Seu saldo atual é de " << saldo <<" R$. Revise a operação."  << endl;
        }
    }

    void ContaBancaria::exibirSaldo() {
        cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
    }

    void ContaBancaria::exibirInformacoes() {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << "    Número da Conta: " << numero << ", Saldo: R$ " << saldo <<endl;

    }
