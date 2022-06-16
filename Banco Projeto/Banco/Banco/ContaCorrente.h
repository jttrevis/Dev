#pragma once
#include "Conta.hpp"
#include <iostream>



class ContaCorrente final: public Conta
{


public:
	ContaCorrente(Cpf cpf, Titular titular);
	float taxaDeSaque()const;
	void transferePara(Conta& conta, float valor);
};

