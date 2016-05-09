#include <stdlib.h>
#include "lenla.h"

typedef unsigned int *u32;

typedef struct node {
  u32 vecino;         
  struct node *next;
};

node LenlaVacia(void) {
    lenla le = NULL;     // Devuelve una lista vacia (NULL).
    return(le);
}

void AgregarVecino(u32 i, node *head) {
    node nodo;
    vecino = malloc(sizeof(*node));
    nodo->vecino = i;       // El vecino dado.
    nodo->next = NULL;      // Lo agrega al final.
    node *curr = head;
    while(curr->next != NULL) {
        if(curr->next == NULL) {
            curr->next = nodo;
        }    
    }
    curr = NULL;
}

u32 IesimoElem(u32 i, node *head) {
    u32 indice = 0;
    nodo *curr = head;
    while(curr->next != NULL && indice < i) {
        i += 1;
    }
    return (i);
}

u32 CantidadElem(node *head) {
    u32 i = 0;
    nodo *curr = head;
    while(curr->next != NULL) {
        i += 1;
    }
    return (i);
}
