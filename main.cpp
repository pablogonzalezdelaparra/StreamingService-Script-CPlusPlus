//Proyecto Integrador (Propuesta de solución a Situación Problema)
//Pablo González de la Parra (A01745096)
//11/06/2021

#include "video.h"
#include "serie.h"
#include "episodio.h"
#include "pelicula.h"
#include "netflix.h"

#include <iostream>
using namespace std;


int main ()
{
    Netflix net;
    net.Menu();

    return 0;
}

//Información para usar de referencia (Opcional)
//Esta es información que puede ser útil para poder observar la adaptabilidad y buen funcionamiento del programa tanto en series como en películas
//Nombre del archivo: BasePeliculas4.csv
//Calificaciónes comúnes: (Videos 8.1), (Episodios de Game of Thrones 9.2), (Peliculas 7.6)
//Géneros comúnes: "Drama, War", "Comedy, Romance"