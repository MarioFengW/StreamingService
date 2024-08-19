// Mario Feng Wu A01644768, TC1030.315

#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

using namespace std;
 
class Pelicula : public Video {
public:
    Pelicula(string id, string titulo, int duracion, string genero);

    string getTipo();
    
    void imprimirDetalles(ostream& os);

};

#endif  