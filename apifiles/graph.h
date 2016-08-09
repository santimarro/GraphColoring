#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hashlink.h"

typedef unsigned int u32;

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    hashList hashList;
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

struct VerticeSt_t IesimoVerticeEnElOrden(NimheP G, u32 i);

struct VerticeSt_t IesimoVecino(NimheP G, struct VerticeSt_t x, u32 i);