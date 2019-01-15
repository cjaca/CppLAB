#include "Kierownik.h"
#include <iostream>


Kierownik::Kierownik()
{
	m_NazwaDzialu = "";
	m_nLiczbaPracownikow = 1;
}

Kierownik::Kierownik(const Kierownik & wzor):Pracownik(wzor)
{
	m_NazwaDzialu = wzor.m_NazwaDzialu;
	m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
}


Kierownik::~Kierownik()
{
}

Kierownik & Kierownik::operator=(const Kierownik & wzor)
{
	// TODO: tu wstawiæ instrukcjê return
	Pracownik::operator= (wzor);
	m_NazwaDzialu = wzor.m_NazwaDzialu;
	m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
	return *this;
}

bool Kierownik::operator==(const Kierownik & wzor) const
{
	if (this == &wzor)
	{
		return true;
	}
	if (Porownaj(wzor) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Kierownik::Wpisz()
{
	Pracownik::Wpisz();
	cout << "Podaj nazwe dzialu: ";
	m_NazwaDzialu.Wpisz();
}

void Kierownik::WypiszDane()
{
	Pracownik::WypiszDane();
	std::cout  <<", Nazwa dzialu: "<< m_NazwaDzialu << std::endl;
}

Pracownik * Kierownik::KopiaObiektu()const
{
	Kierownik * nowy;
	nowy = new Kierownik(*this);
	return nowy;
}

ostream & operator<<(ostream & wy, const Kierownik & s)
{
	// TODO: tu wstawiæ instrukcjê return
	wy << s <<  s.m_NazwaDzialu;
	return wy;
}

istream & operator>>(istream & we, Kierownik & s)
{
	// TODO: tu wstawiæ instrukcjê return
	we >> s >> s.m_NazwaDzialu ;
	return we;
}
