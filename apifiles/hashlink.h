//
// Created by ophion on 23/06/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "lados.h"

typedef unsigned int u32;

struct hashList_t {
    int *heads;
    int *next;
    u32 size;
    bool *used;
    LadoSt *data;
    VerticeSt *vertices; // Arreglo de VerticeP en el orden original
    VerticeSt *orden;   // Arreglo de VerticeP ordenados segun qsort.
};

typedef struct hashList_t *hashList;

hashList HashNuevaHash(u32 n, u32 m);
/*
 * Crea una hashList donde n es la cantidad de vertices.
 */

bool HashAgregar(u32 x, u32 y, hashList h);
/*
 * Agrega una arista a la hashlist, donde x e y son los vertices unidos por la misma.
 */

bool HashContiene(VerticeSt x, VerticeSt y, hashList h);
/*
 * Chequea si la hashlist contiene o no determinada arista (x,y).
 */

void HashEnumerar(VerticeSt x, hashList h);
/*
 * Enumera los vertices vecinos de x
 */

u32 HashCode(u32 x, u32 y, hashList h);
/*
 * Genera el hash para determinada arista a agregar
 */

//u32 HashNombre(u32 x);


void HashEnumerarGrafo(hashList h, u32 n);


VerticeSt HashIesimoVecino(VerticeSt x, u32 z, hashList h);

void DestruirHashList (hashList h);