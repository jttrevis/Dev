#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "ContaPoupanca.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"

using namespace std;
int numeroDeContas;


void RealizaSaque(Conta& conta)
{
    conta.sacar(200);
}

void ExibeSaldo( Conta& conta)
{
    cout << "O saldo da conta : " << conta.getSaldo() << endl;
}

int main()
{

    Cpf cpf("12312554");
    Titular titular(cpf, "Junior");
    Conta umaConta(cpf, titular);
    umaConta.depositar(500);
    RealizaSaque(umaConta);

    Titular novoTitular(cpf, "Angelica");
    ContaPoupanca contaDois(cpf, titular);
    contaDois.depositar(1200);
    RealizaSaque(contaDois);



    ExibeSaldo(contaDois);
    ExibeSaldo(umaConta);


    Funcionario funcionario(Cpf("123456789"), "Junior", 10000);

    cout << "nome do funcionario: " << funcionario.recuperaNome() << endl;


    return 0;
}
