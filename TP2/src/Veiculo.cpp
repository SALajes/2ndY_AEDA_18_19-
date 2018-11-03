#include "Veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a)
{
	marca = mc;
	mes = m;
	ano = a;
}

int Veiculo::getAno() const
{
	return ano;
}

string Veiculo::getMarca() const
{
	return marca;
}

virtual int Veiculo::info() const
{
	cout << marca << endl << mes << endl << ano << endl;

	return 3;
}

Motorizado::Motorizado(string mc, int m, int a,string c,int cil) : Veiculo(mc, m, a)
{
	combustivel = c;
	cilindrada = cil;
}

string Motorizado::getCombustivel() const
{
	return combustivel;
}

virtual int Motorizado::info() const
{
	int x = Veiculo::info();

	cout << combustivel << endl << cilindrada << endl;

	return x + 2;
}

Automovel::Automovel(string mc, int m, int a,string c, int cil) : Motorizado(mc, m, a, c, cil) {}

int Automovel::info() const
{
	return Motorizado::info();
}

Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm) : Motorizado(mc, m, a, c, cil)
{
	carga_maxima = cm;
}

int Camiao::info() const
{
	int x = Motorizado::info();

	cout << carga_maxima << endl;

	return x + 1;
}

Bicicleta::Bicicleta(string mc, int m, int a,string t) : Veiculo(mc, m, a)
{
	tipo = t;
}

int Bicicleta::info() const
{
	int x = Veiculo::info();

	cout << tipo << endl;

	return x + 1;
}


