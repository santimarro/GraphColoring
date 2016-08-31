#include "vSt.h"


struct VerticeSt NuevoVertice(u32 n, u32 id) {
    struct VerticeSt x;
	x.nombreV = n;
	x.colorV = 0;
	x.gradoV = 0;
	x.hashV = id;
    x.capacidad = 5;
	x.vecinos = malloc((x.capacidad)*sizeof(VerticeP));
    return(x);
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
    return;
}

bool VerticesIguales (VerticeP x, VerticeP y) {
    if (x->nombreV == y->nombreV)
        return true;
    else
        return false;
}

void AgregarVecino(VerticeP x, VerticeP y) {
    u32 grado = x->gradoV;
    if(grado == x->capacidad) {

		VerticeP *vecinos;
        vecinos = realloc(x->vecinos, (x->capacidad + 5)*sizeof(VerticeP));
        x->capacidad += 5;
		x->vecinos = vecinos;
        
        //realloc de x->vecinos dandole 5 lugares más.
    }
    x->vecinos[x->gradoV] = y;
    x->gradoV++;
}


void DestruirVertice(VerticeP x) {
	free(x->vecinos);
    free(x);
}
