#include "Parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli)
:lotacao(lot) , numMaximoClientes(nMaxCli) //because the variables are constants, we have to initialize them like this
{
	this->vagas = lotacao;
}

unsigned int ParqueEstacionamento::getNumLugares() const
{
	return this->lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const
{
	return this->numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const
{
	for (size_t i = 0; i < clientes.size(); i++)
	{
		if(clientes[i].nome == nome)
		{
			return i;
		}
	}

	return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) //this->posicaoCliente(nome) != -1
{
	if(clientes.size() == numMaximoClientes || this->posicaoCliente(nome) != -1)
		return false;
	else
	{
		InfoCartao Novo;

		Novo.nome = nome;
		Novo.presente = true;

		clientes.push_back(Novo);

		return true;
	}
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if (clientes.size() == numMaximoClientes || this->posicaoCliente(nome) != -1)
		return true;
	else return false;
}

bool ParqueEstacionamento::retiraCliente(const string & nome)
{

}

















