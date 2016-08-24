//
// Created by smarro on 7/29/16.
//
#include "lados.h"

/*LadoSt CrearLado(VerticeP x1, VerticeP x2) {
    LadoSt l = malloc(1*sizeof(struct LadoSt_t));
    l->x = x1;
    l->y = x2;
    return l;
}
void DestruirLado(struct LadoSt l) {
    free(l);
}*/

VerticeP ObtenerVerticeX(struct LadoSt l) {
    return l.x;
}

VerticeP ObtenerVerticeY(struct LadoSt l) {
    return l.y;
}

bool CompararLados(struct LadoSt l1, struct LadoSt l2) {
    if(l1.x->nombreV == l2.x->nombreV || l1.x->nombreV == l2.y->nombreV) {
        if (l1.y->nombreV == l2.y->nombreV || l1.y->nombreV == l2.x->nombreV)
            return true;
    }
    return false;
}

