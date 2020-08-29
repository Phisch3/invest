/*
 * main.cpp
 *
 *  Created on: 15.08.2020
 *      Author: phili
 */
#include "konto.h"


int main(){

	Konto konto;

	bool done = false;
	while(!done){
		std::cout<< "Moegliche Auswahl: " <<std::endl;
		std::cout<< "(1):  Einfügen einer neuen Aktie." <<std::endl;
		std::cout<< "(2):  Ausgeben der Aktien" <<std::endl;
		std::cout<< "(6):  Beenden!" <<std::endl;


		int eingabe;
		std::cout<< "Eingabe: " <<std::endl;
		std::cin >> eingabe;
		switch(eingabe){
			case 1:
			{
				std::string name;
				double wert;
				int anzahl;
				std::cout<< "Name der Aktie: " <<std::endl;
				std::cin >> name;
				fflush(stdin);
				std::cout<< "Wert der Aktie: " <<std::endl;
				std::cin >> wert;
				fflush(stdin);
				std::cout<< "Anzahl der Aktie: " <<std::endl;
				std::cin >> anzahl;
				fflush(stdin);
				Aktie* aktie = new Aktie(name);
				aktie->buyAt(anzahl,wert);
				konto.addAktie(*aktie);
				break;
			}
			case 2:
			{
				konto.ausgabeAllAktien();
				break;
			}
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				return 0;
				break;
			default:
				std::cout<< "Fehlerhafte Eingabe!!" <<std::endl;
				break;
		}
	}
}



