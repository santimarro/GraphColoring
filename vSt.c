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
    v = malloc(1*(sizeof(struct VerticeSt)));
    v->nombreV = n;
    v->gradoV = 0;
    v->colorV = 0;
    v->lenla = lenlaVacia();
    return(v);
}

u32 ColorDelVertice(VerticeSt x) {
    return(x->colorV);
}

u32 GradoDelVertice(VerticeSt x) {
    return(x->gradoV);
}

u32 NombreDelVertice(VerticeSt x) {
    return(x->nombreV);
}

/*void ImprimirVecinosDelVertice(VerticeSt x,NimheP G) {
        curr = x->vecinosV;
        printf("Los vecinos de %d son: \n", x);
        for(curr; curr != NULL; curr = curr->next) {
            printf("%d ", curr->vecino);
        } // Ubicar esta función donde corresponda (ver los inputs para darse cuenta!)
        printf("\n");
}*/



