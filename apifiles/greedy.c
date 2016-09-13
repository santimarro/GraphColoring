#define MAX(a,b) (((a)>(b))?(a):(b))
#include "Cthulhu.h"

/*
 * Implementacion de greedy, revisar complejidad
 * Inspirada en una version de greedy encontrada en la web
 * Me gustó ya que es facil de entender pero hay que revisar su
 * complejidad
 */

u32 Greedy(NimheP G) {
    u32 n = G->cantVertices;    // Cantidad de vertices
    u32 color;                  // Variable para guardar color actual del vecino
    u32 max_color = 0;          //Variable para guardar la cantidad maxima de colores
    VerticeP vertice = NULL;    //Puntero para guardar vertice
    bool usado[n+1];            // Array para indicar colores no disponibles. n+1 ya que el color 0 no se usa


    memset(usado, false, (n+1)*sizeof(bool));   // Inicializo todos los colores en false(sin usar).
    
    // For para resetear los colores de los vertices
    for(u32 i = 0; i < n; i++) {
        G->vertices[i].colorV = 0;
    }
    vertice = G->orden[0]; // Obtenemos el puntero al primer vertice en el orden
    vertice->colorV = 1;   // Le ponemos el primer color. 
    for (u32 u = 1; u < n; u++) {
        // Revisamos los vecinos del vertice u.
        // y flageamos los colores usados.
        vertice = G->orden[u]; // Obtenemos el u'esimo vertice.
        
        u32 grado = vertice->gradoV;  // Guardamos en grado el grado del vertice u.
        
        // For para recorrer los vecinos, donde chequeamos el color de cada uno de ellos
        // y marcamos el mismo como usado (siempre y cuando este coloreado).
        for (u32 i = 0; i < grado; i++) {

            color = vertice->vecinos[i]->colorV;
            if (color) {
                usado[color] = true;
            }
        }

        //Busquemos el primer color disponible
        for (u32 j = 1; j < n + 1; j++) {
            if (!usado[j]) {
                // Le ponemos el color encontrado
                vertice->colorV = j;
                max_color = MAX(max_color, j);
                break;
            }
        }

        // Reseteamos el array de colores disponibles a falso
       for (u32 i = 0; i < grado; i++) {

            color = vertice->vecinos[i]->colorV;
            //color = ColorDelVertice(vecino);
            if (color) {
                usado[color] = false;
            }
        }
    }
    G->cantcolor = max_color;
    return max_color;
}


 
