#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;


// Classe Cliente:
class Cliente {

private:
    string nome;
    string cpf;

public:

    Cliente(const string& nome, const string& cpf);

    string getNome() const;

    string getCpf() const;
};

#endif 