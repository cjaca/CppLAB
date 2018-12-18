#include "Pracownik.h"



Pracownik::Pracownik(const char * im , const char * naz , int dzien , int miesiac , int rok )
	:m_Imie(im), m_Nazwisko(naz), m_DataUrodzenia(dzien,miesiac,rok), m_nIDZatrudnienia(time(0))
{

}

Pracownik::Pracownik(const Pracownik & wzor)
	: m_nIDZatrudnienia(wzor.m_nIDZatrudnienia), m_Imie(wzor.m_Imie), m_Nazwisko(wzor.m_Nazwisko),m_DataUrodzenia(wzor.m_DataUrodzenia)
{

}


Pracownik::~Pracownik()
{
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << " ";
	m_Nazwisko.Wypisz();
	cout << " ";
	m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz()
{
	cout << " Podaj imie: ";
	m_Imie.Wpisz();
	cout << "Podaj nazwisko: ";
	m_Nazwisko.Wpisz();
	cout << "Podaj date urodzenia: ";
	m_DataUrodzenia.Wpisz();
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::Porownaj(const Pracownik & wzorzec) const
{	//zwraca 0 gdy obiekt, na rzecz ktorego wywolywana jest metoda zgadza sie ze wzorcem przekazanym do metody
	if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 &&
		m_Imie.SprawdzNapis(wzorzec.Imie()) == 0 &&
		m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) == 0)
		return 0; 
	//gdy nazwisko (nastepnie imie i data urodzin), jest alfabetycznie dalej (w przypadku daty - kolejnosc chronologiczna) niz przekazanego
	else { 
		if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) > 0)
			return 1;
		else if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 && m_Imie.SprawdzNapis(wzorzec.Imie()) > 0)
			return 1;
		else if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 && m_Imie.SprawdzNapis(wzorzec.Imie()) == 0 && m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) > 0)
			return 1;
		else
			return -1;  //w przeciwnej sytacji niz wyzej
	}
}

Pracownik & Pracownik::operator=(const Pracownik & wzor)
{
	// TODO: tu wstawiæ instrukcjê return

	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
	m_DataUrodzenia = wzor.m_DataUrodzenia;
	return *this;

}

bool Pracownik::operator==(const Pracownik & wzor) const
{

	if (this->Porownaj(wzor) == 0) return true;
	else return false;
}

ostream & operator<<(ostream & wy, const Pracownik & p)
{
	// TODO: tu wstawiæ instrukcjê return
	wy << p.m_Imie << " " << p.m_Nazwisko << " " << p.m_DataUrodzenia;
	return wy;
}

istream & operator>>(istream & we, Pracownik & p)
{
	// TODO: tu wstawiæ instrukcjê return
	we >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia;
	return we;
}
