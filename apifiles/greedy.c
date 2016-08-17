
#define MAX(a,b) (((a)>(b))?(a):(b))
#include "Nimhe.h"

/*
 * Implementacion de greedy, revisar complejidad
 * Inspirada en una version de greedy encontrada en la web
 * Me gustó ya que es facil de entender pero hay que revisar su
 * complejidad
 */

void greedy(NimheP G) {
    u32 V = G->cantVertices;
    u32 color;
    u32 max_color = 0;
    VerticeSt vertice = NULL;
    VerticeSt vecino = NULL;
    bool usado[V+1];          // Array para indicar colores no disponibles. V+1 ya que el color 0 no se usa

    memset(usado, false, (V+1)*sizeof(bool));   // Inicializo todos los colores en false(sin usar).

    vertice = G->hashList->orden[0];
    vertice->colorV = 1;
    //printf("Vertice: %u Color: %d\n", vertice->nombreV, vertice->colorV);
    //CambiarColorA(vertice, 1);
    for (u32 u = 1; u < V; u++) {
        // Revisamos los vecinos del vertice u
        // y flageamos los colores usados.
        vertice = G->hashList->orden[u];
        if (vertice != NULL) {
            u32 cantVecinos = vertice->gradoV;

            for (u32 h = 0; h < cantVecinos; h++) {
                vecino = HashIesimoVecino(vertice, h, G->hashList); //TODO mejorar la implementacion de recorrer los vecinos
                color = vecino->colorV;
                //color = ColorDelVertice(vecino);
                if (color != 0) {
                    usado[color] = true;
                }
            }
            //Busquemos el primero color disponible
            for (u32 j = 1; j < V + 1; j++) {
                if (!usado[j]) {
                    // Le ponemos el color encontrado
                    vertice->colorV = j;
                    max_color = MAX(max_color, j);
                    G->cantcolor = max_color;
                    //printf("Vertice: %u Color: %d\n", vertice->nombreV, j);
                    break;
                }
            }

            // Reseteamos el array de colores disponibles a falso
            memset(usado, false, (V + 1) * sizeof(bool));
        }
    }
}


 
