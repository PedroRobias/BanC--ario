#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <iostream>
#include <string>
#include "Cliente.h"

// Classe ContaBancaria:
class ContaBancaria {
private:
    int numero;  //Atributo privado -> Número da conta
    double saldo; //Atributo privado -> Saldo da conta
    Cliente titular; //Atributo privado -> Titular / Nome

public:
    ContaBancaria(int numero, const Cliente& titular, double saldo);
    ContaBancaria(int numero, const Cliente& titular);

    void depositar(double valor);
    void sacar(double valor);
    void transferir(double valor, ContaBancaria& destino);
    void transferir(double valor, ContaBancaria& destino1, ContaBancaria& destino2);
    void exibirSaldo();
    void exibirInformacoes();
};

#endif 