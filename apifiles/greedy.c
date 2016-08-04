#include "graph.h"

/*
 * Implementacion de greedy, revisar complejidad
 * Inspirada en una version de greedy encontrada en la web
 * Me gustó ya que es facil de entender pero hay que revisar su
 * complejidad
 */

void greedy(NimheP G) {
    u32 V = G->cantVertices;
    u32 color;
    VerticeSt vertice = NULL;
    VerticeSt vecino = NULL;
    bool usado[V];          // Array para indicar colores no disponibles.
    for (u32 i = 0; i < V; i++) {
        usado[i] = false;   // Inicializo todos los colores en false(sin usar).
    }
    vertice = G->hashList->orden[0];
    vertice->colorV = 1;
    //CambiarColorA(vertice, 1);
    for (u32 u = 1; u < V; u++)
    {
        // Revisamos los vecinos del vertice u
        // y flageamos los colores usados.
        vertice = G->hashList->orden[u];
        u32 cantVecinos = vertice->gradoV;

        for (u32 h = 0; h < cantVecinos; h++) {
            //vecino = IesimoVecinoPlus(vertice, h);
            color = vecino->colorV;
            //color = ColorDelVertice(vecino);
            if(color != 0) {
                usado[color] = true;
            }
        }
        //Busquemos el primero color disponible
        for (u32 j = 0; j < V; j++) {
            if (!usado[j]) {
                // Le ponemos el color encontrado
                vertice->colorV = j;
                //CambiarColorA(vertice, j);
                break;
            }
        }

        // Reseteamos el array de colores disponibles a falso
        memset(usado, false, sizeof(bool));
    }
}


 
