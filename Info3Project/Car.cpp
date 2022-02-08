#include "Car.h"
using namespace std;

unsigned int Car::carNumber = 0;

Car::Car() {
	targa = "XXXXXXX";

	potenza = 0;
	peso = 0;

	Car::increaseNumber();
	carId = Car::carNumber;
}

Car::Car(string& targaIn, int pesoIn, int potenzaIn){

	targa = "XXXXXXX";
	if(targaIn.length() == 7){
		targa = targaIn;
	}
	peso=pesoIn;
	potenza=potenzaIn;

	Car::increaseNumber();
	carId = Car::carNumber;
}


string Car::getTarga(){
	return targa;
}

int Car::getPotenza(){
	return potenza;
}

int Car::getPeso(){
	return peso;
}

int Car::getId(){
	return carId;
}

void Car::setTarga(string& targaIn){
	if(targaIn.length() == 7){
		targa = targaIn;
	}
}

void Car::setPotenza(int potenzaIn){
	potenza = potenzaIn;
}

void Car::setPeso(int pesoIn){
	peso = pesoIn;
}

void Car::printInfo(){
	cout << "Informazioni sul veicolo Nr. "<< carId << endl;
	cout << "Targa: " << getTarga() << endl;
	cout << "Potenza: " << getPotenza() << " kW" << endl;
	cout << "Peso: " << getPeso() << " kg" << endl;
}


 void Car::increaseNumber(){
	 Car::carNumber++;
 }

 Car::~Car() {
 }
