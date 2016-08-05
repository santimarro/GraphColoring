#include "graph.h"


NimheP NuevoNimhe() {
    u32 cantv, cantl;

    char *input; // Donde guardaremos cada linea de input
    size_t bufsize = 80;

    input = (char *)malloc(bufsize * sizeof(char));
    input[0] = 'c';
    while (input[0] == 'c'){
        //Pedimos lineas hasta que no sean mas comentarios
        if(getline(&input, &bufsize, stdin) == -1) {
            printf("Error interno");
            return NULL;
        }
    }
    if (input[0] != 'p') {
        printf("Input invalido 3");
        return NULL;
    }
    char p = 'o';
    char edge[4];
    edge[0] = 'f';

    //char input_format[] = {'p',' ', 'e', 'd', 'g', 'e', ' ', 'n', ' ', 'm'}; //Establecemos dos plantillas
    //char input_format_2[] = {'e', ' ', 'n', ' ', 'm'};
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
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    grafo->hashList = HashNuevaHash(cantv, cantl);

    u32 n, m;
    for (u32 i = 0; i < cantl; i++) {
        if(getline(&input, &bufsize, stdin) != -1) {
            // Parseo los lados
            sscanf(input, "%c %u %u", &p, &n, &m);
            if (p != 'e') {
                printf("Lado mal puesto\n");
                return NULL;
            }
            else {
                //Agrego el lado a la hashlist
                if(!HashAgregar(n, m, grafo->hashList))
                    return NULL;

                if(!HashAgregar(m, n, grafo->hashList))
                    return NULL;
            }
        }
        else {
            printf("Input invalido 4\n");
            return NULL;
        }
    }

    HashEnumerarGrafo(grafo->hashList, grafo->cantVertices);
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
