#include <iostream>

#include "carManager.h"
#include <fstream>
#include "ClassicCar.h"
#include "HybridCar.h"
#include "ElectricCar.h"
using namespace std;


carManager::carManager() {
}

void carManager::addCar(){

	int peso;
	cout << "Inserire il peso della macchina: ";
	cin >> peso;

	int potenza;
	cout << "Inserire la pootenza della macchina: ";
	cin >> potenza;

	string targa;
	cout << "Inserire numero di targa: ";
	cin >> targa;

	char carType;
	cout << "Inserire il tipo di auto: ";
	cin >> carType;

	switch(carType){
		case 'e':{
			int batteryCap;
			cout << "Inserire la capacita della batteria: ";
			cin >> batteryCap;

			unique_ptr<Car> electricCar(new ElectricCar(targa, peso, potenza, batteryCap));
			cars.push_back(move(electricCar));
			cout << "Auto elettrica aggiunta nella lista"<< endl;
			break;
		}
		case 'c':{
			int fuelCapacity;
			cout << "Inserire la capacita dell serbatoio: ";
			cin >> fuelCapacity;

			string fuelType;
			cout << "Inserire il tipo di carburante: ";
			cin >> fuelType;

			unique_ptr<Car> classicCar(new ClassicCar(targa,peso, potenza, fuelCapacity,fuelType));
			cars.push_back(move(classicCar));
			cout << "Auto a carburante fossile ("<< fuelType <<") aggiunta nella lista"<< endl;
			break;
		}
		case 'h':{
			int batteryCap;
			cout << "Inserire la capacita della batteria: ";
			cin >> batteryCap;

			int fuelCapacity;
			cout << "Inserire la capacita dell serbatoio: ";
			cin >> fuelCapacity;

			string fuelType;
			cout << "Inserire il tipo di carburante: ";
			cin >> fuelType;

			unique_ptr<Car> hybridCar(new HybridCar(targa,peso, potenza, fuelCapacity,batteryCap,fuelType));
			cars.push_back(move(hybridCar));
			cout << "Auto ibrida aggiunta nella lista"<< endl;
			break;
		}
		default:{
			cout << "Tipo di macchina non riconosciuto"<< endl;
		}
	}
}

bool carManager::checkSconto(unique_ptr<Car>& c) {
	if(c->getCarType()== "Electric" || c->getCarType() == "Hybrid")
		return true;
	else
		return false;
}

void carManager::printCarInfo(Car &c) const {
	c.printInfo();
}

void carManager::printAllCars() {
	cout << "Info sulle macchine in sistema:" << endl;
	for(auto const &carPntr: cars){
		carPntr.get()->printInfo();
	}
}

void carManager::printToFile() {
	ofstream CarInfoFile;
	CarInfoFile.open("carInfo.txt", ios_base::trunc);
	for(auto const &carPntr: cars){
		CarInfoFile << carPntr.get()->getId() <<" "<< carPntr.get()->getTarga()<< " : "<< carPntr.get()->getCarType() << endl;
	}

}

int carManager::rdn(int y, int m, int d) {
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

void carManager::addPrenotazione() {
	int clientId;
	cout << "Inserire l'ID del cliente: ";
	cin >> clientId;

	int carId;
	cout << "Inserire l'ID del veicolo: ";
	cin >> carId;

	int giornoIn;
	cout << "Inserire giorno inizio: ";
	cin >> giornoIn;

	int giornoOut;
	cout << "Inserire giorno fine: ";
	cin >> giornoOut;

	int meseIn;
	cout << "Inserire mese inizio: ";
	cin >> meseIn;

	int meseOut;
	cout << "Inserire mese fine: ";
	cin >> meseOut;

	int annoIn;
	cout << "Inserire anno inizio: ";
	cin >> annoIn;

	int annoOut;
	cout << "Inserire anno fine: ";
	cin >> annoOut;

	int nrDiGiorni = carManager::rdn(annoOut, meseOut, giornoOut) - carManager::rdn(annoIn, meseIn, giornoIn);

	int scontoM;
	cout << "Inserire la percentuale di sconto: ";
	cin >> scontoM;


	double costo=0;
	for(auto &carPntr: cars){
		if(carPntr.get()->getId() == carId){
			costo = carManager::calcoloCosto<double>(nrDiGiorni, scontoM, carPntr);
			break;
		}
	}
	unique_ptr<Prenotazione> p(new Prenotazione(clientId, carId, giornoIn, meseIn, annoIn, nrDiGiorni, costo));
	prenotazioni.push_back(move(p));

}

void carManager::printAllPrenotazioni() {
	cout << "Preotazioni attive:" << endl;
	for(auto const &prenotazionePntr: prenotazioni){
		prenotazionePntr.get()->printInfo();
	}
}
