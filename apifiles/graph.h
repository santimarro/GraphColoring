#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashlink.h"

typedef unsigned int *u32;

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    hashList hashList;
    u32 *Orden;
};

typedef struct NimheSt *NimheP;


NimheP NuevoNimhe();

int DestruirNimhe(NimheP G);
/*
 * Destruye G y libera la memoria alocada.
 * Retorna 1 si todo anduvo bien y 0 si no.
 */


void ImprimirVecinosDelVertice(VerticeSt x, NimheP G);

u32 NumeroDeVertices(NimheP G);

u32 NumeroDeLados(NimheP G);

u32 NumeroVerticesDeColor(NimheP G, u32 i);

u32 ImprimirVerticesDeColor(NimheP G, u32 i);

u32 CantidadDeColores(NimheP G);

VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i);

VerticeSt IesimoVecino(Nimhep G, VerticeSt x, u32 i);