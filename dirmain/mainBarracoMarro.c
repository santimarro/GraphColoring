#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "../apifiles/Cthulhu.h"

#define min(a,b) (((a)<(b))?(a):(b))

int main() {
    NimheP grafo = NuevoNimhe();

    if (grafo == NULL) {
        printf("Error en formato de entrada\n");
        return (EXIT_FAILURE);
    }

    
    if (Chidos(grafo)) {
        printf("Grafo Bipartito\n");
        return (EXIT_SUCCESS);
    }

    printf("Grafo No Bipartito\n");
    u32 seed = (u32) time(NULL);
    srand(seed);

    u32 alduin;                      // Cantidad de colores. 
    u32 n = NumeroDeVertices(grafo); // Cantidad de vertices del grafo
    u32 minimos_colores = n;         // Cantidad minima de colores usados. 

    u32 *x = malloc(n * sizeof(u32));
    u32 *mejor_orden = malloc(n * sizeof(u32));

    for (u32 i = 0; i != n; ++i)
        x[i] = i;

    for (u32 i = 0; i != 10; ++i) {
        // TODO: Controlar que en el momento que usuario ingresa datos cantidad de vertices es >= 1

        /*
         * Generando arreglo x de números random entre 0 y cantidad de vertices - 1 sin repetidos.
         * X es un arreglo con números del 0 a cantidad de vertices - 1. El ciclo for de abajo simplemente
         * los ordena de manera aleatoria.
         */

        for (u32 j = n - 1; j != 0; --j) {
            u32 random_number = (u32) rand() % (j + 1); // 0 <= numero_random <= j

            u32 temp = x[random_number];
            x[random_number] = x[j];
            x[j] = temp;
        }

        OrdenEspecifico(grafo, x);
        alduin = Greedy(grafo);

        if (alduin < minimos_colores) {
            minimos_colores = alduin;
            for (u32 h = 0; h != n; ++h) {
                mejor_orden[h] = x[h];
            }
        }

        printf("coloreo aleatorio numero %u: %u colores\n", i + 1, alduin);
    }

    free(x);
    printf("\n");

    OrdenWelshPowell(grafo);

    alduin = Greedy(grafo);

    printf(" coloreo con Greedy en WelshPowell:%u colores\n", alduin);

    if (alduin < minimos_colores) {
        minimos_colores = alduin;
        for (u32 h = 0; h != n; ++h) {
            mejor_orden[h] = x[h];
        }
    }

    if (minimos_colores == 3) {
        printf("X(G)=3\n");
        return (EXIT_SUCCESS);
    }

    printf("\n");
    printf("====Comenzando Greedy Iterado 1001 veces====\n\n");

    OrdenEspecifico(grafo, mejor_orden);
    free(mejor_orden);
    Greedy(grafo);

    u32 a, b, c, d;
    a = b = c = d = 0;

    for (u32 i = 0; i != 1001; ++i) {
        
        u32 numero_random = ((u32) rand() % 16) + 1; // 1 <= numero_random <= 16
        if (numero_random <= 8) {
            ChicoGrande(grafo);
            ++a;
        } else if (numero_random <= 10) {
            GrandeChico(grafo);
            ++b;
        } else if (numero_random <= 15) {
            Revierte(grafo);
            ++c;
        } else if (numero_random == 16) {
            ReordenAleatorioRestringido(grafo);
            ++d;
        }
        alduin = min(alduin, Greedy(grafo));
    }

    Revierte(grafo);

    alduin = min(alduin, Greedy(grafo));
    printf("Mejor coloreo con Greedy iterado 1001 veces: %u colores\n",
           alduin);
    printf("(%u CG,%u GC, %u R, %u RAR)\n", a, b, c, d);

    DestruirNimhe(grafo);
}
