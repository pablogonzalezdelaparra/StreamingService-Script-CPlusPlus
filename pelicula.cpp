#include "video.h"
#include "pelicula.h"

#include <iostream>
using namespace std;

Pelicula::Pelicula(string ID, string Nombre, string Duracion, 
                    string Calificacion, string Fecha, string Genero)
                    :Video(ID, Nombre, Duracion, Calificacion, Fecha){
    _genero = Genero;
}

void Pelicula:: ImprimirInfo(){
        cout << "--------PELICULA--------" << endl;
        cout << "ID: " << _id << endl;
        cout << "Nombre: "<< _nombre << endl;
        cout << "Duracion: "<< _duracion << endl;
        cout << "Genero: "<< _genero << endl;
        cout << "Calificacion: "<< _calificacion << endl;
        cout << "Fecha: "<< _fecha << endl;
        cout << endl;
    }

bool Pelicula::operator==(string &p)
{
    if (_genero == p){
        return true;
    }
    else {
        return false;
    }
}

string Pelicula:: getnombre(){
     return _nombre;
}

string Pelicula:: getcalificacion(){
     return _calificacion;
}