#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "../apifiles/sort.h"

#define min(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int main() {
    NimheP nimhe = NuevoNimhe();

    if (nimhe == NULL) {
        printf("Error en formato de entrada\n");
        return (EXIT_FAILURE);
    }

    /*
    if (Chidos(nimhe)) {
        printf("Grafo Bipartito\n");
        return (EXIT_SUCCESS);
    }*/

    printf("Grafo No Bipartito\n");
    u32 semilla = (u32) time(NULL);
    srand(semilla);

    u32 cantidad_de_colores;
    u32 cantidad_de_vertices = NumeroDeVertices(nimhe);
    u32 mejor_cantidad_de_colores = cantidad_de_vertices;

    u32 *x = malloc(cantidad_de_vertices * sizeof(u32));
    u32 *mejor_orden = malloc(cantidad_de_vertices * sizeof(u32));

    for (u32 i = 0; i != cantidad_de_vertices; ++i)
        x[i] = i;

    for (u32 i = 0; i != 10; ++i) {
        // TODO: Controlar que en el momento que usuario ingresa datos cantidad de vertices es >= 1

        /*
         * Generando arreglo x de números random entre 0 y cantidad de vertices - 1 sin repetidos.
         * X es un arreglo con números del 0 a cantidad de vertices - 1. El ciclo for de abajo simplemente
         * los ordena de manera aleatoria.
         */

        for (u32 j = cantidad_de_vertices - 1; j != 0; --j) {
            u32 numero_random = (u32) rand() % (j + 1); // 0 <= numero_random <= j

            u32 temporal = x[numero_random];
            x[numero_random] = x[j];
            x[j] = temporal;
        }

        OrdenEspecifico(nimhe, x);
        cantidad_de_colores = greedy(nimhe);

        if (cantidad_de_colores < mejor_cantidad_de_colores) {
            mejor_cantidad_de_colores = cantidad_de_colores;
            for (u32 k = 0; k != cantidad_de_vertices; ++k) {
                mejor_orden[k] = x[k];
            }
        }

        printf("coloreo aleatorio numero %u: %u colores\n", i + 1, cantidad_de_colores);
        if (cantidad_de_colores == 3) {
            printf("X(G)=3\n");
            free(x);
            return (EXIT_SUCCESS);
        }
    }

    free(x);
    printf("\n");

    OrdenWelshPowell(nimhe);

    cantidad_de_colores = greedy(nimhe);

    printf(" coloreo con Greedy en WelshPowell:%u colores\n", cantidad_de_colores);

    if (cantidad_de_colores == 3) {
        printf("X(G)=3\n");
        return (EXIT_SUCCESS);
    }

    printf("\n");
    printf("====Comenzando Greedy Iterado 1001 veces====\n\n");

    OrdenEspecifico(nimhe, mejor_orden);
    greedy(nimhe);

    
    
    u32 a, b, c, d;
    a = b = c = d = 0;
    //u32 t1 = 0;
    //u32 t2 = 0;

    for (u32 i = 0; i != 1001; ++i) {
        //printf("Iteracion: %u\n", i);
        
        u32 numero_random = ((u32) rand() % 16) + 1; // 1 <= numero_random <= 16
        //t1 = time(NULL);
        if (numero_random <= 8) {
            ChicoGrande(nimhe);
            ++a;
        } else if (numero_random <= 10) {
            GrandeChico(nimhe);
            ++b;
        } else if (numero_random <= 15) {
            Revierte(nimhe);
            ++c;
        } else if (numero_random == 16) {
            //ReordenAleatorioRestringido(nimhe);
            ++d;
        }
        //t2 = time(NULL);
        //printf("Orden en: %u\n", t2 -t1);
        //t1 = time(NULL);
        cantidad_de_colores = min(cantidad_de_colores, greedy(nimhe));
        //t2 = time(NULL);
        //printf("Greedy en: %u\n", t2 - t1);
    }

    Revierte(nimhe);

    cantidad_de_colores = min(cantidad_de_colores, greedy(nimhe));
    printf("Mejor coloreo con Greedy iterado 1001 veces: %u colores\n",
           cantidad_de_colores);
}