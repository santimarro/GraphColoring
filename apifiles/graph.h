#include <stdio.h>
#include <stdlib.h>

#include "vSt.h"
#include "hashlink.h"

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    hashLink hashLink;
    u32 *PrimerOrden;
    /*
     * u32 *PrimerOrden;       // Tengo dudas aca si deberia ser una lista
     * u32 *SegundoOrden;                                  //^ es de esto!
     * VerticeSt *vertices;    // Array de vértices.
    */
};

NimheP NuevoNimhe();

int DestruirNimhe(NimheP G);
/*
 * Destruye G y libera la memoria alocada.
 * Retorna 1 si todo anduvo bien y 0 si no.
 */

u32 NumeroDeVertices(NimheP G);

u32 NumeroDeLados(NimheP G);

u32 NumeroVerticesDeColor(NimheP G, u32 i);

u32 ImprimirVerticesDeColor(NimheP G, u32 i);

u32 CantidadDeColores(NimheP G);

VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i);

VerticeSt IesimoVecino(Nimhep G, VerticeSt x, u32 i);