#pragma once
#include <iostream>
#include "Titular.hpp"
#include "Cpf.hpp"


class Conta
{
protected:
	float saldo;
private:
	
	std::string numero;
	Titular titular;
	

public:
	Conta(Cpf cpf, Titular titular);
	void sacar(float valorASacar);
	virtual void depositar(float valorADepositar);
	float getSaldo() const;
	virtual float taxaDeSaque()const =0;
};

