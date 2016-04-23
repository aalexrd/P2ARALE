#include "Registro.h"

Registro::Registro(char* n, char* c)
{
	strcpy_s(nombre, n);
	strcpy_s(cedula, c);
}

Registro::Registro()
{
	strcpy_s(nombre, "");
	strcpy_s(cedula, "");
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
	cout << "\nNombre: ";
	cin.getline(nombre, 34);
	cout << "C\202dula: ";
	cin.getline(cedula, 20);
}

// Muestra un registro en pantalla, si no está marcado como borrado
void Registro::Mostrar() const
{
	cout << "\n==========\n"
		<< "Nombre: " << nombre
		<< "\nC\202dula: " << cedula
		<< "\n==========\n";
}
