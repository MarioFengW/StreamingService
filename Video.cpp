// Mario Feng Wu A01644768, TC1030.315

#include "Video.h"
#include "Capitulo.h"

#include <cmath>

using namespace std;

Video::Video() : id(""), titulo(""), duracion(0), genero("") {}

Video::Video(string id, string titulo, int duracion, string genero)
    : id(id), titulo(titulo), duracion(duracion), genero(genero) {}

string Video::getId()  {
    return id;
}

 string Video::getTitulo()  {
    return titulo;
}

int Video::getDuracion()  {
    return duracion;
}

 string Video::getGenero()  {
    return genero;
}

void Video::calificar(int calificacion) {
    calificaciones.push_back(calificacion);
}

double Video::promedioCalificaciones()  {
    if (calificaciones.empty())
        return 0.0;
    else {
        double suma = 0.0;
        for (double calificacion : calificaciones)
            suma += calificacion;

        return round(suma / calificaciones.size() * 10) / 10.0;
    }
}

void Video::imprimirDetalles(ostream& os)  {
    os << getId() << "," << getTitulo() << "," << getDuracion() << "," << getGenero();
}

ostream& operator<<(ostream& os,  Video& video) {
    video.imprimirDetalles(os);
    return os;
}