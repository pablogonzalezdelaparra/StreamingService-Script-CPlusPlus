#ifndef CLASEVIDEO_H_
#define CLASEVIDEO_H_

#include <iostream>
using namespace std;

class Video
{
    protected:
    string _nombre;
    string _calificacion;
    string _id;
    string _duracion;
    string _fecha;
    Video(string ID, string Nombre, string Duracion, 
            string Calificacion, string Fecha);

    virtual void ImprimirInfo()=0;


};
#endif