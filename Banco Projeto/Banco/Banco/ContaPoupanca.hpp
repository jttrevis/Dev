#pragma once
#include "Conta.hpp"


class ContaPoupanca :  public Conta
{


public:
	ContaPoupanca(Cpf cpf, Titular titular);
	float taxaDeSaque()const;
};

