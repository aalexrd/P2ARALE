#include "Interfaz.h"

Interfaz::Interfaz(): numero(0)
{
}

void Interfaz::interfaz()
{
	system("Color F6");
	system("cls");
	cout << "Men\243" << endl;
	cout << "\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337" << endl;
	cout << "1  \315  Crear registro" << endl;
	cout << "2  \315  Leer registro" << endl;
	cout << "3  \315  Eliminar registro" << endl;
	cout << "4  \315  Actualizar registro\n"
		<< "5  \315  Listar registro\n";
	cout << "0  \315  Salir" << endl;
	getline(cin, opcion);
	switch (opcion[0] - '0')
	{
	case 0: //salir
		exit(0);
	case 1: // Añadir registro
		reg.Leer();
		datos.Guardar(reg);
		interfaz();
	case 2: // Mostrar registro
		system("cls");
		cout << "Mostrar registro ";
		numero = datos.buscar();
		if (numero != -1)
		{
			if (datos.Recupera(numero, reg))
				reg.Mostrar();
		}
		else
		{
			cout << "\nNo se encontr\242 nada en el registro\n";
			system("pause");
		}
		system("pause");
		interfaz();
	case 3: // Eliminar registro
		system("cls");
		cout << "Eliminar registro ";
		numero = datos.buscar();
		if (numero != -1)
			datos.Borrar(numero);
		else
		{
			cout << "\nNo se encontr\242 nada en el registro\n";
			system("pause");
		}
		interfaz();
	case 4: // Actualizar registro
		system("cls");
		cout << "Actualizar\nSi solo quiere cambiar el nombre primero borre el estudiante de la lista.\n";
		numero = datos.buscar();
		if (numero != -1)
			datos.Actualiza(numero);
		else
		{
			cout << "\nNo se encontr\242 nada en el registro\n";
			system("pause");
		}
		interfaz();
	case 5: //Listar registro
		system("cls");
		cout << "Listado ";
		datos.Listar();
		interfaz();
	default:
		cout << "Esa no es una opci\242n\n";
		system("pause");
		interfaz();
	}
}
