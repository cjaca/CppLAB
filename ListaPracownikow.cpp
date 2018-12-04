#include "ListaPracownikow.h"



ListaPracownikow::ListaPracownikow() //inicjowanie odpowiednich pol skladowych
{
	m_nLiczbaPracownikow = 0;
	m_pPoczatek = nullptr;
}


ListaPracownikow::~ListaPracownikow()
{
}

////void ListaPracownikow::Dodaj(const Pracownik & p)
//{
//
//	Pracownik *k = new Pracownik(p);
//
//	if (m_nLiczbaPracownikow == 0)
//	{
//		m_pPoczatek = new Pracownik(p);
//		m_nLiczbaPracownikow++;
//		m_pPoczatek->m_pNastepny = nullptr;
//	}
//	else if(m_nLiczbaPracownikow == 1)
//	{
//		if (m_pPoczatek->SprawdzNazwisko(p.Nazwisko()) > 0)
//		{
//			m_pPoczatek = new Pracownik(p);
//			k->m_pNastepny = m_pPoczatek;
//			m_nLiczbaPracownikow++;
//			return;
//		}
//		else if (m_pPoczatek->SprawdzNazwisko(p.Nazwisko()) < 0)
//		{
//			m_pPoczatek = new Pracownik(p);
//			m_pPoczatek = k->m_pNastepny;
//			k->m_pNastepny = nullptr;
//			m_nLiczbaPracownikow++;
//			return;
//		}
//	}
//	else
//	{
//		m_pPoczatek = new Pracownik(p);
//		if (m_pPoczatek->SprawdzNazwisko(p.Nazwisko()) > 0)
//		{
//			m_pPoczatek = k;
//			k->m_pNastepny = m_pPoczatek;
//			m_nLiczbaPracownikow++;
//			return;
//		}
//		else if (m_pPoczatek->SprawdzNazwisko(p.Nazwisko()) < 0)
//		{
//			m_pPoczatek -> m_pNastepny;
//			return;
//		}
//
//	}
//}
//
//void ListaPracownikow::Dodaj(const Pracownik & p)
//{
//	Pracownik *k = new Pracownik(p);
//	Pracownik *aktualny = m_pPoczatek;
//	Pracownik *nastepny;
//	int licznik = 0;
//
//
//	if (m_nLiczbaPracownikow == 0)
//	{
//		m_pPoczatek = new Pracownik(p);
//		k->m_pNastepny = nullptr;
//		m_nLiczbaPracownikow++;
//		return;
//	}
//	else if (m_nLiczbaPracownikow == 1)
//	{
//		if (aktualny->SprawdzNazwisko(k->Nazwisko()) > 0)
//		{
//			m_pPoczatek = new Pracownik(p);
//			k->m_pNastepny = aktualny;
//			m_nLiczbaPracownikow++;
//			return;
//
//		}
//		else if (aktualny->SprawdzNazwisko(k->Nazwisko()) < 0)
//		{
//			aktualny->m_pNastepny = k;
//			k->m_pNastepny = nullptr;
//			m_nLiczbaPracownikow++;
//			return;
//		}
//	}
//	else
//	{
//		nastepny = aktualny->m_pNastepny;
//		if (aktualny->SprawdzNazwisko(k->Nazwisko()) > 0)
//		{
//			m_pPoczatek = new Pracownik(p);
//			k->m_pNastepny = aktualny;
//			m_nLiczbaPracownikow++;
//			return;
//		}
//		while (licznik <= m_nLiczbaPracownikow)
//		{
//			if (nastepny->SprawdzNazwisko(k->Nazwisko()) > 0)
//			{
//				aktualny->m_pNastepny = k;
//				k->m_pNastepny = nastepny;
//				m_nLiczbaPracownikow++;
//				return;
//			}
//			else if (nastepny->SprawdzNazwisko(k->Nazwisko()) < 0)
//			{
//				aktualny = nastepny;
//				nastepny = aktualny->m_pNastepny;
//				licznik++;
//			}
//			if (nastepny == nullptr)
//			{
//				aktualny->m_pNastepny = k;
//				k->m_pNastepny = nullptr;
//				m_nLiczbaPracownikow++;
//				return;
//			}
//		}
//	}
//
//}

void ListaPracownikow::Usun(const Pracownik & wzorzec)
{
	/*Pracownik *aktualny = m_pPoczatek;
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
	}*/

	if (m_pPoczatek->Porownaj(wzorzec) == 0)
	{
		if (m_pPoczatek->m_pNastepny != nullptr)
		{
			m_pPoczatek = m_pPoczatek->m_pNastepny;
		}
		else
		{
			m_pPoczatek = nullptr;
			return;
		}
	}
	Pracownik *pomocnik = m_pPoczatek;
	while(pomocnik->m_pNastepny !=nullptr)
	{ 
		pomocnik = pomocnik->m_pNastepny;
		if (pomocnik->Porownaj(wzorzec) == 0)
		{
			if (pomocnik->m_pNastepny != nullptr)
				pomocnik = pomocnik->m_pNastepny;
			else
				pomocnik = nullptr;
			return;
		}
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
			m_pPoczatek->Wypisz();
			aktualny = aktualny->m_pNastepny;
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

			}
		}
		return nullptr;
	}
}
