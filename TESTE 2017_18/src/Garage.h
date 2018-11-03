/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include <string>

using namespace std;

#include"Car.h"

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
	bool compareVehicles(Vehicle * c1, Vehicle * c2);

};
/*
template <>
class Garage <Car> {
	std::vector<Car *> vehicles;
public:
	bool compareVehicles(Car * c1, Car * c2)
	{
		if(c1->getBrand() == c2->getBrand())
		{
			return c1->getPrice() > c1->getPrice();
		}

		return c1->getBrand() < c2->getBrand();

	}
	void sortVehicles()
	{
		sort(vehicles.begin(), vehicles.end(), compareVehicles);
	}

};*/

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

class NoSuchBrandException
{
	string brand;
public:
	NoSuchBrandException(string b){ brand = b; }
	string getBrand() { return brand; }
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template <class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle)
{
	if(vehicles.size() >= capacity)
	{
		return false;
	}

	for(size_t i = 0; i < vehicles.size(); i++)
	{
		if(*vehicles[i] == *vehicle)
		{
			return false;
		}
	}

	vehicles.push_back(vehicle);

	return true;
}

template <class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model)
{
	for(size_t it = 0; it < vehicles.size(); it++)
	{
		if(vehicles[it]->getBrand() == brand && vehicles[it]->getModel() == model)
		{
			Vehicle* c = vehicles[it];

			vehicles.erase(vehicles.begin() + it);

			return c;
		}
	}

	throw NoSuchVehicleException();
}

template <class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const
{
	float sum = 0;
	int count = 0;

	for(size_t i = 0; i < vehicles.size(); i++)
	{
		if(vehicles[i]->getBrand() == brand)
		{
			count++;
			sum = sum + vehicles[i]->getPrice();
		}

	}

	if(count == 0)
	{
		throw NoSuchBrandException(brand);
	}
	else return sum/count;
}

#endif /* SRC_GARAGE_H_ */
