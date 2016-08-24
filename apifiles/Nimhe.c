#include "Nimhe.h"
#include <assert.h>

NimheP NuevoNimhe() {
    u32 cantv, cantl;// cant = cantidad de vertices cantl= cantidad de lados

    char *input; // Donde guardaremos cada linea de input

    int bufsize = 80;// largo de las lineas


    input = (char *)malloc(bufsize * sizeof(char)); // array donde se guardan las lineas.
    input[0] = 'c';
    while (input[0] == 'c'){
        //Pedimos lineas hasta que no sean mas comentarios
        if(fgets(input, bufsize, stdin) == NULL) {
            printf("Error interno");
            return NULL;
        }
    }
    // nos fijamos que la linea p venga luego de los comentarios.
    if (input[0] != 'p') {
        printf("Input invalido 3");
        return NULL;
    }
    char p = 'o';
    char edge[4];
    edge[0] = 'f';
    
    // parseamos la linea
    sscanf(input, "%c %s %u %u", &p, edge, &cantv, &cantl);

    //Chequeo el input correcto
    if (strncmp(edge, "edge", 4) != 0) {
        printf("Input invalido 1\n");
        return NULL;
    }

    if(cantv == 0 && cantl > 0) {
        printf("Input invalido 2 \n");
        return NULL;
    }

    //TODO Que pasa si cantv o cantl no son ints.

    NimheP grafo = NULL;
    grafo = malloc(1*sizeof(struct NimheSt));
    assert(grafo != NULL);
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    grafo->hashList = HashNuevaHash(cantv, cantl);

    u32 n, m;
    for (u32 i = 0; i < cantl; i++) {
        if(fgets(input, bufsize, stdin) != NULL) {
            // Parseo los lados
            sscanf(input, "%c %u %u", &p, &n, &m);
            if (p != 'e') {
                printf("Lado mal puesto\n");
                return NULL;
            }
            else {
                //Agrego el lado a la hashlist
                if(!HashAgregar(n, m, grafo->hashList)) {
                    printf("LADO YA EXISTE");
                    return NULL;
                }
                printf("Iteracion: %u. Cantidad total: %u\n", i, cantl);
            }
        }
        else {
            printf("Input invalido 4\n");
            return NULL;
        }
    }
    //HashEnumerarGrafo(grafo->hashList, grafo->cantVertices);
    free(input);
    printf("TERMINO DE CARGAR");
    return grafo;
}

int DestruirNimhe(NimheP G) {
    DestruirHashList(G->hashList);
    free(G);
    return 1;
}

void ImprimirVecinosDelVertice(struct VerticeSt x, NimheP G) {
    HashEnumerar(&x, G->hashList);
}

// Funciones para extraer informacion de grafo.

u32 NumeroDeVertices(NimheP G) {
    return G->cantVertices;
}

u32 NumeroDeLados(NimheP G) {
    return G->cantLados;
}

u32 NumeroVerticesDeColor(NimheP G, u32 i) {
    u32 result = 0;
    for(u32 h = 0; h < G->cantVertices; h++){
        if(G->hashList->vertices[h].colorV == i) {
            result++;
        }
    }
    return result;
}

u32 ImprimirVerticesDeColor(NimheP G, u32 i) {
    u32 result = 0;
    printf("Vertices de Color %u: ", i);
    bool flag = false;
    for(u32 h = 0; h < G->cantVertices; h++){
        if(G->hashList->vertices[h].colorV == i) {
            printf(", ");
            printf("%u", G->hashList->vertices[h].nombreV);
            result++;
            flag = true;
        }
    }
    if(flag) {
        printf(".");
    }
    else {
        printf("No hay vertices de color %u: ", i);
    }
    return result;
}


u32 CantidadDeColores(NimheP G) {
    return G->cantcolor;
}

struct VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i) {
    return *G->hashList->orden[i];
}

struct VerticeSt IesimoVecino(NimheP G, struct VerticeSt x, u32 i) {
    struct VerticeSt vecino = *HashIesimoVecino(&x, i, G->hashList);
    return vecino;
}