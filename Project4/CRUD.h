#pragma once
#ifndef CRUD_H
#define CRUD_H
#include <fstream>
#include <string>
#include "Registro.h"
using namespace std;

class CRUD : public fstream
{
public:
	CRUD();
	~CRUD();
	void Guardar(Registro& reg);
	bool Recupera(long n, Registro& reg);
	void Borrar(long n);
	void Actualiza(long n);
	void Listar();
	long buscar();
	long buscar(string i);
private:
	void Empaquetar();
};
#endif
