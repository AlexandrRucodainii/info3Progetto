#ifndef CLASSICCAR_H_
#define CLASSICCAR_H_

//Classe derivata da Car, rappresenta una macchina a carburante fossile

#include <iostream>
#include <string>
#include "Car.h"

//Viene derivata come virtual public, in modo da risolvere il problema del diamante per la classe HybridCar
class ClassicCar: virtual public Car {
public:
	//Il costruttore quasi identico al costruttore di Car, il quale verra chiamato per assegnare i primi
	//tre parametri. In seguito assegnera anche i parametri caratteristici alla macchina a carburante fossile
	ClassicCar(string& targaIn, int pesoIn, int potenzaIn, int fuelCapacityIn, string& fuelTypeIn);

	//Getters and setters
	int getFuelCap();
	string getFuelType();
	void setFuelCap(int fuelCapIn);
	void setFuelType(string& fuelTypeIn);

	//Implementazioni specifiche ad ClassicCar dei metodi dichiarati nella classe derivante
	virtual void printInfo();
	virtual string getCarType();

	//Distruttore dichiarato virtual essendo anche questa a sua volta una classe derivante
	virtual ~ClassicCar();

private:
	int fuelCapacity;
	string fuelType;
};

#endif /* CLASSICCAR_H_ */
