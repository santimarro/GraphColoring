#include <stdio.h>
#include <stdlib.h>


struct VerticeSt  {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
};

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

u32 IesimoVecinoPlus(VerticeSt x, i);
/*
 * Devuelve el iesimo vecino del vertice x (No es el que piden en la catedra)
 */
void CambiarColorA(VerticeSt x, i);
/*
 * Cambia el color del vertice a i
 */
void AgregarLado(VerticeSt x, i);
/*
 * Agrega vecino i a x
 */

void DestruirVertice(VerticeSt x);


bool verticesIguales (VerticeSt x, VerticeSt y);
/*
 * Compara la igualdad de ambos vertices.
 */