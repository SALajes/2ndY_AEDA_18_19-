#include "zoo.h"


int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

void Zoo::adicionaAnimal(Animal *a1)
{
	animais.push_back(a1);
}

string Zoo::getInformacao() const
{
	string info;

	for (int i = 0; i < numAnimais(); i++)
	{
		info = info + animais[i]->getInformacao() + "/n";
	}

	return info;
}

bool Zoo::animalJovem(string nomeA)
{
	for(size_t i = 0; i < animais.size(); i++)
	{
		if(animais[i]->getNome() == nomeA)
		{
			return animais[i]->eJovem();
		}
	}

	return false;
}

void Zoo::alocaVeterinarios(istream &isV)
{
	ifstream i_file;

	i_file.open(isV);

	string vet_info;

	int count=0;
	string name, num_ord;

	while(getline(i_file, vet_info))
	{
		count++;

		if(count == 1)
		{
			name = vet_info;
			count++;
		}
		else
		{
			num_ord = vet_info;

			Veterinario* v(name, num_ord);

			veterinarios.push_back(v);

			count = 0;
		}
	}

	i_file.close();

	size_t n = 0;

	for(size_t i = 0; i < animais.size(); i++)
	{
		if(n == veterinarios.size())
		{
			n = 0;
		}

		animais[i]->vet = veterinarios[n];

		n++;
	}
}

bool Zoo::removeVeterinario (string nomeV)
{
	bool vet_exists = 0;
	vector<Veterinario *>::iterator it = veterinarios.begin();

	for (; it < veterinarios.size(); it++)
	{
		if(veterinarios[it]->nome == nomeV)
		{
			vet_exists = 1;

			veterinarios.erase(it);

			break;
		}
	}

	if(!vet_exists || veterinarios.size() < 1)
	{
		return false;
	}

	size_t n = it;

	for (size_t i = 0; i < animais.size(); i++)
	{
		if(animais[i]->vet->nome == nomeV)
		{
			if(n == veterinarios.size())
			{
				n = 0;
			}

			animais[i]->vet = veterinarios[n];
		}
	}
}

bool Zoo::operator < (Zoo& zoo2) const
{
	int sum1 = 0, sum2 = 0;
	vector<Animal *> v1, v2;

	v1 = this->animais;
	v2 = zoo2.animais;

	for(size_t i = 0; i < v1.size(); i++)
	{
		sum1 = sum1 + v1[i]->idade;
	}

	for(size_t i = 0; i < v2.size(); i++)
	{
		sum2 = sum2 + v2[i]->idade;
	}

	if(sum1 < sum2)
	{
		return 1;
	}
	else return 0;
}
