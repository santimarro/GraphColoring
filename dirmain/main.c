
#include "../apifiles/sort.h"

int main(void) {

    NimheP G = NuevoNimhe();

    Greedy(G);

    printf("Colores usados: %d \n", CantidadDeColores(G));

    printf("Primer orden: \n");
    for(u32 i = 0; i < G->cantVertices; i++) {
        printf("%u, ", G->orden[i]->colorV);
    }
    printf(".\n");

    u32 x[] = {4,0,3,2,2};

    ReordenAleatorioRestringido(G);
    printf("Segundo orden: \n");

    for(u32 i = 0; i < G->cantVertices; i++) {
        printf("%u, ", G->orden[i]->colorV);
    }
    printf(".\n");

    DestruirNimhe(G);

    return 1;
}
