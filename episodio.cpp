#include "video.h"
#include "episodio.h"

#include <iostream>
using namespace std;

Episodio::Episodio(string ID, string Nombre, string Duracion, 
                        string Calificacion, string Fecha, 
                            string Temporada, string NumEpisodio)
                :Video(ID, Nombre, Duracion, Calificacion, Fecha){
    _temporada = Temporada;
    _numepisodio = NumEpisodio;
}

void Episodio:: ImprimirInfo(){
        cout << "--------EPISODIO--------" << endl;
        cout << "Nombre episodio: " << _nombre << endl;
        cout << "ID episodio: "<< _id << endl;
        cout << "Duración episodio: "<< _duracion << endl;
        cout << "Calificacion episodio: "<< _calificacion << endl;
        cout << "Fecha episodio: "<< _fecha << endl;
        cout << "Temporada: "<< _temporada << endl;
        cout << "Numero de episodio: "<< _numepisodio << endl;
        cout << endl;
    }

string Episodio:: getnombre(){
    return _nombre;
}

string Episodio:: getcalificacion(){
    return _calificacion;
}