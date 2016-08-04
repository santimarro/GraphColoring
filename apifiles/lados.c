//
// Created by smarro on 7/29/16.
//
#include "lados.h"

LadoSt CrearLado(VerticeSt x1, VerticeSt x2) {
    LadoSt l = malloc(sizeof(struct LadoSt_t));
    l->x = x1;
    l->y = x2;
    return l;
}
void DestruirLado(LadoSt l) {
    DestruirVertice(l->x);
    DestruirVertice(l->y);
    free(l);
}

VerticeSt ObtenerVerticeX(LadoSt l) {
    return l->x;
}

VerticeSt ObtenerVerticeY(LadoSt l) {
    return l->y;
}

u32 ObtenerNombre(LadoSt l) {
    return l->nombre;
}

void CambiarNombre(LadoSt l, u32 x) {
    l->nombre = x;
}

bool CompararLados(LadoSt l1, LadoSt l2) {
    if(l1->x->nombreV == l2->x->nombreV) {
        if (l1->y->nombreV == l2->y->nombreV)
            return true;
    }
    return false;
}

