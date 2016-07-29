//
// Created by smarro on 7/29/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "vSt.h"


struct LadoSt  {
    VerticeSt x;
    VerticeSt y;
    u32 nombre;
};

LadoSt crearLado(VerticeSt x1, VerticeSt x2);

void destruirLado(LadoSt l);

VerticeSt obtenerVerticeX(LadoSt l);

VerticeSt obtenerVerticeY(LadoSt l);

u32 obtenerNombre(LadoSt l);

