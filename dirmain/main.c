
#include "../apifiles/greedy.h"

int main(void) {

    NimheP G = NuevoNimhe();
    greedy(G);
    printf("Colores usados: %d \n", CantidadDeColores(G));
    printf("Numero de vertices de color %u: %u\n", 1, ImprimirVerticesDeColor(G, 1));


    return 1;
}
