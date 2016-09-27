#include <stdio.h>
#include <stdlib.h>


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

    bool mejor_orden_guardado = false; // Booleano donde se pondra en true cuando se haya guardado el mejor orden.

    for (u32 i = 0; i != n; ++i)
        x[i] = i;

    for (u32 i = 0; i != 10; ++i) {
        // Se genera un array aleatorio x, el cual servirá como plantilla de ordenacion para OrdenEspecifico()
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
            mejor_orden_guardado = true;
            for (u32 h = 0; h != n; ++h) {
                mejor_orden[h] = x[h];
            }
        }

        printf("coloreo aleatorio numero %u: %u colores\n", i + 1, alduin);
    }
    // En el caso donde los 10 coloreos hayan dado igual resultado, se copia el ultimo orden.
    if(!mejor_orden_guardado) {
        for (u32 h = 0; h != n; ++h) {
            mejor_orden[h] = x[h];
        }
    }

    free(x);
    printf("\n");

    OrdenWelshPowell(grafo);

    alduin = Greedy(grafo);

    printf(" coloreo con Greedy en WelshPowell:%u colores\n", alduin);

    bool welshPowellGana = false; // Variable booleana que será true si con el orden WelshPowell se obtiene un mejor coloreo
    //Aqui chequeamos si se obtuvo un menor coloreo al previamente guardado.
    if (alduin < minimos_colores) {
        minimos_colores = alduin;
        welshPowellGana = true;
    }
    // Si se obtuvo un numero cromatico = 3, se notifica y se termina el programa.
    if (minimos_colores == 3) {
        printf("X(G)=3\n");
        return (EXIT_SUCCESS);
    }

    printf("\n");
    printf("====Comenzando Greedy Iterado 1001 veces====\n\n");
    
    // Si en el coloreo con WelshPowell no se obtuvo un mejor coloreo,
    // se ordena segun el mejor coloreo de los 10 anteriores.
    if(!welshPowellGana)
        OrdenEspecifico(grafo, mejor_orden);

    free(mejor_orden);
    Greedy(grafo);

    u32 a, b, c, d;
    a = b = c = d = 0;

    for (u32 i = 0; i != 1001; ++i) {
        // Generamos un numero random entre 1 y 16 para elegir que tipo de orden se ejecuta.
        u32 numero_random = ((u32) rand() % 16) + 1;
        // Siguiendo lo pedido por la catedra, se especifican las probabilidades para cada tipo de ordenacion
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
