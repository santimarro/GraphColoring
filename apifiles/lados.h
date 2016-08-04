//
// Created by smarro on 7/29/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "vSt.h"

struct LadoSt_t  {
    VerticeSt x;
    VerticeSt y;
    u32 nombre;
};

typedef struct LadoSt_t *LadoSt;

LadoSt CrearLado(VerticeSt x1, VerticeSt x2);

void DestruirLado(LadoSt l);

VerticeSt ObtenerVerticeX(LadoSt l);

VerticeSt ObtenerVerticeY(LadoSt l);

u32 ObtenerNombre(LadoSt l);

bool CompararLados(LadoSt l1, LadoSt l2);

