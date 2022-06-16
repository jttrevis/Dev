#include "ContaCorrente.h"
#include <iostream>

ContaCorrente::ContaCorrente(Cpf cpf, Titular titular) :Conta(cpf, titular)
{
}

float ContaCorrente::taxaDeSaque()const {
	return 0.05f;
}
void ContaCorrente::transferePara(Conta& destino, float valor)
{
	sacar(valor);
	destino.depositar(valor);
}
