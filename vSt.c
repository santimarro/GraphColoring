#include <stdio.h>
#include <stdlib.h>

#include "lenla.h"
#include "vSt.h"

typedef unsigned int *u32;

struct VerticeSt  {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
    lenla *vecinosV;
};

VerticeSt NuevoVertice(u32 n) {
    VerticeSt v;
    // Borré la linea del malloc porque ya se inicializan todos los vértices en graph.c .
    v.nombreV = n;
    v.gradoV = 0;
    v.colorV = 0;
    v->vecinosV = lenlaVacia();
    return(v);
}

u32 ColorDelVertice(VerticeSt x) {
    return(x.colorV);
}

u32 GradoDelVertice(VerticeSt x) {
    return(x.gradoV);
}

u32 NombreDelVertice(VerticeSt x) {
    return(x.nombreV);
}

u32 IesimoVecinoPlus(i, VerticeSt x) {
    return(IesimoElem(x->vecinosV, i));
}

void CambiaColorA(VerticeSt x, i) {
    x.colorV = i;
}
void AgregarLado(VerticeSt x, i) {
    AgregarVecino(i ,x->vecinosV);
    x.gradoV++;
}

void ImprimirVecinosDelVertice(VerticeSt x, NimheP G) {
    curr = x->vecinosV;
    printf("Los vecinos de %d son: \n", x);
    for(curr; curr != NULL; curr = curr->next) {
        printf("%d ", curr->vecino);
    } // Ubicar esta función donde corresponda (ver los inputs para darse cuenta!)
    printf("\n");
}



