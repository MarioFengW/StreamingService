// Mario Feng Wu A01644768, TC1030.315

#include "Capitulo.h"

using namespace std;

Capitulo::Capitulo() 
    : Video() {}

Capitulo::Capitulo(string id, string titulo, 
                   int duracion, string genero,
                   string nombreSerie, int numeroCapitulo)
    : Video(id, titulo, duracion, genero), nombreSerie(nombreSerie), numeroCapitulo(numeroCapitulo) {}

string Capitulo::getTipo()  {
    return "Capitulo";
}

void Capitulo::imprimirDetalles(ostream& os)  {
    Video::imprimirDetalles(os);
    os << "," << nombreSerie << "," << numeroCapitulo;
    if (calificaciones.empty())
        os << ",SC";
    else
        os << "," << promedioCalificaciones();
}