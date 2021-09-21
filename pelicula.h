#ifndef CLASEPELICULA_H_
#define CLASEPELICULA_H_
#include "video.h"

#include <iostream>
using namespace std;

class Pelicula : public Video
{
    private:
    string _genero;
    
    public:
    Pelicula(string ID, string Nombre, string Duracion, 
                string Calificacion, string Fecha, string Genero);
    bool operator ==(string &p);
    void ImprimirInfo();
    string getnombre();
    string getcalificacion();


};
#endif