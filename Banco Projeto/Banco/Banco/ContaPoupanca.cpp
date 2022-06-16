#include "ContaPoupanca.hpp"
#include <iostream>


ContaPoupanca::ContaPoupanca(Cpf cpf, Titular titular) :Conta(cpf, titular)
{

}
float ContaPoupanca::taxaDeSaque()const
{
	return 0.03f;
}
