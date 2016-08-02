#include "graph.h"


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

    u32 mOrden[n];
    NimheP grafo = NULL;
    grafo = malloc(1*sizeof(struct NimheSt));
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    grafo->hashList = HashNuevaHash(cantv, cantl);
    grafo->Orden = &mOrden;

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

        if(!HashAgregar(n, m, grafo->hashList))
            return NULL;
    }
    return grafo;
}

int DestruirNimhe(NimheP G) {
    DestruirHashList(G->hashList);
    free(G);
    return 1;
}

void ImprimirVecinosDelVertice(VerticeSt x, NimheP G) {
    HashEnumerar(x, G->hashList);
}

// Funciones para extraer informacion de grafo.

u32 NumeroDeVertices(NimheP G);
