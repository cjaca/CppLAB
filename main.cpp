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

		}
	}



	system("pause");
	


}