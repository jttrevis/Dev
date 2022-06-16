#include "Gerente.h"
#include <string>
#include "Cpf.hpp"
#include "Funcionario.hpp"



Gerente::Gerente(Cpf cpf, std::string nome, float salario) :Funcionario(cpf, nome, salario) {

}


float Gerente::bonificacao() const
{
	return getSalario() * 0.5;
}