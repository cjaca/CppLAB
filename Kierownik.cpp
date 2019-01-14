#include "Kierownik.h"
#include <iostream>


Kierownik::Kierownik()
{
	m_NazwaDzialu = "";
	m_nLiczbaPracownikow = 1;
}

Kierownik::Kierownik(const Kierownik & wzor)
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
	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
	m_DataUrodzenia = wzor.m_DataUrodzenia;
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

void Kierownik::WypiszDane()
{
	std::cout << m_Imie << " " << m_Nazwisko << " " << m_DataUrodzenia << " " << m_NazwaDzialu << " " << m_nIDZatrudnienia << std::endl;
}

Pracownik * Kierownik::KopiaObiektu()
{
	Kierownik * nowy;
	nowy = new Kierownik(*this);
	return nowy;
}

ostream & operator<<(ostream & wy, const Kierownik & s)
{
	// TODO: tu wstawiæ instrukcjê return
	wy << s.m_Imie << " " << s.m_Nazwisko << " " << s.m_DataUrodzenia <<" "<< s.m_NazwaDzialu<<" " << s.m_nLiczbaPracownikow;
	return wy;
}

istream & operator>>(istream & we, Kierownik & s)
{
	// TODO: tu wstawiæ instrukcjê return
	we >> s.m_Imie >> s.m_Nazwisko >>s.m_DataUrodzenia >> s.m_NazwaDzialu >> s.m_nLiczbaPracownikow;
	return we;
}
