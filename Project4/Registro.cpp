#include "Registro.h"

Registro::Registro(char* n, char* c) : valido('S')
{
	if (n) strcpy_s(nombre, n); else strcpy_s(nombre, "");
	if (c) strcpy_s(cedula, c); else strcpy_s(cedula, "");
}

Registro::Registro(): valido('S')
{
	strcpy_s(nombre, "");
	strcpy_s(cedula, "");
}

const bool Registro::Valido()
{
	return valido == 'S';
}

const char* Registro::Nombre()
{
	return nombre;
}

const string Registro::Cedula()
{
	return cedula;
}

void Registro::Leer()
{
	system("cls");
	cout << "Leer registro:" << endl << endl;
	valido = 'S';
	cout << "Nombre: ";
	cin.getline(nombre, 34);
	cout << "C\202dula: ";
	cin.getline(cedula, 20);
}

// Muestra un registro en pantalla, si no est� marcado como borrado
void Registro::Mostrar()
{
	if (Valido())
	{
		cout << "\n==========\n"
			<< "Nombre: " << nombre
			<< "\nC\202dula: " << cedula
			<< "\n==========\n";
	}
}
