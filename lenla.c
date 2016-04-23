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
    nodo->vecino = i;
    nodo->next = NULL;
    node *curr = head;
    while(curr->next != NULL) {
        if(curr->next == NULL) {
            curr->next = nodo;
        }    
    }
    curr = NULL;    
}
