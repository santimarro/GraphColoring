#include <stdio.h>
#include <stdlib.h>

#include "vSt.h"

typedef unsigned int *u32;

struct VerticeSt  {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
};

VerticeSt NuevoVertice(u32 n) {
    VerticeSt v;
    v.nombreV = n;
    v.gradoV = 0;
    v.colorV = 0;
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

void CambiaColorA(VerticeSt x, u32 i) {
    x.colorV = i;
}

bool VerticesIguales (VerticeSt x, VerticeSt y) {
    if (x.nombreV == y.nombreV)
        return true;
    else
        return false;
}


void DestruirVertice(VerticeSt x) {
    free(x);
}