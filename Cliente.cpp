#include <iostream>
#include <string>
#include "Cliente.h"

Cliente::Cliente(const string& nome, const string& cpf)
    : nome(nome), cpf(cpf) {}

string Cliente::getNome() const {
    return nome;
}

string Cliente::getCpf() const {
    return cpf;
}
