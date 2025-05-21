// ESSE É O CÓDIGO BRUTO, SEM PARTICIONAR


#include <iostream>
#include <string>

using namespace std;

// Classe Cliente:
class Cliente {

private:
    string nome;
    string cpf;

public:
    Cliente(const string& nome, const string& cpf)
        : nome(nome), cpf(cpf) {}

    string getNome() const {
        return nome;
    }

    string getCpf() const {
        return cpf;
    }

};

// Classe ContaBancaria:
class ContaBancaria {

private:
    int numero;
    double saldo;
    Cliente titular;

public:
    ContaBancaria(int numero, const Cliente& titular, double saldo = 0.0)
        : numero(numero), titular(titular), saldo(saldo) {}

    void depositar(double valor) {
        if (valor > 0)
            saldo += valor;
    }

    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
        } else {
            cout << "Saldo insuficiente para o saque requisitado. Seu saldo atual é de " << saldo <<" R$. Revise a operação."  << endl;
        }
    }

    void transferir(double valor, ContaBancaria& destino) {
        if (valor > 0 && valor <= saldo) {
            saldo = saldo - valor;
            destino.depositar(valor);
        
        } else {
            cout << "Saldo insuficiente para a transferência requisitada. Seu saldo atual é de " << saldo <<" R$. Revise a operação."  << endl;
    
        }
    }

    void transferir(double valor, ContaBancaria& destino1, ContaBancaria& destino2) {
        double metade = valor / 2.0;

        if (valor > 0 && valor <= saldo) {
            saldo = saldo - valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
        
        } else {
            cout << "Saldo insuficiente para a transferência requisitada. Seu saldo atual é de " << saldo <<" R$. Revise a operação."  << endl;
        }
    }

    void exibirSaldo() const {
        cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
    }

    void exibirInformacoes() const {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << "    Número da Conta: " << numero << ", Saldo: R$ " << saldo <<endl;

    }
};




// Main:

int main() {

    // Criação dos clientes.
    Cliente cliente1("Pedro", "111.111.111-11");
    Cliente cliente2("Henrique", "222.222.222-22");
    Cliente cliente3("Papai Smurf", "333.333.333-33");

    // Criação das contas bancárias e seus saldos iniciais.
    ContaBancaria conta1(10, cliente1, 500);
    ContaBancaria conta2(11, cliente2);
    ContaBancaria conta3(12, cliente3);

    conta2.transferir(1, conta1, conta3);
    conta1.depositar(500);
    conta1.transferir(600, conta2, conta3);
    conta2.sacar(301);
    conta3.transferir(1, conta2);

    
    // Mostra os saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
