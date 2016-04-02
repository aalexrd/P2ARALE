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
	void Guardar(Registro& reg);//crear
	bool Recupera(long n, Registro& reg);//lee
	void Borrar(long n);//elimina
	void Actualiza(long n);
	void Listar();
	long buscar();
private:
	void Empaquetar();
};
#endif

