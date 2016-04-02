#include "Interfaz.h"

Interfaz::Interfaz()
{
}

void Interfaz::interfaz()
{
	system("Color F6");
	Registro reg;
	CRUD datos;
	int opcion;
	long numero;

	do
	{
		opcion = Menu();
		switch (opcion)
		{
		case '1': // Añadir registro
			reg.Leer();
			datos.Guardar(reg);
			break;
		case '2': // Mostrar registro
			system("cls");
			cout << "Mostrar registro: ";
			numero = datos.buscar();
			if (numero != -1)
				if (datos.Recupera(numero, reg))
					reg.Mostrar();
			cin.get();
			break;
		case '3': // Eliminar registro
			system("cls");
			cout << "Eliminar registro: ";
			numero = datos.buscar();
			if (numero != -1)
				datos.Borrar(numero);
			break;
		case '4': // Actualizar registro
			system("cls");
			cout << "Actualizar:\n";
			numero = datos.buscar();
			if (numero != -1)
				datos.Actualiza(numero);
			break;
		case '5': //Listar registro
			system("cls");
			cout << "Listado: ";
			datos.Listar();
			break;
		}
	}
	while (opcion != '0');
}

int Interfaz::Menu()
{
	char resp[20];

	do
	{
		system("cls");
		cout << "Men\243" << endl;
		cout << "\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337\337"<< endl;
		cout << "1  \315  Insertar registro" << endl;
		cout << "2  \315  Mostrar registro" << endl;
		cout << "3  \315  Eliminar registro" << endl;
		cout << "4  \315  Actualizar registro\n"
			<< "5  \315  Listar registro\n";
		cout << "0  \315  Salir" << endl;
		cin.getline(resp, 20);
	}
	while (resp[0] < '0' && resp[0] > '5');
	return resp[0];
}

