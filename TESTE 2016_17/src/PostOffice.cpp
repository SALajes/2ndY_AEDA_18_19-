/*
 * PostOffice.cpp
 */

#include "PostOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}

vector<Mail *> PostOffice::removePostman(string name)
{
	vector<Mail *> v;

	for(size_t i= 0; i < postmen.size(); i++)
	{
		if(postmen[i].getName() == name)
		{
			v = postmen[i].getMail();

			postmen.erase(postmen.begin() + i);

			break;
		}
	}

	return v;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance)
{
	int sum = 0;
	vector<Mail *> v;

	for(size_t i = 0; i < mailToSend.size(); i++)
	{
		sum = sum + mailToSend[i]->getPrice();

		if(mailToSend[i]->getZipCode() >= firstZipCode && mailToSend[i]->getZipCode() <= lastZipCode)
		{
			addMailToDeliver(mailToSend[i]);
		}
		else
		{
			v.push_back(mailToSend[i]);
		}
	}

	balance = sum;

	mailToSend.resize(0);

	return v;
}

Postman Postman::addMailToPostman(Mail *m, string name)
{

}


