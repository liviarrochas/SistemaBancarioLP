#ifndef CLASSES_H
#define CLASSES_H
#include <string>
using namespace std;


class Cliente {
private:
    string nome;
    string cpf;

public:
    Cliente(string nome = "", string cpf = "");
    string getNome();
    string getCpf();
};

class ContaBancaria {
private:
    int NConta;
    int Saldo;
    Cliente titular;

public:
    ContaBancaria(int NConta, Cliente titular, int Saldo = 0);
    double getSaldo();
    int getNConta();
    void depositar(double Valor);
    void sacar(double Valor);
    void transferir(double Valor, ContaBancaria &destino);
    void transferir(double Valor, ContaBancaria &destino1, ContaBancaria &destino2);
    void exibirSaldo();
    void exibirInfo();
};

#endif // CLASSES_H