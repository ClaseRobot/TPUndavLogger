//============================================================================
// Name        : TPLoggerUndav.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Email.h"

using std::cout;
using std::endl;
using namespace EmailUndav;

int main() {
	cout << "das11das" << endl; // prints
	cout << "nueva linea de test"<<endl;
	cout << "pepe"<<endl;
	return 0;
}

void PruebasUnitariasEmail(){
	Email* correo = CrearMail("Parcial", "El Sábado 4 de Mayo es el parcial. Estudiar todos los temas vistos hasta el 25 de Abril.");
	CambiarAsunto(correo, "Evaluación de Avance");
	AgregarDestinatario(correo, "gabytubio@gmail.com");
	AgregarDestinatario(correo, "jjlopez@gmail.com");
	MostrarEmail(correo);
	DestruirEmail(correo);
}
