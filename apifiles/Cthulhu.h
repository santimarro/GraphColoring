#ifndef CTHULHU_H_
#define CTHULHU_H_

#define MAX_SIZE    25        // Define maximum length of the queue
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Nimhe.h"
#include <time.h>

typedef unsigned int u32;

typedef struct VerticeSt *VerticeP;

struct VerticeSt {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
    u32 hashV;
    u32 capacidad;
    VerticeP *vecinos;
};

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    struct VerticeSt *vertices;
    VerticeP *orden;
    bool *vertices_usados;
    VerticeP *orden_natural;
};

typedef struct NimheSt *NimheP;

// Funciones del grafo
NimheP NuevoNimhe();

int DestruirNimhe(NimheP G);

VerticeP AgregarLado(NimheP G, u32 z);

// Funciones de los vértices
u32 ColorDelVertice(struct VerticeSt x);

u32 GradoDelVertice(struct VerticeSt x);

u32 NombreDelVertice(struct VerticeSt x);

struct VerticeSt NuevoVertice(u32 n);

void AgregarVecino(VerticeP x, VerticeP y);

void DestruirVertice(struct VerticeSt x);

void ImprimirVecinosDelVertice(struct VerticeSt x, NimheP G);


// Funciones para extraer información de datos del grafo
u32 NumeroDeVertices(NimheP G);

u32 NumeroDeLados(NimheP G);

u32 NumeroVerticesDeColor(NimheP G, u32 i);

u32 ImprimirVerticesDeColor(NimheP G, u32 i);

u32 CantidadDeColores(NimheP G);

struct VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i);

struct VerticeSt IesimoVecino(NimheP G, struct VerticeSt x, u32 i);


// Funciones de coloreo
int Chidos(NimheP G);

u32 Greedy(NimheP G);

// Funciones de ordenación
void OrdenNatural(NimheP G);

void OrdenWelshPowell(NimheP G);

void ReordenAleatorioRestringido(NimheP G);

void GrandeChico(NimheP G);

void ChicoGrande(NimheP G);

void Revierte(NimheP G);

void OrdenEspecifico(NimheP G, u32* x);


// List Function Prototypes
struct QueueSt {
    int head;
    int tail;
    VerticeP *theQueue;
};

struct QueueSt CrearQueue(u32 size);                        // Initialize the queue
void DestruirQueue(struct QueueSt q);       // Remove all items from the queue
void Enqueue(struct QueueSt q, VerticeP v); // Enter an item in the queue
VerticeP Dequeue(struct QueueSt q);         // Remove an item from the queue
u32 isEmpty(struct QueueSt q);             // Return true if queue is empty

#endif  // CTHULHU_H_
