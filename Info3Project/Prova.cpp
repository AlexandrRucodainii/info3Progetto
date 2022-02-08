#include <iostream>

#include "carManager.h"
#include "ClassicCar.h"
#include "HybridCar.h"
#include "ElectricCar.h"
using namespace std;


int main(){

	carManager &cm = carManager::getInstance();

	for(int i =0; i<3; i++){
		cm.addCar();
	}

	cm.addPrenotazione();

	cm.printAllCars();
	cm.printAllPrenotazioni();
	cm.printToFile();
return 0;
}
