#include "ListaPracownikow.h"
#include <fstream>




ListaPracownikow::ListaPracownikow() //inicjowanie odpowiednich pol skladowych
{
	m_nLiczbaPracownikow = 0;
	m_pPoczatek = nullptr;
}


ListaPracownikow::~ListaPracownikow()
{
	Pracownik *aktualny = m_pPoczatek;
	if (m_nLiczbaPracownikow == 0)
	{
		cout << "Lista pracownikow jest pusta!" << endl;
	}
	else
	{
		while (aktualny != nullptr)
		{
			aktualny = aktualny->m_pNastepny;
			delete m_pPoczatek;
			m_pPoczatek = aktualny;

		}
	}
}

void ListaPracownikow::Dodaj(const Pracownik & p)
{
	Pracownik *k = p.KopiaObiektu();
	Pracownik *pomocnik = m_pPoczatek;
	Pracownik *pop = nullptr;

	if (m_nLiczbaPracownikow == 0)
	{
		m_pPoczatek = k;
		k->m_pNastepny = nullptr;
		m_nLiczbaPracownikow++;
		return;
	}
	else
	{
		while (pomocnik != nullptr) // czyli wykonywanie dopoki nie dojdzie do konca
		{
			if (pomocnik->Porownaj(p) > 0)
			{
				Pracownik *k = p.KopiaObiektu();
				if (pop)
				{
					pop->m_pNastepny = k;
				}
				else
					m_pPoczatek = k;
				k->m_pNastepny = pomocnik;
				m_nLiczbaPracownikow++;
				return;
			}
			else if (pomocnik->Porownaj(p) == 0)
			{
				cout << "obiekt juz wystepuje" << endl;
				return;
			}
			pop = pomocnik;
			pomocnik = pomocnik->m_pNastepny;
		}
		Pracownik *k = p.KopiaObiektu();
		pop->m_pNastepny = k;
		k->m_pNastepny = nullptr;
		m_nLiczbaPracownikow++;
	}
}


void ListaPracownikow::Usun(const Pracownik & wzorzec)
{
	Pracownik *aktualny = m_pPoczatek;
	Pracownik *poprzedni = nullptr;
	
	if (m_nLiczbaPracownikow == 0) {
		std::cout << "Lista pracownikow jest pusta" << std::endl;
	}
	else
	{
		for (int i = 0; i <= m_nLiczbaPracownikow; i++)
		{
			if (aktualny->Porownaj(wzorzec) == 0)
			{
				if (aktualny == m_pPoczatek)
				{
					m_pPoczatek = aktualny->m_pNastepny;
					m_nLiczbaPracownikow--;
					return;
				}
				else
				{
					poprzedni->m_pNastepny = aktualny->m_pNastepny;
					m_nLiczbaPracownikow--;
					return;
				}
			}
			else
			{
				poprzedni = aktualny;
				aktualny = aktualny->m_pNastepny;
			}
		}
		std::cout << "Nie znaleziono pracownika na liscie" << std::endl;
	}

}

void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik* aktualny = m_pPoczatek;
	if (m_nLiczbaPracownikow == 0)
	{
		std::cout << "Lista pracownikow jest pusta" << std::endl;
	}
	else
	{
		for (int i = 1; i <= m_nLiczbaPracownikow; i++)
		{
			std::cout << "Pracownik nr" << i << ": " << std::endl;
			aktualny->WypiszDane();
			aktualny = aktualny->m_pNastepny;
			std::cout << " " << std::endl;
		}
	}

}

const Pracownik * ListaPracownikow::Szukaj(const char * nazwisko, const char * imie)
{
	Pracownik* aktualny = m_pPoczatek;
	if (m_nLiczbaPracownikow == 0)
	{
		std::cout << "Lista pracownikow jest pusta" << std::endl;
		return nullptr;
	}
	else
	{
		for (int i = 1; i <= m_nLiczbaPracownikow; i++)
		{
			if ((aktualny->SprawdzImie(imie) == 0) && (aktualny->SprawdzNazwisko(nazwisko) == 0))
			{
				std::cout << "Znaleziono pracownika" << std::endl;
				aktualny->Wypisz();
				std::cout << " " << std::endl;
				return aktualny;
			}
			else
			{
				aktualny = aktualny->m_pNastepny;
				notfound = true;
			}
		}
		if (notfound == true)
		{
			notfound = false;
			std::cout << "Nie znaleziono pracownika" << std::endl;
		}
		return nullptr;
	}
}

void ListaPracownikow::SaveToFile() const
{
	ofstream plik;
	plik.open("plik.txt", fstream::out);
	if (!plik.good())
	{
		cout << "blad otwarcia pliku" << endl;
	}
	else
	{
		Pracownik * aktualny = m_pPoczatek;
		for (int i = 0; i < m_nLiczbaPracownikow; i++) {
			if (aktualny != nullptr)
			{
				plik << *aktualny << endl;
			}
			aktualny = aktualny->m_pNastepny;
		}
		
	}
	plik.close();
}

void ListaPracownikow::ReadFromFile()
{
	ifstream plik;
	plik.open("plik.txt", fstream::out);

	if (!plik.good())
	{
		cout << "blad otwarcia pliku" << endl;
	}
	else
	{
		m_nLiczbaPracownikow = 0;
		m_pPoczatek = nullptr;
		Pracownik * tymczasowy = new Pracownik();
		while (plik >> *tymczasowy)
		{
			Dodaj(*tymczasowy);
			tymczasowy = new Pracownik();
		}

	}
	plik.close();
}


