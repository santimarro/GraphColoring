#include "vSt.h"


VerticeP NuevoVertice(u32 n) {
    VerticeP v = malloc(sizeof(struct VerticeSt));
    v->nombreV = n;
    v->gradoV = 0;
    v->colorV = 0;
    return(v);
}

u32 ColorDelVertice(struct VerticeSt x) {
    return(x.colorV);
}

u32 GradoDelVertice(struct VerticeSt x) {
    return(x.gradoV);
}

u32 NombreDelVertice(struct VerticeSt x) {
    return(x.nombreV);
}

void CambiaColorA(struct VerticeSt x, u32 i) {
    x.colorV = i;
}

bool VerticesIguales (VerticeP x, VerticeP y) {
    if (x->nombreV == y->nombreV)
        return true;
    else
        return false;
}


void DestruirVertice(VerticeP x) {
    free(x);
}