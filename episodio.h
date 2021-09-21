#ifndef CLASEPISODIO_H_
#define CLASEPISODIO_H_
#include "video.h"

#include <iostream>
using namespace std;

class Episodio : public Video
{
    private:
    string _temporada;
    string _numepisodio;
    public:
    Episodio(string ID, string Nombre, string Duracion, string Calificacion, 
                string Fecha, string Temporada, string NumEpisodio);
    void ImprimirInfo();
    string getnombre();
    string getcalificacion();

};
#endif