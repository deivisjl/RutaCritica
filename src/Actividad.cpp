#include "Actividad.h"
#include <iostream>
#include <windows.h>

Actividad Grafo[100000];

void Actividad::ingresar_numero_actividades(int tam)
{
    if (tam < 2) {
		cout << " La cantidad de actividades debe ser >= 2" << endl << endl;
		return;
	}

	for (int i = 0; i < tam; i++)
	{
		Actividad val;
		Actividad buscar[100];
		int duracion, f = 0, z = 0;
		int numero_de_predecesores;
		int band = 0;
		string id;
		cout << "Ingrese NOMBRE de la actividad "<<i+1 <<":";
		cin >> id;
		val.nombre_de_actividad = id;
		cout << "Ingrese la duracion de la actividad : ";
		cin >> duracion;
		val.tiempo_duracion = duracion;
		cout << "Ingrese el numero de predecesores : ";
		cin >> numero_de_predecesores;
		val.numero_de_predecesores = numero_de_predecesores;
		if (numero_de_predecesores != 0) {
			for (int j = 0; j < numero_de_predecesores; j++)
			{
				string buscar_ID;
				band = 0;
				cout << "Nombre del predecesor " << j + 1 << " : ";
				cin >> buscar_ID;
				Grafo[i].dependencia[j] = buscar_ID;

				for (int l = 0; l < tam; l++)
				{
					if (Grafo[l].nombre_de_actividad == buscar_ID)
					{
					    band = 1;
						buscar[f].nombre_de_actividad= Grafo[l].nombre_de_actividad;
						buscar[f].tiempo_duracion = Grafo[l].tiempo_duracion;
						buscar[f].numero_de_predecesores = Grafo[l].numero_de_predecesores;
						buscar[f].Est = Grafo[l].Est;
						buscar[f].Efi = Grafo[l].Efi;
						f++;
					}
				}

				if(band == 0)
                {
                    cout<<"El nodo no existe..!"<<endl;
                }
			}
			//search for the biggist Els on the arr
			int duracion_maxima = buscar[0].Efi, index1;
			for (int l = 0; l < f; l++)
			{
				if (duracion_maxima <= buscar[l].Efi)
				{
					duracion_maxima = buscar[l].Efi;
					index1 = l;
				}
			}
			Grafo[i].nombre_de_actividad = val.nombre_de_actividad;
			Grafo[i].tiempo_duracion = val.tiempo_duracion;
			Grafo[i].numero_de_predecesores = val.numero_de_predecesores;
			Grafo[i].Est = buscar[index1].Efi+1;
			Grafo[i].Efi = Grafo[i].tiempo_duracion + Grafo[i].Est-1;
			f = 0;
		}
		else
		{
			Grafo[i].nombre_de_actividad = val.nombre_de_actividad;
			Grafo[i].tiempo_duracion = val.tiempo_duracion;
			Grafo[i].numero_de_predecesores = val.numero_de_predecesores;
			Grafo[i].Est = 1;
			Grafo[i].Efi = Grafo[i].tiempo_duracion + Grafo[i].Est-1;
		}
		cout<<"============================================="<<endl;
	}
};

void Actividad::calcular_ruta(int tam)
{
    Grafo[tam - 1].Lst = Grafo[tam - 1].Efi;
	Grafo[tam - 1].Lfi = Grafo[tam - 1].Lst - Grafo[tam - 1].tiempo_duracion+1;
	for (int i = tam - 2; i >= 0; i--)
	{
		bool check = true;
		for (int j = i; j < tam; j++)
		{
			for (int w = 0; w < Grafo[j].numero_de_predecesores; w++)
			{
				if (Grafo[i].nombre_de_actividad == Grafo[j].dependencia[w])
				{
					check = false;
					break;
				}
			}
		}
		if (check == true)
		{
			Grafo[i].Lst = Grafo[i].Efi;
			Grafo[i].Lfi = Grafo[i].Lst - Grafo[i].tiempo_duracion;
		}
		else
		{
			Actividad encontrar1[100];
			int f = 0;
			for (int j = i; j < tam; j++)
			{
				for (int w = 0; w < Grafo[j].numero_de_predecesores; w++)
				{
					if (Grafo[i].nombre_de_actividad == Grafo[j].dependencia[w])
					{
						encontrar1[f].nombre_de_actividad = Grafo[j].nombre_de_actividad;
						encontrar1[f].tiempo_duracion = Grafo[j].tiempo_duracion;
						encontrar1[f].numero_de_predecesores = Grafo[j].numero_de_predecesores;
						encontrar1[f].Est = Grafo[j].Est;
						encontrar1[f].Efi = Grafo[j].Efi;
						encontrar1[f].Lfi = Grafo[j].Lfi;
						encontrar1[f].Lst = Grafo[j].Lst;
						f++;
					}
				}
			}
			int duracion_minima = encontrar1[0].Lfi, index2;
			for (int l = 0; l < f; l++)
			{
				if (duracion_minima >= encontrar1[l].Lfi)
				{
					duracion_minima = encontrar1[l].Lfi;
					index2 = l;
				}
			}
			Grafo[i].Lst = duracion_minima-1;
			Grafo[i].Lfi = Grafo[i].Lst -  Grafo[i].tiempo_duracion+1;
			f = 0;
		}
	}
};

void Actividad::mostrar(int tam)
{
    for (int i = 0; i < tam; i++) {
		cout << "Nombre de la actividad : " << Grafo[i].nombre_de_actividad << endl;
		cout << "tiempo de duracion : " << Grafo[i].tiempo_duracion << endl;
		cout << "Est : " << Grafo[i].Est << endl;
		cout << "Efi : " << Grafo[i].Efi << endl;
		cout << "Lst : " << Grafo[i].Lst << endl;
		cout << "Lfi : " << Grafo[i].Lfi << endl;
		for (int j = 0; j < Grafo[i].numero_de_predecesores; j++)
		{
			cout << "Numero de dependencias "<<j+1<<" : " << Grafo[i].dependencia[j] << endl;
		}
	}
};

void Actividad::finalizar(int tam)
{
    string respuesta ="";
    int tiempoTotal = 0;

	for (int i = 0; i < tam; i++)
	{
		if (Grafo[i].Lst - Grafo[i].Efi == 0 && Grafo[i].Lfi - Grafo[i].Est == 0)
		{
		    respuesta += " -> ";
			respuesta += Grafo[i].nombre_de_actividad;
			tiempoTotal = tiempoTotal + Grafo[i].tiempo_duracion;
		}
	}
	cout << "La ruta critica es : ";
	cout << respuesta << endl;
	cout << "Duracion total del proyecto: "<<tiempoTotal<<endl;
}
