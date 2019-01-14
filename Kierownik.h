#pragma once
#include "Pracownik.h"
class Kierownik :
	public Pracownik
{
public:
	Kierownik();
	Kierownik(const Kierownik & wzor);
	~Kierownik();
	Kierownik & operator=(const Kierownik & wzor);
	bool operator==(const Kierownik & wzor) const;
	virtual void WypiszDane();
	virtual Pracownik* KopiaObiektu();
	friend ostream & operator<<(ostream & wy, const Kierownik &s);
	friend istream & operator>>(istream & we, Kierownik &s);
private:
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;

};

