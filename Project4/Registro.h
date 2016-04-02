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
	void Mostrar();
	const bool Valido();
	const char* Nombre();
	const string Cedula();
private:
	char valido; // Campo que indica si el registro es válido 
	// S->Válido, N->Inválido
	char nombre[34];
	char cedula[20];
};
#endif

