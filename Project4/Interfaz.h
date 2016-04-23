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
	CRUD datos;
	long numero;
	string opcion;
public:
	Interfaz();
	void interfaz();
};
#endif
