#include "graph.h"


NimheP NuevoNimhe() {
    u32 cantv, cantl;
    char input[80]; // Donde guardaremos cada linea de input
    input[0] = 'c';
    while (input[0] == 'c' && getline(input, 80) != -1){
        //Pedimos lineas hasta que no sean mas comentarios
    }
    if (input[0] != 'p') {
        printf("Input invalido");
        return NULL;
    }
    char p = 'p';
    char *edge = NULL;
    char input_format[] = "p edge n m"; //Establecemos dos plantillas
    char input_format_2[] = "e n m";
    sscanf(input, input_format, "%c, %s, %u, %u", p, edge, &cantv, &cantl);

    //Chequeo el input correcto
    if (strcmp(edge, "edge") != 0) {
        printf("Input invalido\n");
        return NULL;
    }

    if(cantv == 0 && cantl > 0) {
        printf("Input invalido\n");
        return NULL;
    }

    //TODO Que pasa si cantv o cantl no son ints.

    NimheP grafo = NULL;
    grafo = malloc(1*sizeof(struct NimheSt));
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    grafo->hashList = HashNuevaHash(cantv, cantl);

    u32 n, m;
    for (u32 i = 0; i < cantl; i++) {
        if(getline(input, 80) != -1) {
            // Parseo los lados
            sscanf(input, input_format_2, "%c, %u, %u", p, &n, &m);
            if (p != 'e') {
                printf("Lado mal puesto\n");
                return NULL;
            }
            //Agrego el lado a la hashlist
            if(!HashAgregar(n, m, grafo->hashList))
                return NULL;
        }
        else {
            printf("Input invalido\n");
            return NULL;
        }
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
