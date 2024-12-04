#include "stdafx.h"
#include "Date.h"

constexpr bool istSchaltjahr(int jahr) {
	return (jahr % 4 == 0 && jahr % 100) || jahr % 400 == 0;
}

Date::Date() {
	aktuell();
}

Date::Date(int t, int m, int j)
	: tag(t),
	monat(m),
	jahr(j) {
}

Date::~Date()
{
}

int Date::getTag() { return tag; }
int Date::getMonat() { return monat; }
int Date::getJahr() { return jahr; }

void Date::setDate(int t, int m, int j) {
	tag = t;
	monat = m;
	jahr = j;
}

void Date::aktuell() { // Systemdatum setzen
					   // {\tt time\_t, time(), tm, localtime()} sind in <ctime>
					   // deklariert
	time_t now{ time(NULL) }; // aktuelle Zeit in s seit 1.1.1970
	tm *z{ std::localtime(&now) }; // Zeiger auf eine vordefinierte Struktur des
								   // Typs \tt{tm}.
	jahr = z->tm_year + 1900;
	monat = z->tm_mon + 1; // \tt{localtime} liefert 0..11
	tag = z->tm_mday;
}

bool Date::istSchaltjahr() {
	return ::istSchaltjahr(jahr); // globale Funktion mit \tt{::}-Operator
}

Date& Date:: operator++() { // Tag hochzählen, präfix
	++tag;
	if (true) { // Monatsende erreicht?
		tag = 1;
		if (++monat > 12) { // Jahresende erreicht?
			monat = 1;
			++jahr;
		}
	}
	return *this;
}

Date Date::operator++(int) { // Tag hochzählen, postfix
	Date temp = *this;
	++*this; // Präfix ++ aufrufen
	return temp;
}

string Date::toString() { // Typumwandlungsoperator
	string temp("tt.mm.jjjj");
	// implizite Umwandlung in char
	temp[0] = tag / 10 + '0';
	temp[1] = tag % 10 + '0';
	temp[3] = monat / 10 + '0';
	temp[4] = monat % 10 + '0';
	std::size_t pos = 9; // letzte Jahresziffer
	std::size_t j = jahr;
	while (j > 0) {
		temp[pos] = j % 10 + '0'; // letzte Ziffer
		j = j / 10;               // letzte Ziffer abtrennen
		--pos;
	}
	return temp;
}

bool Date::operator == (Date& b) {
	return getTag() == b.getTag() && getMonat() == b.getMonat() && getJahr() == b.getJahr();
}

bool Date::operator != (Date &b) {
	return !(*this == b);
}

bool Date::operator < (Date &b) {
	return getJahr() < b.getJahr() ||
		(getJahr() == b.getJahr() && getMonat() < b.getMonat()) ||
		(getJahr() == b.getJahr() && getMonat() == b.getMonat() && getTag() < b.getTag());
}

int Date::datumDifferenz(Date& a, Date& b) {
	if (a == b) // kurzer Prozeß bei Gleichheit
		return 0;
	bool richtigeReihenfolge{ a < b };
	Date frueher{ a };
	Date spaeter{ b };
	if (!richtigeReihenfolge) { // ggf. vertauschen
		frueher = b;
		spaeter = a;
	}
	int differenz{ 0 };
	// Achtung! nicht optimiert! (tageweises Hochzählen)
	while (frueher != spaeter) {
		++differenz;
		++frueher;
	}
	return richtigeReihenfolge ? differenz : -differenz;
}
