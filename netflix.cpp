#include "netflix.h"

#include <iostream>

#include <fstream>
#include <unistd.h>

using namespace std;

void Netflix::leerArchivo(string nom){
    _nombre_archivo = nom;
    int contador = 0;
    ifstream myFile;
    myFile.open(_nombre_archivo);

    getline(myFile,ID,';');
    getline(myFile,Nombre,';');
    getline(myFile,Duracion,';');
    getline(myFile,Genero,';');
    getline(myFile,Calificacion,';');
    getline(myFile,Fecha,';');
    getline(myFile,NombreEpisodio,';');
    getline(myFile,IDEpisodio,';');
    getline(myFile,Temporada,';');
    getline(myFile,NumEpisodio,'\n');

    while(myFile.good()) {
    getline(myFile,ID,';');
    getline(myFile,Nombre,';');
    getline(myFile,Duracion,';');
    getline(myFile,Genero,';');
    getline(myFile,Calificacion,';');
    getline(myFile,Fecha,';');
    getline(myFile,NombreEpisodio,';');
    getline(myFile,IDEpisodio,';');
    getline(myFile,Temporada,';');
    getline(myFile,NumEpisodio,'\n');

        if (NombreEpisodio == ""){
            for (int i=0; (i < vectorpeli.size()); i++){
                if (vectorpeli[i].getnombre() == Nombre){
                    contador = contador + 1;
                }
            }

            if (contador > 0){
                //cout << "Ya existe esta pelicula. No se guardará nuevamente" << endl;
                contador = 0;
                }

            else{
                Pelicula peli(ID,  Nombre,  Duracion,  Calificacion,  Fecha, Genero);
                vectorpeli.push_back(peli);
            }
        }

        else{
            for (int i=0; (i < vectorserie.size()); i++){
                if (vectorserie[i].getnombre() == Nombre){
                    Episodio epi(IDEpisodio,  NombreEpisodio,  Duracion, Calificacion,  
                                    Fecha,  Temporada,  NumEpisodio);
                    vectorserie[i].meterepisodio(epi);
                    contador = contador + 1;
                    break;
                }
            }

            if (contador > 0){
                //cout << "Ya existe esta serie. No se guardará nuevamente" << endl;
                contador = 0;
            }

            else{
                Serie seri( ID,  Nombre,  Genero);
                Episodio epi( IDEpisodio,  NombreEpisodio,  Duracion, Calificacion,
                                Fecha,  Temporada,  NumEpisodio);
                seri.meterepisodio(epi);
                vectorserie.push_back(seri);
            }
        }
    }
cout << endl;
cout << "Resumen de carga del documento" << endl;
cout << "------------------------------" << endl;
cout << "Se cargaron " << vectorpeli.size() << " peliculas" << endl;
cout << "Se cargaron " << vectorserie.size() << " series" << endl;
for (int i=0; (i < vectorserie.size()); i++){
    cout << "Se cargaron " << vectorserie[i].vecepisodios.size() << " episodios de la serie " << vectorserie[i].getnombre() << endl;
}

}

