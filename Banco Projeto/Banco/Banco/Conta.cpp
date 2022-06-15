#include "Conta.hpp"
#include <iostream>
#include "Titular.hpp"


Conta::Conta(Cpf cpf, Titular titular):
	numero(numero),
	titular(titular),
	saldo(0)
	
{
	
}


void Conta::sacar(float valorASacar)
{
	if (valorASacar < 0)
	{
		std::cout << "Saldo Insuficente! " << std::endl;
		return;
	}

	float tarifaDeSaque = valorASacar * 0.05f;
	float valorDoSaque = valorASacar + tarifaDeSaque;
	if (valorASacar > saldo)
	{
		std::cout << "Saldo Insuficente! " << std::endl;
		return;
	}
	saldo -= valorDoSaque;
}

void Conta::depositar(float valorADepositar)
{
	{
		if (valorADepositar < 0) {
			std::cout << "Valor de Deposito invalido. " << std::endl;
			return;
		}
		saldo += valorADepositar;
	}
}
float Conta::getSaldo() const
{
	return saldo;
}

