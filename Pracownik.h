#pragma once
#include "Napis.h"
#include "Data.h"
#include <time.h>
class Pracownik
{
public:
	Pracownik(const char * im="", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik & wzor);
	~Pracownik();
	const char* Imie() const;
	const char* Nazwisko() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;

	//Zajecia 3: Rozbudowa projektu - cz.I
	Pracownik* m_pNastepny;
	int Porownaj(const Pracownik & wzorzec) const;

	Pracownik & operator=(const Pracownik & wzor);
	bool operator==(const Pracownik & wzor) const;

	friend ostream & operator<<(ostream & wy, const Pracownik &p);
	friend istream & operator>>(istream & we, Pracownik & p);

	virtual void WypiszDane(); //wypisuje na ekranie wszystkie dane o pracowniku
	virtual Pracownik* KopiaObiektu()const;  // zwrocenie nowo stworzonego obiektu


private: 
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;

	const int m_nIDZatrudnienia; //unikalny id pracownika
};

