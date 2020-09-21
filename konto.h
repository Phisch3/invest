/*
 * konto.h
 *
 *  Created on: 12.08.2020
 *      Author: phili
 */

#ifndef KONTO_H_
#define KONTO_H_
#include "aktie.h"

using namespace std;

class Konto {

	private:
	vector<Aktie> aktienListe;


	public:

	void addAktie(Aktie);
	Aktie* getAktie(int);
	Aktie* getAktie(string);
	void aktieLoeschen(); // nicht erstellt
	void ausgabeAllAktien();
	int getLength();




};



#endif /* KONTO_H_ */
