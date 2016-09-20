#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "../apifiles/Cthulhu.h"

int main(void) {

    NimheP G = NuevoNimhe();

    Greedy(G);

    printf("Cantidad de vertices: %u \n", NumeroDeVertices(G));
    printf("Cantidad de lados: %u \n", NumeroDeLados(G));

    printf("Colores usados: %u \n", CantidadDeColores(G));


    ImprimirVecinosDelVertice(G->vertices[0], G);
    ImprimirVecinosDelVertice(G->vertices[1], G);
    
    u32 numero = 1;

//    scanf("%u", &numero);
    printf("Numero de vertices de color %u: %u\n", numero, NumeroVerticesDeColor(G, numero));

    ImprimirVerticesDeColor(G, numero);


    struct VerticeSt x = IesimoVerticeEnElOrden(G, numero);

    struct VerticeSt y = IesimoVecino(G, x, numero);
    printf("%u\n", y.nombreV);

    /*printf("Primer orden: \n");
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
    */
    DestruirNimhe(G);

    return 1;
}
