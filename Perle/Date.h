#pragma once
class Date
{
private:
	int tag;
	int monat;
	int jahr;

public:
	Date();
	Date(int, int, int);
	~Date();

	int getTag();
	int getMonat();
	int getJahr();

	void setDate(int, int, int);
	void aktuell();
	bool istSchaltjahr();

	Date & operator++();
	Date operator++(int);

	bool operator == (Date &);
	bool operator != (Date &);
	bool operator < (Date &);

	int datumDifferenz(Date&, Date&);

	string toString();
};
