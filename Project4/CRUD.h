#pragma once
#ifndef CRUD_H
#define CRUD_H
#include <fstream>
#include <string>
#include "Registro.h"
using namespace std;

template <class T, class S>
class CRUD : public fstream
{
public:
	CRUD();
	~CRUD();
	void Guardar(T& reg);
	bool Recupera(long n, T& reg);
	void Borrar(long n);
	void Actualiza(long n);
	void Listar();
	long buscar();
	long buscar(S i);
};
#endif
