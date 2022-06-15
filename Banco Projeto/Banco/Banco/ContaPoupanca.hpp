#pragma once
#include "Conta.hpp"


class ContaPoupanca :  public Conta
{


public:
	ContaPoupanca(Cpf cpf, Titular titular);
	void sacar(float valorASacar);
};

