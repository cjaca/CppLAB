#pragma once
#include "Pracownik.h"
class ListaPracownikow
{
private: 
	Pracownik* m_pPoczatek; //nowy pracownik
	int m_nLiczbaPracownikow;


public:
	ListaPracownikow();
	~ListaPracownikow();
	void Dodaj(const Pracownik & p); //zadaniem tej metody jest wstawienie kopii obiektu typu Pracownik przekazanego do metody w kolejnosc rosnacej (uzyj metody Porownaj).
									// Metoda ma dodawaæ tylko unikalne obekty, czyli takie, ktorych dane sa rozne od istniejacych na liscie obiektow.
	void Usun(const Pracownik & wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie);
	void SaveToFile() const;
	void ReadFromFile();
};

