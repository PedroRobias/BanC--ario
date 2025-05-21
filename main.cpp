#include <iostream>
#include <string>
#include "Cliente.h"
#include "ContaBancaria.h"

using namespace std;

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
