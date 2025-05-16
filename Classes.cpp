#include "Classes.h"
#include <string>
#include <iostream>

// Metodos Cliente
Cliente::Cliente(string nome, string cpf) {
    this->nome = nome;
    this->cpf = cpf;
}

string Cliente::getNome() {
    return this->nome;
}

string Cliente::getCpf() {
    return this->cpf;
}

// Metodos ContaBancaria
ContaBancaria::ContaBancaria(int NConta, Cliente titular, int Saldo) {
    this->NConta = NConta;
    this->Saldo = Saldo;
    this->titular = titular;
}

double ContaBancaria::getSaldo() {
    return this->Saldo;
}

int ContaBancaria::getNConta() {
    return this->NConta;
}

void ContaBancaria::depositar(double Valor) {
    this->Saldo = getSaldo() + Valor;
}

void ContaBancaria::sacar(double Valor) {
    if(Valor > getSaldo()) {
        cout << "Saldo insuficiente" << endl;
    } else {
        this->Saldo = getSaldo() - Valor;
    }
}

void ContaBancaria::transferir(double Valor, ContaBancaria &destino) {
    if(Valor <= getSaldo()) {
        sacar(Valor);
        destino.depositar(Valor);
        cout << "Transferido: R$ " << Valor << " da conta: " << getNConta() << " para a conta: " << destino.getNConta() << endl;
    } else {
        cout << "Falha na transferência" << endl;
    }
}

void ContaBancaria::transferir(double Valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    if(Valor <= getSaldo()) {
        sacar(Valor);
        destino1.depositar(Valor/2);
        destino2.depositar(Valor/2);
        cout << "Transferido: R$ " << Valor/2 << " para cada conta (" << destino1.getNConta() << " e " << destino2.getNConta() << ") da conta " << getNConta() << endl;
    } else {
        cout << "Falha na transferência" << endl;
    }
}

void ContaBancaria::exibirSaldo() {
    cout << "Saldo atual da conta " << getNConta() << ": R$ " << getSaldo() << endl;
}

void ContaBancaria::exibirInfo() {
    cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
    cout << "Número da conta: " << getNConta() << ", Saldo: R$ " << getSaldo() << endl;
}