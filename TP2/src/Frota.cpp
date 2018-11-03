#include "Frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1)
{
	veiculos.push_back(v1);
}

int Frota::numVeiculos() const
{
	return veiculos.size();
}

int Frota::menorAno() const
{
	int numVeic = numVeiculos();

	if (numVeic == 0)
		return 0;
	else
	{
		int menorA = veiculos[0]->getAno();
		int menorB;

		for (size_t i = 1; i < numVeic; i++)
			{
				menorB = veiculos[i]->getAno();

				if (menorB > menorA)
					menorA = menorB;
			}

		return menorA;
	}
}


