#include <stdio.h>
#include <stdlib.h>

#include "vSt.h"
#include "lenla.h"

typedef unsigned int *u32;

typedef NimheSt *NimheP;

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    u32 *PrimerOrden;       // Tengo dudas aca si deberia ser una lista 
                            // de vertices completos o de numero de vertices
    u32 *SegundoOrden;                                  //^ es de esto!
    VerticeSt *vertices;    // Array de vértices.
    //hash_link
    //Espacio para mas cosas
};

bool esVertice(VerticeSt *v, u32 longitud, u32 n) {
    bool result;
    u32 i = 0;
    while((i < longitud) && (!result)) {
        result = result || (v[i].nombreV == n);
        ++i;
    }
    return result;    
}

void nuevoLado(NimheSt *G, u32 i, u32 j) { //Dudas aca si deberia ser puntero G
    if (!esVertice(grafo->vertices, n)
        agregarVertice(grafo->vertices, n);
    if (!esVertice(grafo->vertices, m)
        agregarVertice(grafo->vertices,m);    
    
    AgregarLado(f, j);
    AgregarLado(j, f); //Pensar mejor implementacion pero no cambia mucho
}

void inicOrdenes(u32 *primero, u32 *segundo, VerticeSt *v) {
    for(i=0; i < cantv; ++i) {
        primero[i], segundo[i] = v[i];
    // Inicializa los dos órdenes como los vértices ordenados por sus nombres.
    }// Poner en donde corresponda.
}

NimheP NuevoNimhe() {
    u32 cantv, cantl;
    char input[80];
    input[0] = 'c';
    while (input[0] == 'c') {
        scanf("%s", &input);
    }
    if (input[0] != 'p') {
        printf("(Input invalido");
        return NULL;
    }

    char *edge;
    char input_format[] = "p edge n m";
    char input_format_2[] = "e n m";
    sscanf(input, input_format, "%c, %s, %u, %u", p, edge, &cantv, &cantl);
    //Chequeo el input correcto
    if (edge != "edge") {
        printf("Input invalido\n");
        return NULL;
    }
    NimheP grafo = NULL;
    grafo = malloc(1*sizeof(struct NimheSt));
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    struct VerticeSt *arreglov[cantv] = {NULL};// Creo un arreglo de vértices en NULL.
    grafo->vertices = arreglov;// Apunto a lo mismo que arreglov. ¿Debería setear en NULL a arreglov ahora?
    // Las dos lineas de arriba podrían ser una función inicVertices, hablarlo luego.
    grafo->PrimerOrden, grafo->SegundoOrden = malloc(cantv*sizeof(u32));
    
    /* FALTA AGREGAR ESTRUCTURA A CADA VERTICE Y CONTAR EL GRADO.*/

    u32 n, m;
    bool existe = false;
    u32 len = 0;
    for (u32 i = 0; i < cantl; i++) {
        scanf("%s", &input);
        sscanf(input, input_format_2, "%c, %u, %u", p, &n, &m);
        if (p != 'e')
            return NULL;
        nuevoLado(n, m); // <- VER CAMBIOS EN IMPLEMENTACIÓN .
        for (u32 i = 0; i < cantv; i++) {
            existe = existe || PrimerOrden[i] == n; // Ver inicOrdenes a ver si se puede sacar esto.   
        }
        if (!existe) {
            PrimerOrden[len];
            SegundoOrden[len];
            ++len;
        }
    }

    return grafo;
}

VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i) {
    IesimoVecinoPlus(G->SegundoOrden, i);
}

void agregarVertice(VerticeSt *v, u32 n, u32 longitud) {
    u32 i = 0;
    while (i < longitud) {
        if (v[i] == NULL) {
            v[i] = NuevoVertice(n);
            break;
        }
        ++i;
    }
}

