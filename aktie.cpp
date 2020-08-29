/*
 * aktie.cpp
 *
 *  Created on: 12.08.2020
 *      Author: phili
 */
#include "aktie.h"

Aktie::Aktie(string namen): name(namen){

}

string Aktie::getName(){
	return name;
}

int Aktie::getAnzahlAktien(){
	int summe = 0;
	for(vector<int>::iterator it = buy.begin(); it != buy.end();it++ ){
		summe += (*it);
	}
	return summe;
}

double Aktie::getValue(){
	double ergebnis = 0;
	vector<double>::iterator it = preis.end();
	ergebnis = (*(it-1));
	return ergebnis;
}



void Aktie::setValue(double wert){
	preis.push_back(wert);
	buy.push_back(0);
}

void Aktie::buyAt(int anzahl, double wert){
	preis.push_back(wert);
	buy.push_back(anzahl);
}

void Aktie::sellAt(int anzahl, double wert){
	preis.push_back(wert);
	buy.push_back(-anzahl);
}

Aktie::~Aktie(){

}


