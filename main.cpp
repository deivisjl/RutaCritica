#include <iostream>
#include "Actividad.h"

using namespace std;

int main()
{
    Actividad Grafo;

    int tam;
	cout << "Ingrese el numero de actividades: ";
	cin >> tam;
	cout<<"-----------------------------------------"<<endl;
	Grafo.ingresar_numero_actividades(tam);
	Grafo.calcular_ruta(tam);
	//Grafo.mostrar(tam);
	Grafo.finalizar(tam);
	system("pause");
	return 0;
}
