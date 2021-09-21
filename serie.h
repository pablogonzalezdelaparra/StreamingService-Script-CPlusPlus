#ifndef CLASESERIE_H_
#define CLASESERIE_H_
#include "episodio.h"

#include <vector>
#include <iostream>
using namespace std;

class Serie
{
    private:
    string _genero;
    string _id;
    string _nombre;

    public:
    vector<Episodio> vecepisodios;

    Serie(string ID, string Nombre, string Genero);
    void meterepisodio(Episodio epi);
    void ImprimirInfo();
    bool operator ==(string &s);
    string getnombre();


};
#endif