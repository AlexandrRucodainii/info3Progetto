#ifndef PRENOTAZIONE_H_
#define PRENOTAZIONE_H_

#include <string>
#include <iostream>
using namespace std;

//classe che rappresenta una prenotazione di noleggio, prende in ingresso il giorno, mese e anno inizio,
//numero di giorni di noleggio ed il costo
class Prenotazione{
public:

	//costruttore che prende i parametri necessari
	Prenotazione(int idClientIn, int idCarIn, int ggIn, int mmIn, int yyIn, int nrGiorniIn, double costoIn);

	//Getters per i campi privati
	int getClient();
	int getCar();
	int getDay();
	int getMonth();
	int getYear();
	double getCost();
	int getNrOfDays();

	//metodo per stampare le informazioni su una prenotazione
	void printInfo();

	//distruttore non virtual visto che la classe non è una classe derivante
	~Prenotazione();


private:
	int clientId, carId, day, month, year, nrOfDays;
	double cost;
};

#endif /* PRENOTAZIONE_H_ */
