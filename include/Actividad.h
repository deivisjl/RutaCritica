#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Actividad
{
    public:
        string nombre_de_actividad;
        int tiempo_duracion;
        int Est; //Earliest Start(Inicio mas temprano)
        int Efi; //Earliest Finish(Fin mas temprano)
        int Lst; //Latest Start (Inicio mas tarde)
        int Lfi; //Latest Finish (Fin mas tarde)
        int numero_de_predecesores;
        string dependencia[10];

        void ingresar_numero_actividades(int tam);
        void calcular_ruta(int tam);
        void finalizar(int tam);
        void mostrar(int tam);
};
#endif // ACTIVIDAD_H
