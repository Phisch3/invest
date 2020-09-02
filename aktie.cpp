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
	int summe =0;
	for(vector<int>::iterator it = buy.begin(); it != buy.end();it++ ){
		summe += (*it);
	}
	return summe;
}

double Aktie::getValue(){
	vector<double>::iterator it = preis.end();
	return *(--it);
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

void Aktie::getStatistik(){
	std::cout << "Aktie: "<< name <<std::endl;
	vector<double>::iterator itp = preis.begin();
	vector<int>::iterator itb = buy.begin();
	for(int i = 0; i< (int)buy.size();i++ ){
		std::cout << "		"<< i+1 <<". Transaktion		Preis: " << *(itp+i) << "		Anzahl: " << *(itb+i)<<std::endl;
	}
	std::cout<<std::endl;	//Formatierung
}

Aktie::~Aktie(){

}


