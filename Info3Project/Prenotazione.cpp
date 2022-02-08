#include "Prenotazione.h"

Prenotazione::Prenotazione(int idClientIn, int idCarIn, int ggIn, int mmIn,
		int yyIn, int nrGiorniIn, double costoIn) {
	clientId= idClientIn;
	carId= idCarIn;
	day=ggIn;
	month=mmIn;
	year=yyIn;
	nrOfDays=nrGiorniIn;
	cost=costoIn;
}

int Prenotazione::getClient() {
	return clientId;
}

int Prenotazione::getCar() {
	return carId;
}

int Prenotazione::getDay() {
	return day;
}

int Prenotazione::getMonth() {
	return month;
}

int Prenotazione::getYear() {
	return year;
}

double Prenotazione::getCost() {
	return cost;
}

int Prenotazione::getNrOfDays() {
	return nrOfDays;
}

void Prenotazione::printInfo(){
	cout<<"Prenotazione del cliente "<<clientId<<" :"<<endl;
	cout<<"Macchina prenotata: "<< carId<<endl;
	cout<<"Data inizio : "<<day<<"/"<<month<<"/"<<year<<endl;
	cout<<"Numero di giorni: "<< nrOfDays<<endl;
	cout<<"Costo: "<< cost<<endl;
}

Prenotazione::~Prenotazione() {
}
