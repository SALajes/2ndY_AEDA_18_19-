
#include "animal.h"
#include "sstream"


int Animal::maisJovem = 999;

Animal::Animal(string nome, int idade)
{
	this->nome = nome;
	this->idade = idade;
	vet = NULL;

	if(this->idade < maisJovem)
	{
		maisJovem = this->idade;
	}
}

string Animal::getNome() const {
	return nome;
}

int Animal::getMaisJovem()
{
	return maisJovem;
}

Cao::Cao(string nome, int idade, string raca) : Animal(nome, idade)
{
	this->raca = raca;
}

bool Cao::eJovem () const
{
	if(this->idade < 5)
	{ return true; }
	else { return false; }
}

Voador::Voador(int vmax, int amax)
{
	velocidade_max = vmax;
	altura_max = amax;
}

Morcego::Morcego(string nome, int idade, int vmax, int amax) : Animal(nome, idade), Voador(vmax, amax) {}

bool Morcego::eJovem () const
{
	if(this->idade < 4)
	{ return true; }
	else { return false; }
}

string Animal::getInformacao() const
{
	ostringstream info;

	info << nome << ", " << idade << ", " << vet;

	return info.str();
}

string Cao::getInformacao() const
{
	return Animal::getInformacao();
}

string Voador::getInformacao() const
{
	ostringstream info;

	info << this->velocidade_max << ", " << this->altura_max;

	return info.str();
}

string Morcego::getInformacao() const
{
	ostringstream info;
	string info_animal = Animal::getInformacao();

	info << info_animal;

	info_animal = Voador::getInformacao();

	info << ", " << info_animal;

	return info.str();
}
