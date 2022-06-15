#include "Pessoa.hpp"




Pessoa::Pessoa(Cpf cpf, std::string nome) : cpf(cpf), nome(nome)
{
	verificaTamanhoDoNome();
}
void Pessoa::verificaTamanhoDoNome()
{
	if (nome.size() < 4)
	{
		std::cout << "Nome muito curto " << std::endl;
		exit(1);
	}
}