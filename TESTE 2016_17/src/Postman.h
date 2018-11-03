/*
 * Postman.h
 */

#ifndef SRC_POSTMAN_H_
#define SRC_POSTMAN_H_

#include "Mail.h"
#include <string>
#include <vector>
#include <algorithm>

class Postman {
	unsigned int id;
	string name;
	vector<Mail *> myMail;
public:
	Postman();
	Postman(string name);
	void setName(string nm);
	void addMail(Mail *m);
	void addMail(vector<Mail *> mails);
	string getName() const;
	vector<Mail *> getMail() const;
	unsigned int getID() const;
	bool operator<(const Postman &p2);

	static int last_id;
};

template<class T>
unsigned int numberDifferent(const vector<T>  & v1, bool pointer = 0)
{
	vector<T> v2;
	int counter = 0;

	for(size_t i = 0; i < v1.size(); i++)
	{
			if(find(v2.begin(), v2.end(), v1[i]) == v2.end())
			{
				counter++;
				v2.push_back(v1[i]);
			}

	}

	return counter;
}

#endif /* SRC_POSTMAN_H_ */
