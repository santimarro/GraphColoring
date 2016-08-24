//
// Created by smarro on 7/29/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "vSt.h"

struct LadoSt  {
    VerticeP x;
    VerticeP y;
};

typedef struct LadoSt *LadoSt;

LadoSt CrearLado(VerticeP x1, VerticeP x2);

void DestruirLado(LadoSt l);

VerticeP ObtenerVerticeX(struct LadoSt l);

VerticeP ObtenerVerticeY(struct LadoSt l);

bool CompararLados(struct LadoSt l1, struct LadoSt l2);

