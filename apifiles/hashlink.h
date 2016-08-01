//
// Created by ophion on 23/06/16.
//
#include <math.h>
#include "lados.h"


struct hashList {
    u32 *heads;
    LadoSt *data;
    bool *used;
    u32 *next;
    u32 size;
};

hashList HashNuevaHash(u32 n, u32 m);
/*
 * Crea una hashList donde n es la cantidad de vertices.
 */

boolean HashAgregar(VerticeSt x, VerticeSt y, hashList h);
/*
 * Agrega una arista a la hashlist, donde x e y son los vertices unidos por la misma.
 */

boolean HashContiene(VerticeSt x, VerticeSt y, hashList h);
/*
 * Chequea si la hashlist contiene o no determinada arista (x,y).
 */

void HashEnumerar(VerticeSt x, hashList h);
/*
 * Enumera los vertices vecinos de x
 */

u32 hash(VerticeSt x, VerticeSt y);
/*
 * Genera el hash para determinada arista a agregar
 */


void DestruirHashList (hashList h);