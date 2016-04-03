#pragma once
#ifndef REG_H
#define REG_H
#include <iostream>
using namespace std;

class Registro
{
public:
	Registro(char* n, char* c);
	Registro();
	void Leer();
	void Mostrar() const;
	bool getValido() const;
	char* getNombre();
	string getCedula() const;
private:
	char valido; // Campo que indica si el registro es válido S->No se debe borrar, N->Se debe borrar
	char nombre[34];
	char cedula[20];
};
#endif

