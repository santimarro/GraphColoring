#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "vSt.h"

typedef unsigned int u32;

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    struct VerticeSt *vertices;
    //VerticeP *orden;
    bool *vertices_usados;
};

typedef struct NimheSt *NimheP;


NimheP NuevoNimhe();

int DestruirNimhe(NimheP G);
/*
 * Destruye G y libera la memoria alocada.
 * Retorna 1 si todo anduvo bien y 0 si no.
 */


void ImprimirVecinosDelVertice(struct VerticeSt x, NimheP G);

u32 NumeroDeVertices(NimheP G);

u32 NumeroDeLados(NimheP G);

u32 NumeroVerticesDeColor(NimheP G, u32 i);

u32 ImprimirVerticesDeColor(NimheP G, u32 i);

u32 CantidadDeColores(NimheP G);

struct VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i);

struct VerticeSt IesimoVecino(NimheP G, struct VerticeSt x, u32 i);

u32 HashNombre(u32 hash, u32 n);

VerticeP AgregarLado(NimheP G, u32 z);
