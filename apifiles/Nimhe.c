#include "Cthulhu.h"

NimheP NuevoNimhe() {
    u32 cantv, cantl; // cant = cantidad de vertices cantl = cantidad de lados

    int bufsize = 80; // largo de las lineas

    char input[bufsize];      // Donde guardaremos cada linea de input

    input[0] = 'c';
    while (input[0] == 'c'){
        // Pedimos lineas hasta que no sean mas comentarios
        if(fgets(input, bufsize, stdin) == NULL) {
            printf("Error interno");
            return NULL;
        }
    }
    // Nos fijamos que la linea p venga luego de los comentarios.
    if (input[0] != 'p') {
        printf("Formato de entrada invalido\n");
        return NULL;
    }
    char p = 'o';
    char edge[4];
    edge[0] = 'f';
    
    //Parseamos la linea.
    sscanf(input, "%c %s %u %u", &p, edge, &cantv, &cantl);

    //Chequeo el input correcto.
    if (strncmp(edge, "edge", 4) != 0) {
        printf("Formato de entrada invalido\n");
        return NULL;
    }

    if(cantv == 0 && cantl > 0) {
        printf("Formato de entrada invalido\n");
        return NULL;
    }

    //TODO Que pasa si cantv o cantl no son ints.
    // Creo el grafo.
    NimheP grafo = NULL;
    // Le asigno memoria.
    grafo = malloc(1*sizeof(struct NimheSt));
    // Completo los campos del grafo.
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    grafo->vertices = calloc(cantv,sizeof(struct VerticeSt));
    grafo->orden = malloc(cantv*sizeof(VerticeP));
    grafo->orden_natural = calloc(cantv, sizeof(VerticeP));
    grafo->vertices_usados = calloc(cantv, sizeof(bool));

    u32 n, m;// Vertices de los lados que ponen en el input.
    VerticeP xPuntero = NULL;
    VerticeP yPuntero = NULL;
    for (u32 i = 0; i < cantl; i++) {
        // Se leen los lados pidiendo lineas de tamaño bufsize
        if(fgets(input, bufsize, stdin) != NULL) {
            // Parseo los lados.
            sscanf(input, "%c %u %u", &p, &n, &m);
            // Si p no es 'e', la linea esta mal puesta.
            if (p != 'e') {
                printf("Lado mal puesto\n");
                return NULL;
            }
            else {
                
                //Agrego el lado.
                xPuntero = AgregarVertice(grafo, n);
                yPuntero = AgregarVertice(grafo, m);
                
                if(xPuntero != NULL)
                    AgregarVecino(xPuntero, yPuntero);
                else {
                    printf("Error en la carga de lado\n");
                    return NULL;
                }
                
                if(yPuntero != NULL)
                    AgregarVecino(yPuntero, xPuntero);
                else {
                    printf("Error en la carga de lado\n");
                    return NULL;
                }
                
            }
        }
        else {
            printf("Formato de entrada invalido\n");
            return NULL;
        }
    }
    return grafo;
}

int DestruirNimhe(NimheP G) {
    // Se destruyen los vertices y luego se libera el resto de G
    for(u32 i = 0; i < G->cantVertices; i++)
        DestruirVertice(G->vertices[i]);

    free(G->vertices);
    free(G->orden);
    free(G->vertices_usados);
    free(G->orden_natural);
    free(G);
    return 1;
}

void ImprimirVecinosDelVertice(struct VerticeSt x, NimheP G) {
    u32 grado = x.gradoV;
    
    for (u32 i = 0; i < grado; i++) {
        printf("%u", x.vecinos[i]->nombreV);
        if(i != grado - 1)
            printf(",");
    }
    u32 cantidad = G->cantLados;
    cantidad++;
    printf(".\n");
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
        if(G->vertices[h].colorV == i) {
            result++;
        }
    }
    return result;
}

u32 ImprimirVerticesDeColor(NimheP G, u32 i) {
    u32 result = 0; // Numero de vertices del 'i' color.
    u32 size = NumeroVerticesDeColor(G, i);
    u32 result_[size];
    printf("Vertices de Color %u: ", i);

    bool flag = false;//Flag que se vuelve verdadera si existe un vertices con el color i.
    for(u32 h = 0; h < G->cantVertices; h++){
        if(G->vertices[h].colorV == i) {
            result_[result] = G->vertices[h].nombreV;
            result++;
            flag = true;
        }
    }
    if(flag) {
        for(u32 j = 0; j < size; j++) {
            printf("%u", result_[j]);
            if(j != size - 1)
                printf(", ");
        }
        printf(".\n");
    }
    else {
        printf("No hay vertices de color %u: \n", i);
    }
    return result;
}


u32 CantidadDeColores(NimheP G) {
    return G->cantcolor;
}

struct VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i) {
    return *G->orden[i];
}

struct VerticeSt IesimoVecino(NimheP G, struct VerticeSt x, u32 i) {
    u32 cantidad = G->cantLados;
    cantidad++;
    if(x.vecinos[i] != 0)
        return *x.vecinos[i];
    else {
        printf("Vertice %u no tiene %u vecinos o mas\n", x.nombreV, i);
        return x;
    }
}


VerticeP AgregarVertice(NimheP G, u32 z) {

    VerticeP xPuntero = NULL;   // Puntero a vertice
    u32 n = G->cantVertices;    // Numero de vertices
    u32 id_z = z % n;           // El Hash de 'z'
    u32 contador = 0;           //
    // Buscamos si existe el vertice 'z', en caso que no exista, se le encuentra un lugar.
    while (G->vertices_usados[id_z] && contador < n) {
        contador++;    
        if (G->vertices[id_z].nombreV == z) {
            xPuntero = &G->vertices[id_z];
            contador = 0;
            break;
        }
        else {
            id_z++;
            if (id_z == n)
                id_z = 0;
        }
    }


    if(contador == n)
        return NULL;

    // En el caso que no exista, se lo crea.
    if(xPuntero == NULL) {
        struct VerticeSt x = NuevoVertice(z);
        G->vertices[id_z] = x;
        xPuntero = &G->vertices[id_z];
        G->vertices_usados[id_z] = true;
        G->orden[id_z] = xPuntero;
    }
    
    return xPuntero;
}
