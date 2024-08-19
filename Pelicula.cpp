// Mario Feng Wu A01644768, TC1030.315

#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula(string id, string titulo, int duracion, string genero)
    : Video(id, titulo, duracion, genero) {}

string Pelicula::getTipo()  {
    return "Pelicula";
}

void Pelicula::imprimirDetalles(ostream& os) {
    Video::imprimirDetalles(os);
    if (calificaciones.empty())
        os << ",SC";
    else
        os << "," << promedioCalificaciones();
}