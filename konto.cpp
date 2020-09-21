/*
 * konto.cpp
 *
 *  Created on: 12.08.2020
 *      Author: phili
 */
#include "konto.h"



Aktie* Konto::getAktie(int index){
	if(index < (int)aktienListe.size()){
		vector<Aktie>::iterator it = aktienListe.begin();
		it += index;
		return &(*it);
	}else{
		std::cout << "Dieser Inedx ist noch keiner Aktie zu gewiesen!" << std::endl;
		return nullptr;
	}
}

Aktie* Konto::getAktie(string name){
		for(vector<Aktie>::iterator it = aktienListe.begin(); it != aktienListe.end();it++){
			if((*it).getName() == name){
				return &(*it);
			}
		}
		return nullptr;
}

void Konto::addAktie(Aktie aktie){
	aktienListe.push_back(aktie);
}

void Konto::ausgabeAllAktien(){
	for(vector<Aktie>::iterator it = aktienListe.begin(); it != aktienListe.end();it++){
			std::string name = it->getName();
			double wert = it->getValue();
			int anzahl = it->getAnzahlAktien();
			std::cout << "Name: " << name << "		Wert: " << wert  << "		Anzahl: " << anzahl << "		Gesamt Wert: " << anzahl*wert << std::endl;
	}
}

int Konto::getLength(){
	return (int)aktienListe.size();
}


