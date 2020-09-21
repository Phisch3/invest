/*
 * main.cpp
 *
 *  Created on: 15.08.2020
 *      Author: phili
 */
#include "konto.h"
#include <iostream>
#include <fstream>
#include <vector>


int main(){


	Konto konto;

	bool done = false;
	while(!done){
		std::cout<< "Moegliche Auswahl: " <<std::endl;
		std::cout<< "(1):  Kaufen einer Aktie." <<std::endl;		// Schlechte position der ausgabe noch ändern
		std::cout<< "(2):  Ausgeben der Aktien." <<std::endl;
		std::cout<< "(3):  Verkaufen einer Aktie." <<std::endl;
		std::cout<< "(4):  Speichern." <<std::endl;
		std::cout<< "(5):  Verlauf einer Aktie." << std::endl;
		std::cout<< "(6):  Beenden!" <<std::endl;
		std::cout<< "(7):  Laden" <<std::endl;


		int eingabe;
		std::cout<< "Eingabe: " <<std::endl;
		std::cin >> eingabe;
		switch(eingabe){
			case 1:
			{
				std::cout<< "Eingeben des Names der gekauften Aktie:" << std::endl;
				std::string name;
				std::cin>> name;

				std::cout<< "Wert der Aktie:" << std::endl;
				double wert;
				std::cin>> wert;

				std::cout<< "Wie viele Aktien:" << std::endl;
				int anzahl;
				std::cin>> anzahl;

				Aktie* aktie = konto.getAktie(name);
				if(aktie == nullptr){
					Aktie* neu = new Aktie(name);
					neu->buyAt(anzahl,wert);
					konto.addAktie(*neu);
				}else{
					aktie->buyAt(anzahl,wert);
				}
				break;
			}
			case 2:
			{
				konto.ausgabeAllAktien();
				break;
			}
			case 3:
			{
				std::cout<< "Eingeben des Names der verkauften Aktie:" << std::endl;
				std::string name;
				std::cin>> name;

				std::cout<< "Wert der Aktie:" << std::endl;
				double wert;
				std::cin>> wert;

				std::cout<< "Wie viele Aktien:" << std::endl;
				int anzahl;
				std::cin>> anzahl;

				Aktie* aktie = konto.getAktie(name);
				if(aktie == nullptr){
					std::cout << "Es gibt keine Aktie mit diesem Namen in der Datenbank!" << std::endl;
				}else{
					if(aktie->getAnzahlAktien()>=anzahl){
						aktie->sellAt(anzahl,wert);
					}else{
						aktie->sellAt(aktie->getAnzahlAktien(),wert);
						std::cout << "Da nur " << aktie->getAnzahlAktien() << "Aktie im Besitz sind werden alle verkauft." << std::endl;
					}
				}
				break;
			}
			case 4:
			{
				ofstream myfile;
				myfile.clear();
				myfile.open ("example.txt");
				for(int index =0;index<konto.getLength();index++){
					Aktie* aktie = konto.getAktie(index);
					string name = aktie->getName();
					myfile << name << std::endl;
					for(int i=0;i<aktie->getLength();i++){
						myfile<<aktie->getTransaction(i)<<std::endl;
					}
					myfile << "$$$$$" << std::endl << std::endl;
				}
				myfile.close();
			}
				break;
			case 5:
			{
				std::cout<< "Eingeben des Names der Aktie:" << std::endl;
				std::string name;
				std::cin>> name;

				Aktie* aktie = konto.getAktie(name);
				if(aktie != nullptr){
					aktie->getStatistik();
				}else{
					std::cout << "Es wurde keine Aktie mit diesem Namen gefunden." <<std::endl;
				}

				break;
			}
			case 6:
			{
				return 0;
				break;
			}
			case 7:
			{

				break;
			}
			default:
				std::cout<< "Fehlerhafte Eingabe!!" <<std::endl;
				break;
		}
	}
}



