#pragma once
#ifndef Intefraz_H
#define Interfaz_H
#include "CRUD.h"
#include <iostream>
using namespace std;

class Interfaz
{
private:
	Registro reg;
	CRUD<Registro, string> datos;
	long numero;
	string opcion;
public:
	Interfaz();
	void interfaz();
};
#endif
