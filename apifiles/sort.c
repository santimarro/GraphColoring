#include "sort.h"

u32 random = 0;

int CrecienteCompNombre(const void * x, const void * y) {
    VerticeSt v1 = *(VerticeSt*) x;
    VerticeSt v2 = *(VerticeSt*) y;

    if(v1->nombreV < v2->nombreV)
        return -1;
    else
        return 1;
}

int CompWelshPowell(const void * x, const void * y) {
    VerticeSt v1 = *(VerticeSt*) x;
    VerticeSt v2 = *(VerticeSt*) y;

    if(v1->gradoV < v2->gradoV)
        return 1;
    else if (v1->gradoV == v2->gradoV)
        return 0;
    else
        return -1;
}
// Funcion de comparacion para ReordenAletorioRestringido
int CompReordenAleatorio(const void * x, const void * y) {
    VerticeSt v1 = *(VerticeSt*) x;
    VerticeSt v2 = *(VerticeSt*) y;
    u32 i = random;
    if(v1->colorV == i && v2->colorV == i) {
        return 0;
    }
    else if (v1->colorV == i) {
        return -1;
    }
    else if(v2->colorV == i) {
        return 1;
    }
    else
        return 0;
}

int CrecienteCompColores(const void * x, const void * y) {
    VerticeSt v1 = *(VerticeSt*) x;
    VerticeSt v2 = *(VerticeSt*) y;

    if(v1->colorV > v2->colorV)
        return 1;
    else if (v1->colorV == v2->colorV)
        return 0;
    else
        return -1;
}
int DecreCompColores(const void * x, const void * y) {
    VerticeSt v1 = *(VerticeSt*) x;
    VerticeSt v2 = *(VerticeSt*) y;
    
    if(v1->colorV < v2->colorV)
        return 1;
    else if(v1->colorV == v2->colorV)
        return 0;
    else
        return -1;
}
// Ordena los vertices en orden creciente de sus "nombres" reales
void OrdenNatural(NimheP G) {

	qsort(G->hashList->orden, G->cantVertices, sizeof(VerticeSt), CrecienteCompNombre);
}

/*Ordena los vertices de G de acuerdo con el orden Welsh-Powell, es decir,
 * con los grados en orden no creciente. */
void OrdenWelshPowell(NimheP G) {
    qsort(G->hashList->orden, G->cantVertices, sizeof(VerticeSt), CompWelshPowell);
}


/*
 * Si G esta coloreado con r colores y W1 sno los vertices coloreados con 1,
 * W2 los con 2, etc. Se ordena poniendo primero los vertices de Wj1(en algun orden)
 * luego los de Wj2 etc, donde j1,j2,..,etc son aleatorios distintos
 */
void ReordenAleatorioRestringido(NimheP G) {
    u32 seed = time(NULL);
    srand(seed);
    u32 i = 0;
    random = rand() % G->cantcolor + 1;

    bool available[G->cantcolor + 1];
    memset(available, true, (G->cantcolor + 1)*sizeof(bool));

    u32 CantVerticesDeColor = NumeroVerticesDeColor(G, random);
    qsort(G->hashList->orden, G->cantVertices, sizeof(VerticeSt), CompReordenAleatorio);
    available[random] = false;

    while(i < G->cantcolor - 1) {
        random = rand() % G->cantcolor + 1;
        if(available[random]) {
            qsort(G->hashList->orden + CantVerticesDeColor, G->cantVertices - CantVerticesDeColor, sizeof(VerticeSt), CompReordenAleatorio);
            CantVerticesDeColor = CantVerticesDeColor + NumeroVerticesDeColor(G, random);
            available[random] = false;
            i++;
        }
    }
}


 /* Si G esta coloreado con r colores y W1 sno los vertices coloreados con 1,
 * W2 los con 2, etc. Se ordena poniendo primero los vertices de Wj1(en algun orden)
 * luego los de Wj2 etc, donde j1,j2,..,etc son tales que |Wj1| >= |Wj2| >= ... >= |Wjr|
 */
void GrandeChico(NimheP G) {
     u32 VerticesDeColor[G->cantcolor + 1];
     memset(VerticesDeColor, 0, (G->cantcolor + 1)*sizeof(u32));
     u32 color;
     for(u32 i = 0; i < G->cantVertices; i++) {
         color = G->hashList->vertices[i]->colorV;
         VerticesDeColor[color]++;
     }
     // Funcion de comparacion para Grande Chico
     int CompDecreciente(const void * x, const void * y) {
        VerticeSt v1 = *(VerticeSt*) x;
        VerticeSt v2 = *(VerticeSt*) y;

         if(VerticesDeColor[v1->colorV] > VerticesDeColor[v2->colorV])
            return -1;
        else if (VerticesDeColor[v1->colorV] == VerticesDeColor[v2->colorV])
             if(v1->colorV == v2->colorV)
                return 0;
             else {
                 if(v1->colorV > v2->colorV)
                    return -1;
                 else
                     return 1;
             }
        else
            return 1;
    }
     qsort(G->hashList->orden, NumeroDeVertices(G), sizeof(VerticeSt), CompDecreciente);
 }
// Igual que el anterior pero al reves los ordenes.. |Wj1| <= |Wj2|<= ...
void ChicoGrande(NimheP G) {
     u32 VerticesDeColor[G->cantcolor + 1];
     memset(VerticesDeColor, 0, (G->cantcolor + 1)*sizeof(u32));
     u32 color;
     for(u32 i = 0; i < G->cantVertices; i++) {
         color = G->hashList->vertices[i]->colorV;
         VerticesDeColor[color]++;
     }
     // Funcion de comparacion para Grande Chico
     int CompDecreciente(const void * x, const void * y) {
        VerticeSt v1 = *(VerticeSt*) x;
        VerticeSt v2 = *(VerticeSt*) y;

         if(VerticesDeColor[v1->colorV] < VerticesDeColor[v2->colorV])
            return -1;
        else if (VerticesDeColor[v1->colorV] == VerticesDeColor[v2->colorV])
             if(v1->colorV == v2->colorV)
                return 0;
             else {
                 if(v1->colorV > v2->colorV)
                    return -1;
                 else
                     return 1;
             }
        else
            return 1;
    }
     qsort(G->hashList->orden, NumeroDeVertices(G), sizeof(VerticeSt), CompDecreciente);
}
/*Si G esta coloreado con r colores y W 1 son los vertices coloreados con 1, W 2 los coloreados con 2,
 * etc, entonces esta funcion ordena los vertices poniendo primero los vertices de Wr (en algun orden)
 * luego los de W r−1 (en algun orden), etc. */

void Revierte(NimheP G){
   qsort(G->hashList->orden, G->cantVertices, sizeof(VerticeSt), DecreCompColores); 
}
// Leer el pdf, muy largo.
void OrdenEspecifico(NimheP G, u32 *x);
