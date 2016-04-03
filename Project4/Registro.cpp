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

bool Registro::getValido() const
{
	return valido == 'S';
}

char* Registro::getNombre()
{
	return nombre;
}

string Registro::getCedula() const
{
	return cedula;
}

//Pide al usuario que llene los campos del registro
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

// Muestra un registro en pantalla, si no está marcado como borrado
void Registro::Mostrar() const
{
	if (getValido())
	{
		cout << "\n==========\n"
			<< "Nombre: " << nombre
			<< "\nC\202dula: " << cedula
			<< "\n==========\n";
	}
}

