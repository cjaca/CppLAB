#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	Pracownik nr1;
	nr1.Wypisz();
	cout << endl;
	nr1.Wpisz();
	cout << nr1.SprawdzImie("Jan") << endl;
	cout << nr1.SprawdzNazwisko("Kowalski") << endl;
	nr1.Wypisz();
	cout << endl;

	system("pause");
	


}