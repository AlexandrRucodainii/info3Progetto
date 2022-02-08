#include "HybridCar.h"
using namespace std;



HybridCar::HybridCar(string& targaIn, int pesoIn, int potenzaIn, int fuelCapIn, int batCapIn, string& fuelTypeIn):
		Car(targaIn, pesoIn, potenzaIn),
		ClassicCar(targaIn, pesoIn, potenzaIn, fuelCapIn, fuelTypeIn),
		ElectricCar(targaIn, pesoIn, potenzaIn, batCapIn){
}

string HybridCar::getCarType(){
	return "Hybrid";
}

void HybridCar::printInfo(){
	Car::printInfo();
	cout << "Capienza del serbatoio: " << getFuelCap() << endl;
	cout << "Tipo di carburante: " << getFuelType() << endl;
	cout << "Capacita della batteria:" << getBatteryCap() << " kWh" << endl;
	cout << "Tipo veicolo: " << getCarType() << endl;
}

HybridCar::~HybridCar(){
}
