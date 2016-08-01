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

LadoSt CrearLado(VerticeSt x1, VerticeSt x2);

void DestruirLado(LadoSt l);

VerticeSt ObtenerVerticeX(LadoSt l);

VerticeSt ObtenerVerticeY(LadoSt l);

u32 ObtenerNombre(LadoSt l);

