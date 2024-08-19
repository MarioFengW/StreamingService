// Mario Feng Wu A01644768, TC1030.315

#ifndef CATALOGO_H
#define CATALOGO_H

#include "Video.h"
#include "Pelicula.h"
#include "Capitulo.h"

using namespace std;

class Catalogo {
private:
    vector<Video*> videos;

public:
    void cargarVideos(const string nombreArchivo);

    void mostrarCatalogo();

    void calificarVideo();

    void mostrarPorCalificacion();

    void mostrarPorGenero();
    
    Video* buscarVideo(string id);
    
};

#endif  
