//
// Created by ophion on 23/06/16.
//
#include <math.h>
#include "lados.h"

u32 SIZE = 1000000;

hashList newhashList(u32 n);
/*
 * Crea una hashList donde n es la cantidad de vertices.
 */

boolean add(u32 x, u32 y);
/*
 * Agrega una arista a la hashlist, donde x e y son los vertices unidos por la misma.
 */

boolean contains(u32 x, u32 y);
/*
 * Chequea si la hashlist contiene o no determinada arista (x,y).
 */

void enumerate(u32 x);
/*
 * Enumera los vertices vecinos de x
 */

u32 hash_search(u32 x, hashList h):
/*
 * Returns the element un hashList
 */

u32 hash(u32 x, u32 y);
/*
 * Genera el hash para determinada arista a agregar
 */

u32 code(u32 x, u32 y);
/*
 * Convierte el par de vecinos (x,y) a un solo valor u32
 */