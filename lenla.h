#include <stdlib.h>

node LenlaVacia(void);
/*
 * Crea una lista enlazada vacía (devuelve un puntero a NULL).
 */

void AgregarVecino(u32 i, node *head);
/*
 * Agrega al vecino i a la lista de adyacencia.
 */

u32 IesimoElem(u32 i, node *head);
/*
 * Devuelve el iesimo elemento de la lista
 */

u32 CantidadElem(node *head);
/*
 * Devuelve la cantidad de elementos de la lista
 */