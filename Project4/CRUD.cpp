#include "CRUD.h"

CRUD::CRUD() : fstream("file.bin", ios::in | ios::out | ios::binary)
{
	if (!good())
	{
		open("file.bin", ios::in | ios::out | ios::trunc | ios::binary);
		cout << "fichero creado" << endl;
		cin.get();
	}
}

CRUD::~CRUD()
{
	Empaquetar();
}

void CRUD::Guardar(Registro& reg)
{
	// Insertar al final:
	clear();
	seekg(0, ios::end);
	write(reinterpret_cast<char *>(&reg), sizeof(Registro));
	cout << reg.Nombre() << endl;
}

bool CRUD::Recupera(long n, Registro& reg)
{
	clear();
	seekg(n * sizeof(Registro), ios::beg);
	read(reinterpret_cast<char *>(&reg), sizeof(Registro));
	return gcount() > 0;
}

// Marca el registro como borrado:
void CRUD::Borrar(long n)
{
	char marca;

	clear();
	marca = 'N';
	seekg(n * sizeof(Registro), ios::beg);
	write(&marca, 1);
}

void CRUD::Actualiza(long n)
{
	clear();
	seekg(n * sizeof(Registro), ios::beg);
	Registro reg;
	reg.Leer();
	write(reinterpret_cast<char *>(&reg), sizeof(Registro));
}

void CRUD::Listar()
{
	clear();
	Registro reg;
	long n = 0;
	seekg(0, ios::beg);
	while (Recupera(n, reg))
	{
		reg.Mostrar();
		n++;
	}
	cin.get();
}

// Elimina los registros marcados como borrados
void CRUD::Empaquetar()
{
	ofstream ftemp("file.tmp", ios::out);
	Registro reg;

	clear();
	seekg(0, ios::beg);
	do
	{
		read(reinterpret_cast<char *>(&reg), sizeof(Registro));
		if (gcount() > 0 && reg.Valido())
			ftemp.write(reinterpret_cast<char *>(&reg), sizeof(Registro));
	}
	while (gcount() > 0);
	ftemp.close();
	close();
	remove("file.bak");
	rename("file.bin", "file.bak");
	rename("file.tmp", "file.bin");
	open("file.bin", ios::in | ios::out | ios::binary);
}


long CRUD::buscar()//encontrar en que posicion esta el registro
{
	cout << "\nDigite la c\202dula a buscar: ";
	string i;
	std::getline(cin, i);
	long n = 0;
	Registro reg; //para guardar temporalmente lo leido del archivo
	while (Recupera(n, reg))//mientras pueda leer algo del archivo
	{
		if (reg.Cedula() == i)
		{
			return n;
		}
		n++;
	}
	cout << "\nNo se encontro nada en el registro\n";
	cin.get();
	return -1;
}

