/*
 * aktie.h
 *
 *  Created on: 12.08.2020
 *      Author: phili
 */

#ifndef AKTIE_H_
#define AKTIE_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Aktie {

	private:
	vector<int> buy;
	vector<double> preis;
	const string name;

	public:
	Aktie(string);
	//Anfragen
	string getName();
	double getValue();
	int getAnzahlAktien();

	//Aufträge
	void setValue(double);
	void buyAt(int, double);
	void sellAt(int, double);

	~Aktie();

};



#endif /* AKTIE_H_ */
