#pragma once
#include"stdafx.h"
//#include "Person.h"


class Kunde : public Person
{
private:
	string passwort;
public:
	double abrechnenMonat(int monat, int jahr) {
		double betrag = 0;

		return betrag;
	}

	Kunde(string _name, string _plz, string _eMail, string pw):Person(_name, _plz, _eMail)
	{
		passwort = pw;
	}

	string getPasswort() {
		return passwort;
	}

	virtual ~Kunde()
	{
	}
};

