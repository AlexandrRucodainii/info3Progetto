#ifndef CAR_H_
#define CAR_H_

//Classe astratta da cui deriviamo le classi ClassicCar, ElectricCar e HybridCar

#include <string>
#include <iostream>
using namespace std;

class Car{

public:

	//Costruttore di default e uno che prende come parametri informazioni comuni a tutti i tipi di macchine
	Car();
	Car(string& targa, int peso, int potenza);

	//Metodi get e set per i vari campi privati della classe
	string getTarga();
	int getPotenza();
	int getPeso();
	int getId();
	void setPotenza(int potenzaIn);
	void setPeso(int pesoIn);
	void setTarga(string& targa);

	//Metodo che subira l'ovverriding dalle classe derivate, dichiarato virtual per garantire il coretto
	//polimorfismo in fase di runtime
	//Stampa le informazioni della macchina
	virtual void printInfo();

	//Metodo pure virtual che garantisce che questa classe sia astratta
	//Restituisce il tipo di macchina in forma di una stringa, verra implementato da clasi derivati
	virtual string getCarType() = 0;

	//Distruttore dichiarato virtual per la coretta cancellazione delle classi derivate
	virtual ~Car();

private:
	string targa;
	unsigned short peso;
	unsigned short potenza;
	unsigned int carId;

	//Campo di tipo static è comune a tutta la classe e non a un oggetto in particolare, si usa per assegnare
	//un id univoco ad ogni macchina creata
	static unsigned int carNumber;

protected:
	//Metodo statico utilizzato per incrementare il campo carNumber, dichiarato protected im nodo da poter
	//essere utilizzato dalle sottoclassi, ma non dal esterno.
	static void increaseNumber();
};

#endif /* CAR_H_ */