void Netflix::Menu(){
    string nom, resp;
    int respuesta_menu;
    int cont = 0;
    int yap = 1;

    while (cont == 0){
        cout << "==================================================================================" << endl;
        cout << "                                  MENU NETFLIX                                    " << endl;
        cout << "==================================================================================" << endl;
        cout << "1) Cargar archivo de datos" << endl;
        cout << "2) Mostrar los videos en general con una cierta calificación o de un cierto género" << endl;
        cout << "3) Mostrar los episodios de una determinada serie con una calificacion determinada" << endl;
        cout << "4) Mostrar las películas con cierta calificacion" << endl;
        cout << "0) Salir" << endl;
        cout << endl;

        cout << "Que opción quieres elegir?: ";

        try{
            cin >> resp;
                if (stoi(resp) > 4 || stoi(resp) < 0){
                    throw(stoi(resp));
                }
        }
        catch(int &res){
            cout << "Opción inválida... Eliga un número de 0 a 4." << endl;
            cout << "Opción elegida: " << res << endl;
            cout << endl;
        }

        catch (exception &error){
            cout << "Opción inválida... Eliga un valor numérico mostrado en el menú" << endl;
            cout << "Opción elegida: " << resp << endl;
            resp = "5";
        }

        switch (stoi(resp)){
            case 1:
                if (yap == 1){
                    cout << "Introducir el nombre del archivo: ";
                    cin >> nom;
                    cout << endl;
                    leerArchivo(nom);
                    cout << endl;
                    yap = yap + 1;
                    break;
                }
                else {
                    cout << "Ya se cargó un archivo de datos" << endl;
                    cout << endl;
                    break;
                }
            case 2:
                mostrarvideos();
                break;
            case 3:
                mostrarepisodios();
                break;
            case 4:
                mostrarpeliculas();
                break;
            case 5:
                break;
            case 0:
                cout << endl;
                cont = 1;
                cout << "Cerrando sesión..." << endl;
                sleep(2);
                break;
        }
    }

    cout << "Su sesión ha sido cerrada. Vuelva pronto!" << endl;
}

void Netflix::mostrarvideos(){
    string dec, cali, gen;

    cout << "Mostrar videos por: " << endl;
    cout << "1) Calificación" << endl;
    cout << "2) Género" << endl;
    cout << endl;

    cout << "Que opción quieres elegir?: ";
    cin >> dec;
    cout << endl;

    if (dec == "1"){
        cout << "Mostrar videos con calificación de: ";
        cin >> cali;
        cout << endl;
        cout << endl;

        for (int i=0; (i < vectorpeli.size()); i++){
            if (vectorpeli[i].getcalificacion() == cali){
            vectorpeli[i].ImprimirInfo();
            }
        }

        for (int i=0; (i < vectorserie.size()); i++){
            for (int j=0; (j < vectorserie[i].vecepisodios.size()); j++){
                if (vectorserie[i].vecepisodios[j].getcalificacion() == cali){
                    vectorserie[i].ImprimirInfo();
                    vectorserie[i].vecepisodios[j].ImprimirInfo();
                }
            }
        } 
    }

    if (dec == "2"){
        cout << "Mostrar videos con género de: ";
        cin.ignore();
        getline(cin, gen);
        cout << endl;
        cout << endl;

        for (int i=0; (i < vectorpeli.size()); i++){
            if (vectorpeli[i] == gen){
            vectorpeli[i].ImprimirInfo();
            }
        }

        for (int i=0; (i < vectorserie.size()); i++){
            if (vectorserie[i] == gen){
                vectorserie[i].ImprimirInfo();
                for (int j=0; (j < vectorserie[i].vecepisodios.size()); j++){
                    if (vectorserie[i] == gen){
                        vectorserie[i].vecepisodios[j].ImprimirInfo();
                    }
                }
            }
        } 
    }
}

void Netflix::mostrarepisodios(){
    string cali, nomser;

    cout << "Que serie quieres elegir?: ";
    cin.ignore();
    getline(cin, nomser);
    cout << endl;

    cout << "Mostrar episodios con calificación de: ";
    cin >> cali;
    cout << endl;

    for (int i=0; (i < vectorserie.size()); i++){
        if (vectorserie[i].getnombre() == nomser){
            vectorserie[i].ImprimirInfo();
            for (int j=0; (j < vectorserie[i].vecepisodios.size()); j++){
                if (vectorserie[i].vecepisodios[j].getcalificacion() == cali){
                    vectorserie[i].vecepisodios[j].ImprimirInfo();
                }
            }
        }
    } 

}

void Netflix::mostrarpeliculas(){
    string cali;

    cout << "Mostrar peliculas con calificación de: ";
    cin >> cali;
    cout << endl;

    for (int i=0; (i < vectorpeli.size()); i++){
        if (vectorpeli[i].getcalificacion() == cali){
        vectorpeli[i].ImprimirInfo();
        }
    }

}