#include "ClassicCar.h"
using namespace std;

ClassicCar::ClassicCar(string& targaIn, int pesoIn, int potenzaIn, int fuelCapacityIn, string& fuelTypeIn):
		Car(targaIn, pesoIn, potenzaIn){
	fuelCapacity= fuelCapacityIn;
	fuelType = fuelTypeIn;
}

int ClassicCar::getFuelCap(){
	return fuelCapacity;
}

string ClassicCar::getFuelType(){
	return fuelType;
}

void ClassicCar::setFuelCap(int fuelCapIn){
	fuelCapacity = fuelCapIn;
}

void ClassicCar::setFuelType(string& fuelTypeIn){
	fuelType = fuelTypeIn;
}

string ClassicCar::getCarType(){
	return "Classic";
}

void ClassicCar::printInfo(){
	Car::printInfo();
	cout << "Capienza del serbatoio: " << getFuelCap() << endl;
	cout << "Tipo veicolo: " << getCarType() << endl;
	cout << "Tipo di carburante: " << getFuelType() << endl;
}

ClassicCar::~ClassicCar(){
}
