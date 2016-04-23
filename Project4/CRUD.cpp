#include "CRUD.h"

template <class T, class S>
CRUD<T, S>::CRUD() : fstream("file.bin", in | out | binary) //abre el archivo file.bin
{
	if (!good()) //si no lo pudo abrir lo crea
	{
		open("file.bin", in | out | trunc | binary);
	}
}

template <class T, class S>
CRUD<T, S>::~CRUD()
{
}

template <class T, class S>
void CRUD<T, S>::Guardar(T& reg)// Insertar un nuevo registro al final:
{
	if (buscar(reg.getCedula()) == -1)
	{
		clear();
		seekg(0, end);
		write(reinterpret_cast<char *>(&reg), sizeof(Registro));
	}
	else
	{
		cout << "\nEl estudiante ya esta en la lista.\n";
		system("pause");
	}
}

template <class T, class S>
bool CRUD<T, S>::Recupera(long n, T& reg)//Lee del archivo y pasa por parametro lo leido, el bool devuelve si hubo algo que leer
{
	clear();
	seekg(n * sizeof(Registro), beg);
	read(reinterpret_cast<char *>(&reg), sizeof(Registro));
	return gcount() > 0;
}

template <class T, class S>
void CRUD<T, S>::Borrar(long n)// Elimina el registro deseado
{
	ofstream ftemp("file.tmp", out);
	Registro reg;
	long temp = 0;
	clear();
	seekg(0, beg);
	do
	{
		read(reinterpret_cast<char *>(&reg), sizeof(Registro));
		if (gcount() > 0 && temp != n)
			ftemp.write(reinterpret_cast<char *>(&reg), sizeof(Registro));
		temp++;
	}
	while (gcount() > 0);
	ftemp.close();
	close();
	remove("file.bak");
	rename("file.bin", "file.bak");
	rename("file.tmp", "file.bin");
	open("file.bin", in | out | binary);
}

template <class T, class S>
void CRUD<T, S>::Actualiza(long n)//Actualiza un registro del archivo:
{
	Registro reg;
	reg.Leer();
	if (buscar(reg.getCedula()) == -1)
	{
		clear();
		seekg(n * sizeof(Registro), beg);
		write(reinterpret_cast<char *>(&reg), sizeof(Registro));
	}
	else
	{
		cout << "\nEl estudiante ya esta en la lista.\n";
		system("pause");
	}
}

template <class T, class S>
void CRUD<T, S>::Listar()//Lista todos los contenidos del archivo:
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
	cout << endl;
	system("pause");
}

template <class T, class S>
long CRUD<T, S>::buscar()//Encontrar en que posicion esta el registro prguntando el termino de busqueda
{
	cout << "\nDigite la c\202dula a buscar: ";
	string i;
	std::getline(cin, i);
	return buscar(i);
}

template <class T, class S>
long CRUD<T, S>::buscar(S i)//Encontrar la posicion cuando envian de una vez lo que debo buscar
{
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
	return -1;
}

template class CRUD<Registro, string>; //forzar compilacion de estas plantillas
