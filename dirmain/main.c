
#include "../apifiles/sort.h"

int main(void) {

    NimheP G = NuevoNimhe();
    greedy(G);
    printf("Colores usados: %d \n", CantidadDeColores(G));
    printf("Numero de vertices de color %u: %u\n", 1, ImprimirVerticesDeColor(G, 1));
    /*
    printf("Primer orden: \n");
    for(u32 i = 0; i < G->cantVertices; i++) {
        printf("%u, ", G->hashList->orden[i]->colorV);
    }
    GrandeChico(G);
    printf("Segundo orden: \n");
    for(u32 i = 0; i < G->cantVertices; i++) {
        printf("%u, ", G->hashList->orden[i]->colorV);
    }*/

    DestruirNimhe(G);

    return 1;
}
