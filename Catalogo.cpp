// Mario Feng Wu A01644768, TC1030.315

#include "Catalogo.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Video* Catalogo::buscarVideo(string id) {
    for (Video* video : videos) {
        if (video -> getId() == id) {
            return video;
        }
    }
    return nullptr;
}

void Catalogo::cargarVideos(const string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream iss(linea);
        string tipo, id, titulo, duracionStr, genero, nombreSerie;
        int duracion, numeroCapitulo;

        getline(iss, tipo, ',');
        getline(iss, id, ',');
        getline(iss, titulo, ',');
        getline(iss, duracionStr, ',');
        getline(iss, genero, ',');

        duracion = stoi(duracionStr);

        if (tipo == "p") {
            videos.push_back(new Pelicula(id, titulo, duracion, genero));
        } else if (tipo == "c") {
            getline(iss, nombreSerie, ',');
            iss >> numeroCapitulo;
            videos.push_back(new Capitulo(id, titulo, duracion, genero, nombreSerie, numeroCapitulo));
        }
    }

    archivo.close();
}

void Catalogo::mostrarCatalogo() {
    cout << "\nCatalogo de videos:\n\n";
    for (Video* video : videos) {
        if (Capitulo* capitulo = dynamic_cast<Capitulo*>(video)) {
            cout << *capitulo << endl << endl;
        } else if (Pelicula* pelicula = dynamic_cast<Pelicula*>(video)) {
            cout << *pelicula << endl << endl;
        } else {
            cout << *video << endl << endl;
        }
    }
}

void Catalogo::calificarVideo() {
    string id;
    cout << "\nIngrese el ID del video a calificar: ";
    cin >> id;

    Video* video = buscarVideo(id);
    if (video) {
        int calificacion;
        do {
            cout << "Ingrese la calificacion (1-5): ";
            cin >> calificacion;
        } while (calificacion < 1 || calificacion > 5);

        video -> calificar(calificacion);
        cout << "Calificacion registrada correctamente.\n";
    } else {
        cout << "No se encontro el video con ID " << id << ".\n";
    }
}

void Catalogo::mostrarPorCalificacion() {
    int opcion;
    do {
        cout << "\nSeleccione el tipo de video:\n"
             << "1. Peliculas\n"
             << "2. Capitulos\n"
             << "3. Ambos\n"
             << "Opcion: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 3);

    double calificacionMinima;
    cout << "Ingrese la calificacion minima: ";
    cin >> calificacionMinima;

    cout << "\nVideos con calificacion promedio mayor o igual a " << calificacionMinima << ":\n";

    for (Video* video : videos) {
        bool mostrar = false;
        bool esPelicula = dynamic_cast<Pelicula*>(video) != nullptr;
        bool esCapitulo = dynamic_cast<Capitulo*>(video) != nullptr;

        if ((opcion == 1 && esPelicula) || 
            (opcion == 2 && esCapitulo) || 
            (opcion == 3)) {
            if (video -> promedioCalificaciones() >= calificacionMinima) {
                mostrar = true;
            }
        }

        if (mostrar) {
            cout << video -> getId() << "," << video -> getTitulo() << ","
                 << video -> promedioCalificaciones() << endl << endl;
        }
    }
}

void Catalogo::mostrarPorGenero() {
    int opcion;
    do {
        cout << "\nSeleccione el tipo de video:\n"
             << "1. Peliculas\n"
             << "2. Capitulos\n"
             << "3. Ambos\n"
             << "Opcion: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 3);

    string genero;
    cout << "Ingrese el genero: ";
    cin.ignore();
    getline(cin, genero);

    cout << "\nVideos del genero " << genero << ":\n";

    for (Video* video : videos) {
        bool mostrar = false;
        bool esPelicula = dynamic_cast<Pelicula*>(video) != nullptr;
        bool esCapitulo = dynamic_cast<Capitulo*>(video) != nullptr;

        if ((opcion == 1 && esPelicula) || 
            (opcion == 2 && esCapitulo) || 
            (opcion == 3)) {
            if (video -> getGenero() == genero) {
                mostrar = true;
            }
        }

        if (mostrar) {
            cout << video -> getId() << "," << video -> getTitulo() << "," << video -> getGenero();
            if (video -> promedioCalificaciones() == 0.0) 
                cout << ",SC\n\n";
            else
                cout << "," << video -> promedioCalificaciones() << endl << endl;
        }
    }
}
