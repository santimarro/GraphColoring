//
// Created by smarro on 7/29/16.
//
#include "lados.h"

LadoSt crearLado(VerticeSt x1, VerticeSt x2) {
    LadoSt l;
    l.x = x1;
    l.y = x2;
}
void destruirLado(LadoSt l) {
    free(l);
}

VerticeSt obtenerVerticeX(LadoSt l) {
    return l.x;
}

VerticeSt obtenerVerticeY(LadoSt l) {
    return l.y;
}

u32 obtenerNombre(LadoSt l) {
    return l.nombre;
}

void cambiarNombre(LadoSt l, u32 x) {
    l.nombre = x;
}
