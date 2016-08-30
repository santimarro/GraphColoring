
#include "../apifiles/Nimhe.h"

int main(void) {

    NimheP G = NuevoNimhe();

    /*
    greedy(G);

    OrdenNatural(G);

    printf("Colores usados: %d \n", CantidadDeColores(G));

    
    printf("Numero de vertices de color %u: %u\n", 1, ImprimirVerticesDeColor(G, 1));
    printf("Primer orden: \n");
    for(u32 i = 0; i < G->cantVertices; i++) {
        printf("%u, ", G->hashList->orden[i]->nombreV);
    }
    printf(".\n");

    u32 x[] = {4,0,3,2,2};


    printf("Segundo orden: \n");

    for(u32 i = 0; i < G->cantVertices; i++) {
        printf("%u, ", G->hashList->orden[i]->colorV);
    }

    printf(".\n");

    */

    DestruirNimhe(G);

    return 1;
}
