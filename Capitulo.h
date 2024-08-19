// Mario Feng Wu A01644768, TC1030.315

#ifndef CAPITULO_H
#define CAPITULO_H

#include "Video.h"

using namespace std;
 
class Capitulo : public Video {
private:
    string nombreSerie;
    int numeroCapitulo;

public:
    Capitulo();
    
    Capitulo(string id, string titulo, int duracion, string genero,
             string nombreSerie, int numeroCapitulo);

    string getTipo();

    void imprimirDetalles(ostream& os);

};

#endif  