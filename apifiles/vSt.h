#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef unsigned int *u32;

struct VerticeSt_t  {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
};

typedef struct VerticeSt_t *VerticeSt;

VerticeSt NuevoVertice(u32 n);
/*
 * Devuelve un nuevo vértice 'n' de color 0 y con grado 0.
 */

u32 ColorDelVertice(VerticeSt x);
/*
 * Devuelve el color del vértice dado.
 */

u32 GradoDelVertice(VerticeSt x);
/*
 * Devuelve el grado del vértice dado.
 */
 
u32 NombreDelVertice(VerticeSt x);
/*
 * Devuelve el nombre del vértice dado.
 */

void CambiarColorA(VerticeSt x, u32 i);
/*
 * Cambia el color del vertice a i
 */
void DestruirVertice(VerticeSt x);


bool VerticesIguales (VerticeSt x, VerticeSt y);
/*
 * Compara la igualdad de ambos vertices.
 */