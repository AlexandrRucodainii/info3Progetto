#ifndef ELECTRICCAR_H_
#define ELECTRICCAR_H_

//Classe derivata da Car, rappresenta una macchina elettrica

#include <iostream>
#include "Car.h"

//Viene derivata come virtual public, in modo da risolvere il problema del diamante per la classe HybridCar
class ElectricCar: virtual public Car{
public:
	//Il costruttore quasi identico al costruttore di Car, il quale verra chiamato per assegnare i primi
	//tre parametri. In seguito assegnera anche il parametro caratteristico alla macchina elettrica
	ElectricCar(string& targaIn, int pesoIn, int potenzaIn, int batteryCapIn);

	//Getter and setter
	int getBatteryCap();
	void setBatteryCap(int BatteryCapIn);

	//Implementazioni specifiche ad ElectricCar dei metodi dichiarati nella classe derivante
	virtual string getCarType();
	virtual void printInfo();

	//Distruttore dichiarato virtual essendo anche questa a sua volta una classe derivante
	virtual ~ElectricCar();

private:
	int batteryCap;
};



#endif /* ELECTRICCAR_H_ */
