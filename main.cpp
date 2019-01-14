#include "Data.h"
#include "ListaPracownikow.h"
#include "Napis.h"
#include "Pracownik.h"
#include "Kierownik.h"
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	Pracownik* pracownik;
	ListaPracownikow lista;
	Kierownik kierownik;
	Napis imie, nazwisko;

	char c;
	while (true) {
		cout << " " << endl;
		cout << "1) Dodaj pracownika" << endl;
		cout << "2) Wyswietl liste pracownikow" << endl;
		cout << "3) Usun pracownika z listy" << endl;
		cout << "4) Wyszukaj pracownika" << endl;
		cout << "5) Exportowanie pracowników do pliku" << endl;
		cout << "6) Importowanie pracowników z pliku" << endl;
		cout << "7) Zakoñcz program" << endl;
		cin >> c;
		switch (c) {
		case '1':
			cin.clear();
			pracownik = new Pracownik;
			pracownik->Wpisz();
			lista.Dodaj(*pracownik);
			break;
		case '2':
			lista.WypiszPracownikow();
			break;
		case '3':
			pracownik = new Pracownik;
			pracownik->Wpisz();
			lista.Usun(*pracownik);
			break;
		case '4':
			cout << "Imie i nazwisko pracownika ktorego chcesz znalezc: " << endl;
			imie.Wpisz();
			nazwisko.Wpisz();
			lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			break;
		case '5':
			lista.SaveToFile();
			break;
		case '6':
			lista.ReadFromFile();
			break;
		case '7':
			exit(0);
		}
	}
}