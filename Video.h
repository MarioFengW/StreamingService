// Mario Feng Wu A01644768, TC1030.315

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video {
protected:
    string id;
    string titulo;
    int duracion;
    string genero;
    string nombreSerie;
    int numeroCapitulo;
    vector<int> calificaciones;

public:
    Video();
    Video(string id,  string titulo, int duracion,  string genero);

    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();

    virtual string getTipo() = 0;

    void calificar(int calificacion);
    double promedioCalificaciones();

    virtual void imprimirDetalles(ostream& os);
    friend ostream& operator<<(ostream& os,  Video& video);
};

#endif 