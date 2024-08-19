// Mario Feng Wu A01644768, TC1030.315

#include "Catalogo.h"

#include <iostream>

using namespace std;

int main() {
    Catalogo catalogo;
    catalogo.cargarVideos("videos.txt");

    int opcion;
    do {
        cout << "\nMenu:\n"
             << "1. Mostrar todo el catalogo con calificaciones\n"
             << "2. Calificar un video\n"
             << "3. Mostrar peliculas o capitulos con una calificacion minima determinada\n"
             << "4. Mostrar peliculas o capitulos de un cierto genero\n"
             << "9. Salir\n"
             << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                catalogo.mostrarCatalogo();
                break;
            case 2:
                catalogo.calificarVideo();
                break;
            case 3:
                catalogo.mostrarPorCalificacion();
                break;
            case 4:
                catalogo.mostrarPorGenero();
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida, intenta de nuevo." << endl;
        }
    } while (opcion != 9);

    return 0;
}
