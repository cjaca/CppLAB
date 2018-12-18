#include "Napis.h"
using namespace std;




Napis::Napis(const char* nap)
{
	m_nD1 = strlen(nap) + 1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, nap);
}

Napis::Napis(const Napis & wzor)
{
	m_nD1 = wzor.m_nD1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
}


Napis::~Napis()
{
	delete[] m_pszNapis;
}

const char * Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	m_nD1 = strlen(nowy_napis) + 1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	cout << m_pszNapis;
}

void Napis::Wpisz()
{
	string napis;
	cin >> napis;
	Ustaw(napis.c_str());
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	return strcmp(m_pszNapis, por_napis);
}

Napis & Napis::operator=(const Napis & wzor)
{
	// TODO: tu wstawiæ instrukcjê return

	if (this == &wzor)
	{
		return *this;
	}
	m_nD1 = wzor.m_nD1;
	m_pszNapis = new char[m_nD1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
	return *this;
}

bool Napis::operator==(const Napis & wzor) const //sam to robilem i nie jestem pewny do konca czy to jest dobrze
{
	if (this->m_pszNapis == wzor.m_pszNapis) return true;
	else return false;
}

ostream & operator<<(ostream & wy, const Napis & p)
{
	wy << p.m_pszNapis;
	return wy;
}

istream & operator>>(istream & we, Napis & p)
{
	string nowy;
	we >> nowy;
	p.m_nD1 = nowy.length() + 1;
	p.m_pszNapis = new char[p.m_nD1];
	strcpy(p.m_pszNapis, nowy.c_str());
	return we;
};
