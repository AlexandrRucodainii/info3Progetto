#include "ElectricCar.h"
using namespace std;

ElectricCar::ElectricCar(string& targaIn, int pesoIn, int potenzaIn,int batteryCapIn):Car(targaIn, pesoIn, potenzaIn){
	batteryCap=batteryCapIn;
}

int ElectricCar::getBatteryCap(){
	return batteryCap;
}

void ElectricCar::setBatteryCap(int BatteryCapIn){
	batteryCap = BatteryCapIn;
}

string ElectricCar::getCarType(){
	return "Electric";
}

void ElectricCar::printInfo(){
	Car::printInfo();
	cout << "Capacita della batteria:" << getBatteryCap() << " kWh" << endl;
	cout << "Tipo veicolo: " << getCarType() << endl;

}

ElectricCar::~ElectricCar(){}
