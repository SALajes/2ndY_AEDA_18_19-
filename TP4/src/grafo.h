#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;
template <class N> class NoRepetido;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template <class N, class A>  //construtor
Grafo<N,A>::Grafo () {} //Grafo<string,int> grf1;

template <class N, class A>  //destrutor
Grafo<N,A>::~Grafo ()
{
	/*//com iteradores
	 * vector < No<N,A> * >::iterator it = nos.begin();
	 * for(;it != nos.end(); it++)
	 * {
	 * 		delete *it;
	 * }
	 */ //vai dar erro por causa do template de dados não definidos, portanto devemos escrever typename antes da declaração do iterador

	for(size_t i=0; i < nos.size(); i++)
	{
		delete nos[i];
	}
}

template <class N, class A>
int Grafo<N,A>::numNos() const
{
	return nos.size();
}

template <class N, class A>
int Grafo<N,A>::numArestas() const
{
	int count = 0;
	int arestas;

	for(size_t i = 0; i < nos.size(); i++)
	{
		arestas = nos[i]->arestas.size(); // -> faz aceder ao objeto apontado por nos[i], enquanto que arestas é mesmo um objeto, portanto, utilizamos .
		count = count + arestas;
	}

	return count;
}

template <class N, class A>
Grafo<N,A>& Grafo<N,A>::inserirNo(const N &dados)
{
	for(size_t i=0; i < nos.size(); i++)
	{
		if(nos[i]->info == dados)
		{
			throw NoRepetido(dados); //lança exceçao
		}
	}

	No<N,A> *no = new No<N,A>(dados); //quando se adiciona um no a um grafo temos de respeitar os parametros deste *(apontador para um) No<N,A>

	this->nos.push_back(no);

	return *this;
}

template <class N, class A>
Grafo<N,A>& Grafo<N,A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
	for(size_t i=0; i < nos.size(); i++)
	{
		if(nos)
	}
}

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


// excecao  NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }



// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};
template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }
