#pragma once
#include "Pessoa.hpp"
#include "Cpf.hpp"
#include <string>
#include "Caixa.h"

class Funcionario : public Pessoa
{
private:
    float salario;

public:
    Funcionario(Cpf cpf, std::string nome, float salario);
    std::string recuperaNome()const;
    virtual float bonificacao() const;
    float getSalario() const;
};

