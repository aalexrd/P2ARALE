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
	char* getNombre();
	string getCedula() const;
private:
	char nombre[34];
	char cedula[20];
};
#endif
