#include "ContaPoupanca.hpp"
#include <iostream>


ContaPoupanca::ContaPoupanca(Cpf cpf, Titular titular) :Conta(cpf, titular)
{

}
void ContaPoupanca::sacar(float valorASacar)
{
	if (valorASacar < 0)
	{
		std::cout << "Saldo Insuficente! " << std::endl;
		return;
	}

	float tarifaDeSaque = valorASacar * 0.03f;
	float valorDoSaque = valorASacar + tarifaDeSaque;

	if (valorASacar > saldo)
	{
		std::cout << "Saldo Insuficente! " << std::endl;
		return;
	}
	saldo -= valorDoSaque;
}