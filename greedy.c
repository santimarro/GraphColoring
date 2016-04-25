#include <stdio.h>
#include <stdlib.h>

#include "graph.c"
#include "vSt.h"

void greedy(NimheSt *G) {
    VerticeSt vertice = NULL;
    colores[10000];
    for(int i = 0; i < graph->cantLados; i++) {
        vertice = IesimoVerticeEnElOrden(G, i);
        if (ColorDelVertice(vertice) == 0) {
            // No fue coloreado, primera vez de greedy
            /*
             * Aca tengo que buscar en sus vecinos y en los colores ya
             * usados el minimo:
             * min(j in colores tal que ColorDelVertice(Vh) != j
             * para todo h
             * CambiarColorA(vertice) = j;
             *
             */
        }
         else {
            /*
             * Aca tengo que buscar en sus vecinos y en los colores ya
             * usados el minimo:
             * min(j in colores tal que ColorDelVertice(Vh) != j
             * para todo h
             * CambiarColorA(vertice) = j;
             *
             */
        }


    }
}

 