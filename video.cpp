#include "video.h"

#include <iostream>
using namespace std;

Video::Video(string ID, string Nombre, string Duracion, 
                string Calificacion, string Fecha){
    _id = ID;
    _nombre = Nombre;
    _duracion = Duracion;
    _calificacion = Calificacion;
     _fecha = Fecha;
}