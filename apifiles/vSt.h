#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef unsigned int u32;

struct VerticeSt {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
    u32 hashV;
};

typedef struct VerticeSt *VerticeP;

VerticeP NuevoVertice(u32 n);
/*
 * Devuelve un nuevo vértice 'n' de color 0 y con grado 0.
 */

u32 ColorDelVertice(struct VerticeSt x);
/*
 * Devuelve el color del vértice dado.
 */

u32 GradoDelVertice(struct VerticeSt x);
/*
 * Devuelve el grado del vértice dado.
 */
 
u32 NombreDelVertice(struct VerticeSt x);
/*
 * Devuelve el nombre del vértice dado.
 */

void CambiarColorA(struct VerticeSt x, u32 i);
/*
 * Cambia el color del vertice a i
 */
void DestruirVertice(VerticeP x);


bool VerticesIguales (VerticeP x, VerticeP y);
/*
 * Compara la igualdad de ambos vertices.
 */