#define MAX(a,b) (((a)>(b))?(a):(b))
#include "Cthulhu.h"

struct QueueSt CrearQueue(u32 size) {
    struct QueueSt q;
    q.head = q.tail = -1;
    q.theQueue = malloc(size*sizeof(VerticeP));
    return q;
}

void DestruirQueue(struct QueueSt *q) {
    free(q->theQueue);
}

void Enqueue(struct QueueSt *q, VerticeP v) {
    // Increment tail index
    q->tail++;
    // Add the item to the Queue
    q->theQueue[q->tail] = v;
    return;
}

VerticeP Dequeue(struct QueueSt *q) {
    VerticeP v;
    q->head++;
    v = q->theQueue[q->head]; // Get character to return
    return v;           // Return popped character
}

u32 isEmpty(struct QueueSt *q) {
    return (q->head == q->tail);
}


u32 Greedy(NimheP G) {
    u32 n = G->cantVertices;    // Cantidad de vertices
    u32 color;                  // Variable para guardar color actual del vecino
    u32 max_color = 0;          //Variable para guardar la cantidad maxima de colores
    VerticeP vertice = NULL;    //Puntero para guardar vertice
    bool usado[n+1];            // Array para indicar colores no disponibles. n+1 ya que el color 0 no se usa
    u32 grado = 0;


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
        
        grado = vertice->gradoV;  // Guardamos en grado el grado del vertice u.
        
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
            if (color) {
                usado[color] = false;
            }
        }
    }
    G->cantcolor = max_color;
    return max_color;
}

int Chidos(NimheP G) {
    VerticeP x;
    VerticeP vertice = NULL;
    struct QueueSt q;
    u32 indice = 0;
    u32 n = G->cantVertices;
    // For para resetear los colores de los vertices
    for(u32 i = 0; i < n; i++) {
        G->orden[i]->colorV = 0;
    }

    u32 vertices_coloreados = 0;

    while (vertices_coloreados < n) {
        x = G->orden[indice];
        if(x->colorV == 0) {
            x->colorV = 1;
            vertices_coloreados++;
            q = CrearQueue(n);
            Enqueue(&q, x);
            // While para desencolar q
            while(!isEmpty(&q)) {
                vertice = Dequeue(&q);
                // For para recorrer los vecino.
                for(u32 i = 0; i < vertice->gradoV; i++) {
                    // Si el vecino no tiene color, se encola y se colorea.
                    if(vertice->vecinos[i]->colorV == 0) {
                        Enqueue(&q, vertice->vecinos[i]);
                        vertice->vecinos[i]->colorV = (3 - vertice->colorV);
                        //aumento los vertices coloreados
                        vertices_coloreados++;
                    }
                    // Si un vecino ya tenia el mismo color entonces no es bipartito. Hago return 0
                    else if (vertice->colorV == vertice->vecinos[i]->colorV) {
                        DestruirQueue(&q);
                        return 0;
                    }
                }
            }
            DestruirQueue(&q);
        }
        indice++;
    }

    // For que revisa que sea un coloreo propio.
    for(u32 i = 0; i < n; i++) {
        vertice = G->orden[i];
        for(u32 j = 0; j < vertice->gradoV; j++) {
            if(vertice->colorV == vertice->vecinos[j]->colorV)
                return 0;
        }
    }

    return 1;
}


 
