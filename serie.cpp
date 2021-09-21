#include "serie.h"

#include <iostream>
using namespace std;

Serie::Serie(string ID, string Nombre, string Genero){
        _genero = Genero;
        _nombre = Nombre;
        _id = ID;
    }

void Serie:: ImprimirInfo(){
        cout << "--------SERIE--------" << endl;
        cout << "ID: " << _id << endl;
        cout << "Nombre: "<< _nombre << endl;
        cout << "Genero: "<< _genero << endl; 
        cout << endl;
    }

void Serie:: meterepisodio(Episodio epi){
    vecepisodios.push_back(epi);
}

bool Serie::operator==(string &s)
{
    if (_genero == s){
        return true;
    }
    else {
        return false;
    }
}

string Serie:: getnombre(){
    return _nombre;
}
