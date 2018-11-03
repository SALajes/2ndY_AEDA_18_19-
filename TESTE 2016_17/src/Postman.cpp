/*
 * Postman.cpp
 */
#include "Postman.h"

int Postman::last_id = 0;

Postman::Postman(): id(0) {}

Postman::Postman(string name) : id(last_id++)
{
	setName(name);
	id = last_id;
	myMail.resize(0);
}

void Postman::setName(string nm){
	name = nm;
}

string Postman::getName() const{
	return name;
}

vector<Mail *> Postman::getMail() const {
	return myMail;
}

void Postman::addMail(Mail *m) {
	myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
	myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
	return id;
}

/*bool Postman::operator<(const Postman &p2)
{
	unsigned int p1_num = numberDifferent(this->myMail);
	unsigned int p2_num = numberDifferent(p2.myMail);

	if (p1_num < p2_num)
		return true;
	else return false;

}*/



