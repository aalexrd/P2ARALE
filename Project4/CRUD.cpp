#include "CRUD.h"

CRUD::CRUD() : fstream("file.bin", in | out | binary)
{
	if (!good())
	{
		open("file.bin", in | out | trunc | binary);
	}
}

CRUD::~CRUD()
{
	Empaquetar();
}

// Insertar un nuevo registro al final:
void CRUD::Guardar(Registro& reg)
{
	clear();
	seekg(0, end);
	write(reinterpret_cast<char *>(&reg), sizeof(Registro));
}

//Lee del archivo y pasa por parametro lo leido, el bool devuelve si hubo algo que leer
bool CRUD::Recupera(long n, Registro& reg)
{
	clear();
	seekg(n * sizeof(Registro), beg);
	read(reinterpret_cast<char *>(&reg), sizeof(Registro));
	return gcount() > 0;
}

// Marca el registro como borrado:
void CRUD::Borrar(long n)
{
	char marca;
	clear();
	marca = 'N';
	seekg(n * sizeof(Registro), beg);
	write(&marca, 1);
}

//Actualiza un registro del archivo:
void CRUD::Actualiza(long n)
{
	clear();
	seekg(n * sizeof(Registro), beg);
	Registro reg;
	reg.Leer();
	write(reinterpret_cast<char *>(&reg), sizeof(Registro));
}

//Lista todos los contenidos del archivo:
void CRUD::Listar()
{
	clear();
	Registro reg;
	long n = 0;
	seekg(0, beg);
	while (Recupera(n, reg))
	{
		reg.Mostrar();
		n++;
	}
	cout << "Presione una tecla para continuar...";
	cin.get();
}

// Elimina los registros marcados como borrados:
void CRUD::Empaquetar()
{
	ofstream ftemp("file.tmp", out);
	Registro reg;

	clear();
	seekg(0, beg);
	do
	{
		read(reinterpret_cast<char *>(&reg), sizeof(Registro));
		if (gcount() > 0 && reg.getValido())
			ftemp.write(reinterpret_cast<char *>(&reg), sizeof(Registro));
	}
	while (gcount() > 0);
	ftemp.close();
	close();
	remove("file.bak");
	rename("file.bin", "file.bak");
	rename("file.tmp", "file.bin");
	open("file.bin", in | out | binary);
}

//Encontrar en que posicion esta el registro:
long CRUD::buscar()
{
	cout << "\nDigite la c\202dula a buscar: ";
	string i;
	std::getline(cin, i);
	long n = 0;
	Registro reg; //para guardar temporalmente lo leido del archivo
	while (Recupera(n, reg))//mientras pueda leer algo del archivo
	{
		if (reg.getCedula() == i)
		{
			return n;
		}
		n++;
	}
	cout << "\nNo se encontr\242 nada en el registro\n";
	cin.get();
	return -1;
}

