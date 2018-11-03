#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <vector>

using namespace std;

bool InfoCartao::operator == (const InfoCartao &ic1) const
{
	return this->nome == ic1.nome;
}

bool InfoCartao::operator < (const InfoCartao &ic1) const
{
	if(this->frequencia == ic1.frequencia)
	{
		string nome1 = this->nome;
		string nome2 = ic1.nome;
		const size_t i = min(nome1.size(), nome2.size());

		for(size_t n = 0; n < i; n++)
		{
			if(nome1[n] > nome2[n])
			{
				return true;
			}
			else if(nome1[n] < nome2[n])
			{
				return false;
			}
		}

		if(nome1.size() == i)
		{
			return true;
		}
		else return false;

	}
	else return this->frequencia < ic1.frequencia;
}


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }


bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
    info.frequencia = 0;
	clientes.push_back(info);
	numClientes++;
	return true;
}
 
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}
  
unsigned int ParqueEstacionamento::getNumLugares() const
{
	return lotacao;
}
                   
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{
	return lotacao-vagas;
}

bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	vagas--;
	clientes[pos].frequencia++;
	return true;
}

bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const
{
	InfoCartao ic1;

	ic1.nome = nome;

	return sequentialSearch(clientes, ic1);
}

int ParqueEstacionamento::getFrequencia(const string &nome)const
{
	int i = posicaoCliente(nome);

	if(i == -1)
		throw ClienteNaoExistente(nome);

	return clientes[i].frequencia;
}

void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
	insertionSort(clientes);
}

vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2)
{


	ordenaClientesPorFrequencia();
}

