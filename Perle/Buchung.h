#pragma once
#include "stdafx.h"
#include "Date.h"
#include "Kunde.h"
class Reinigungskraft;

class Buchung
{
private:
	Date* reinigungsDatum;
	int anzahlStunden;
	Kunde* kunde;
	Reinigungskraft* kraft;

public:

	Buchung (Kunde* k, Reinigungskraft* rk, Date* d, int anzSt) 
	{
		reinigungsDatum = d;
		anzahlStunden = anzSt;
		kunde = k;
		kraft = rk;
	//	rk->hinzufuegenBuchung(this);
	//	k->hinzufuegenBuchung(this);
	}

	Date* getReinigungsDatum() {
		return reinigungsDatum;
	}

	int getAnzahlStunden() {
		return anzahlStunden;
	}


	~Buchung()
	{
	}
};

