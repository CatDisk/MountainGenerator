#include <iostream>
#include <conio.h>
#include <stdlib.h>


using namespace System;
using namespace std;
//Almacenar "n" valores enteros

void Imprimir_Arreglo(int *arreglo, int*cantidad)
{
	for (int i = 0; i < *cantidad; i++)
		cout << "Arreglo[" << i << "]=" << arreglo[i] << endl;
}

int* Aumentar_Capacidad_Arreglo(int *arreglo, int*capacidad)
{
	int *arrauxiliar = new int[*capacidad + 1];
	for (int i = 0; i < *capacidad; i++)
		arrauxiliar[i] = arreglo[i];
	return arrauxiliar;
}

int* Eliminar_Ultima_Pos(int *arreglo, int *capacidad)
{
	int *araux = new int[*capacidad - 1];
	for (int i = 0; i < *capacidad - 1; i++)
		araux[i] = arreglo[i];
	*capacidad = *capacidad - 1;
	return araux;
}
int* Eliminar_Pos(int *arreglo, int *capacidad, int *pos)
{
	int *araux = new int[*capacidad - 1];
	int j = 0;
	for (int i = 0; i < *capacidad; i++)
	{
		if (i != *pos)
		{
			araux[j] = arreglo[i];
			j++;
		}
	}
	*capacidad = *capacidad - 1;
	return araux;
}

int* Eliminar_Elem(int *arreglo, int *capacidad, int *elem)
{
	int contador = 0;
	int j = 0;
	for (int i = 0; i < *capacidad; i++)
	{
		contador += (arreglo[i] == *elem) ? 1 : 0;
	}
	int *araux = new int[*capacidad - contador];
	for (int i = 0; i < *capacidad; i++)
	{
		if (arreglo[i] != *elem)
		{
			araux[j] = arreglo[i];
			j++;
		}
	}
	*capacidad = *capacidad - contador;
	return araux;
}

int mayorElem(int *arreglo, int *capacidad)
{
	int mayor = arreglo[0];

	for (int i = 0; i < *capacidad; i++)
	{
		if (mayor < arreglo[i])
			mayor = arreglo[i];
	}
	return mayor;
}

int menorElem(int *arreglo, int *capacidad)
{
	int mayor = arreglo[0];

	for (int i = 0; i < *capacidad; i++)
	{
		if (mayor > arreglo[i])
			mayor = arreglo[i];
	}
	return mayor;
}

float average(int *arreglo, int *capacidad)
{
	float promedio = 0.0;

	for (int i = 0; i < *capacidad; i++)
	{
		promedio += arreglo[i];
	}
	promedio /= *capacidad;

	return promedio;
}

void sort(int *arreglo, int *cap)
{
	int buffer;
	int n;

	for (int i = 1; i < *cap; i++)
	{
		if (arreglo[i] < arreglo[i - 1])
		{
			buffer = arreglo[i];
			n = i;
			do
			{
				arreglo[n] = arreglo[n - 1];
				n--;
			} while (buffer < arreglo[n] && n != 0);
			arreglo[n] = buffer;
		}
	}
}

void menu(int *opt)
{
	Console::Clear();
	do
	{
		cout << "----------------------------------" << endl;
		cout << "1- Insertar nuevo elemanto" << endl;
		cout << "----------------------------------" << endl;
		cout << "2- Eliminar ultimo elemento" << endl;
		cout << "----------------------------------" << endl;
		cout << "3- Eliminar una ubicacion" << endl;
		cout << "----------------------------------" << endl;
		cout << "4- Eleminar un elemento" << endl;
		cout << "----------------------------------" << endl;
		cout << "5- Imprimir arreglo" << endl;
		cout << "----------------------------------" << endl;
		cout << "6- Encontrar el mayor" << endl;
		cout << "----------------------------------" << endl;
		cout << "7- Encontrar el menor" << endl;
		cout << "----------------------------------" << endl;
		cout << "8- Hallar el promedio" << endl;
		cout << "----------------------------------" << endl;
		cout << "9- Ordenar Arreglo" << endl;
		cout << "----------------------------------" << endl;
		cout << "10- Exit" << endl;
		cout << "----------------------------------" << endl;
		cout << "Ingrese su opcion: ";
		cin >> *opt;
	} while (*opt < 1 || *opt > 10);
}

int main()
{
	int *arreglo;	int *cantidad; 	char *opt; int *menu_opt;
	arreglo = new int[1]; // almacena minimo 1 valor
	cantidad = new int; 	opt = new char; *cantidad = 0; menu_opt = new int;
	int *pos; pos = new int; int *elem; elem = new int;
	do {
		menu(menu_opt);
		switch (*menu_opt)
		{
		case 1:
			do {
				cout << "Ingrese el numero a guardar : ";
				cin >> arreglo[*cantidad];
				*cantidad = *cantidad + 1;
				Imprimir_Arreglo(arreglo, cantidad);
				flushall();
				cout << "Desea registrar otro valor ? (S/N) :";
				cin >> *opt;
				*opt = toupper(*opt);
				if (*opt == 'S')
					arreglo = Aumentar_Capacidad_Arreglo(arreglo, cantidad);
			} while (*opt != 'N');
			break;
		case 2:
			arreglo = Eliminar_Ultima_Pos(arreglo, cantidad);
			break;
		case 3:
			cout << "Ingrese la ubicacion (0 - " << *cantidad - 1 << "): ";
			cin >> *pos;
			arreglo = Eliminar_Pos(arreglo, cantidad, pos);
			break;
		case 4:
			cout << "Ingrese el valor: ";
			cin >> *elem;
			arreglo = Eliminar_Elem(arreglo, cantidad, elem);
			break;
		case 5:
			Imprimir_Arreglo(arreglo, cantidad);
			_getch();
			break;
		case 6:
			cout << "El elemento mayor es: " << mayorElem(arreglo, cantidad);
			_getch();
			break;
		case 7:
			cout << "El elemento menor es: " << menorElem(arreglo, cantidad);
			_getch();
			break;
		case 8:
			cout << "El promedio es: " << average(arreglo, cantidad);
			_getch();
			break;
		case 9:
			sort(arreglo, cantidad);
			break;
		}
	} while (*menu_opt != 10);


	delete[] arreglo;
	delete cantidad;
	getch();
	return 0;
}