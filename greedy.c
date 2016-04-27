#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.c"
#include "vSt.h"

/*
 * Implementacion de greedy, revisar complejidad
 * Inspirada en una version de greedy encontrada en la web
 * Me gustó ya que es facil de entender pero hay que revisar su
 * complejidad
 */

void greedy(NimheSt *G) {
    u32 V = G.cantVertices;
    // u32 E = G->cantLados;
    u32 color;
    VerticeSt vertice = NULL;
    VerticeSt vecino = NULL;
    bool usado[V]; //Array para indicar colores no disponibles.
    for (int i = 0; i < V; i++) {
        usado[i] = false;
    }
    vertice = G->SegundoOrden[0];
    CambiarColorA(vertice, 1);
    for (int u = 1; u < V; u++)
    {
        // Revisamos los vecinos del vertice u
        // y flageamos los colores usados.
        vertice = G->SegundoOrden[u];
        u32 cantVecinos = vertice.cantVecinos;
        for (int h = 0; h < cantVecinos; h++) {
            vecino = IesimoVecinoPlus(vertice, h);
            color = ColorDelVertice(vecino);
            if(color != 0) {
                usado[color] = true;
            }
        }
        //Busquemos el primero color disponible
        for (int j = 0; j < V; j++) {
            if (usado[j] == false)
                break;
        }
        // Le ponemos el color encontrado
        CambiarColorA(vertice, j);

        // Reseteamos el array de colores disponibles a falso
        for (i = 0; i < V; i++) {
            usado[i] = false;
        }
    }
}


 