#ifndef CLASENETFLIX_H_
#define CLASENETFLIX_H_
#include "pelicula.h"
#include "serie.h"

#include <vector>
#include <iostream>
using namespace std;

class Netflix
{
    private:
    vector<Pelicula> vectorpeli;
    vector<Serie> vectorserie;
    string _nombre_archivo;
    
    string ID;
    string Nombre;
    string Duracion;
    string Genero;
    string Calificacion;
    string Fecha;
    string NombreEpisodio;
    string IDEpisodio;
    string Temporada;
    string NumEpisodio;

    void leerArchivo(string nom);
    void mostrarvideos();
    void mostrarepisodios();
    void mostrarpeliculas();

    public:
    void Menu();
};
#endif