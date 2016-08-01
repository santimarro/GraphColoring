#include <stdio.h>
#include <stdlib.h>


#include "graph.h"

typedef unsigned int *u32;

typedef NimheSt *NimheP;

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    hashLink hashLink;
    /*
     * u32 *PrimerOrden;       // Tengo dudas aca si deberia ser una lista
     * u32 *SegundoOrden;                                  //^ es de esto!
     * VerticeSt *vertices;    // Array de vértices.
    */
};

NimheP NuevoNimhe() {
    u32 cantv, cantl;
    char input[80]; // Donde guardaremos cada linea de input
    input[0] = 'c';
    while (input[0] == 'c') {
        getline(input, 80); //Pedimos lineas hasta que no sean mas comentarios
    }
    if (input[0] != 'p') {
        printf("Input invalido");
        return NULL;
    }

    char *edge;
    char input_format[] = "p edge n m"; //Establecemos dos plantillas
    char input_format_2[] = "e n m";
    sscanf(input, input_format, "%c, %s, %u, %u", p, edge, &cantv, &cantl);
    //Chequeo el input correcto
    if (edge != "edge") {
        printf("Input invalido\n");
        return NULL;
    }
    //TODO terminar de chequear el input
    NimheP grafo = NULL;
    grafo = malloc(1*sizeof(struct NimheSt));
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    grafo->hashLink = newhashList(cantv);

    /*
    struct VerticeSt *arreglov[cantv] = {NULL};// Creo un arreglo de vértices en NULL.
    grafo->vertices = arreglov;// Apunto a lo mismo que arreglov. ¿Debería setear en NULL a arreglov ahora?
    // Las dos lineas de arriba podrían ser una función inicVertices, hablarlo luego.
    grafo->PrimerOrden, grafo->SegundoOrden = malloc(cantv*sizeof(u32));
    */
    /* FALTA AGREGAR ESTRUCTURA A CADA VERTICE Y CONTAR EL GRADO.*/

    u32 n, m;
    bool existe = false;
    u32 len = 0;
    for (u32 i = 0; i < cantl; i++) {
        getline(input, 80);
        sscanf(input, input_format_2, "%c, %u, %u", p, &n, &m);
        if (p != 'e') {
            printf("Lado mal puesto\n");
            return NULL;
        }
        VerticeSt x = NuevoVertice(n);
        VerticeSt y = NuevoVertice(m);

        if(!hash_add(x, y, grafo->hashLink))
            return NULL;
    }
    return grafo;
}

int DestruirNimhe(NimheP G) {
    Destruir
}

// Cambiar cuando este la hash.

// Funciones para extraer informacion de grafo.
