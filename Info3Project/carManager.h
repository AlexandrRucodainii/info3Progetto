#ifndef CARMANAGER_H_
#define CARMANAGER_H_

//Classe Singleton che realizza la "gestione" di tutte le macchine e prenotazioni

#include "Car.h"
#include "Prenotazione.h"
#include <vector>
#include <memory>

class carManager{
public:

	//Metodo statico che restitusce l'unica istanza di questa classe
	//Inizializza l'istanza se non esiste ancora
	static carManager& getInstance(){
		static carManager gInstance;
		return gInstance;
	}

	//Metodo per creare una macchina e aggiungerla nel vettore di macchine inseriti nel sistema
	void addCar();

	//Verifica se macchina è di tipo elettrico o ibrido. In tal caso al calcolo di costo si applica un
	//ulteriore sconto di 10%
	bool checkSconto(unique_ptr<Car>& c);

	//Stampa le informazioni sulla macchinapassata come parametro
	void printCarInfo(Car &c) const;

	//Stampa le informazioni di tutte le macchine presenti attualmente nel sistema
	void printAllCars();

	//Scrive su un file la targa e il tipo di tutte le macchine preseti nel sistema
	void printToFile();

	//Funzione template per calcolare il costo di prenotazione in base al numero di giorni
	//e lo sconto applicato
	template<class T>
	inline double calcoloCosto(int numeroGiorni, T sconto,unique_ptr<Car>& c) {
		if(checkSconto(c)){
			sconto+=10;
		}
		double costo= (numeroGiorni*40)-(numeroGiorni*40)*(sconto/100);
		cout<<"Costo: "<< costo<<endl;
		return costo;
	}

	//Funzione che calcola il numero di giorni trascorso da una certa data, in questo caso dal 01/01/0001
	//Utilizzata per calcolare il numero di giorni di una prenotazione
	int rdn(int y, int m, int d);

	//Creazione e aggiunta nel vettore di una prenotazione
	void addPrenotazione();

	//Stampa di tutte le prenotazioni presenti nel sistema
	void printAllPrenotazioni();

	//Cancellazione del copy constructor e l operatore "=" per garantire che non verrano create istanze
	//di questa classe in modo anomalo
	carManager(carManager const&) = delete;
	void operator=(carManager const&)  = delete;

private:
	//costruttore privato per realizzare una classe singleton
	carManager();


	//vettori STL di macchine e prenotazioni
	vector<unique_ptr<Car>> cars;
	vector<unique_ptr<Prenotazione>> prenotazioni;
};



#endif /* CARMANAGER_H_ */
