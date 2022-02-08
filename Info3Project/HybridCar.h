#ifndef HYBRIDCAR_H_
#define HYBRIDCAR_H_

//Classe derivata da ElectricCar e ClassicCar, rappresenta una macchina ibrida

#include <iostream>
#include "ClassicCar.h"
#include "ElectricCar.h"

class HybridCar: public ClassicCar, public ElectricCar {
public:
	//Costruttore che chiamera i 3 costruttori delle classi derivanti per inizializzare tutti i campi
	//(anche essi ereditati)
	HybridCar(string& targaIn, int pesoIn, int potenzaIn, int fuelCapIn, int batCapIn, string& fuelTypeIn);

	//Implementazioni specifiche ad HybridCar dei metodi dichiarati nelle classi derivanti
	virtual void printInfo();
	virtual string getCarType();

	//Distruttore dichiarato virtual per una eventuale derivazione della classe HybridCar
	virtual ~HybridCar();

private:

};


#endif /* HYBRIDCAR_H_ */
