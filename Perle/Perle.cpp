// Perle.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Reinigungskraft.h"
#include "Date.h"
#include "Buchung.h"
//#include "Kunde.h"
#include "PerleVerwaltung.h"


int main()
{
	PerleVerwaltung pw;
	Kunde* k = pw.registriereKunde("Mark Rein", "60128", "mark@reinlein.info", "marki700");
	Reinigungskraft* rk = pw.hinzufuegenReinigungskraft("Silvie Proper","60128","s.proper@t-online.de", 11.80);

	// Sequendiagramm 2.2.3
	pw.erstelleBuchung(k, rk, new Date(18, 4, 2018), 4);
	int b = rk->abrechnenMonat(4, 2018); 
	cout << "Geld: " << b << endl;
	cout << rk->toString()<< endl;

	// Überprüfung 
	if (pw.anmelden("mark@reinlein.info", "marki700") == k)
		cout << "Kunde angemeldet" << endl;
	else
		cout << "Anmeldung fehlgeschlagen" << endl;
	return 0;
}

