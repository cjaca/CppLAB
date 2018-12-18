#include "Data.h"
#include "ListaPracownikow.h"
#include "Napis.h"
#include "Pracownik.h"
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	Pracownik* pracownik;
	ListaPracownikow lista;

	char c;
	while (true) {
		cout << " " << endl;
		cout << "1 - dodawanie pracownika" << endl;
		cout << "2 - wyswietlanie listy pracownikow" << endl;
		cout << "3 - usuwanie z listy pracownikow" << endl;
		cout << "4 - dodawanie pracownikow do pliku" << endl;
		cout << "5 - dodawanie pracownikow z pliku" << endl;
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
			lista.SaveToFile();
			break;

		case '5':
			lista.ReadFromFile();
			break;

		}
	}



	system("pause");
	


}