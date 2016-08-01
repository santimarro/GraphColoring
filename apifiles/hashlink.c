#include <stdio.h>
#include <stdlib.h>
#include "hashlink.h"

typedef unsigned int *u32;

struct hashList {
    u32 *heads;
    LadoSt *data;
    bool *used;
    u32 *next;
    u32 size;
};

// n number of vertices
hashList HashNuevaHash(u32 n) {
    hashList h;
    h = malloc(1*sizeof(struct hashList));
    u32 heads_[n];
    LadoSt data_[n];
    bool used_[n];
    h.data = &data_;
    h.used = &used_;
    h.next = &next_;
    memset(heads_, -1, sizeof(u32));
    memset(used_, 0, sizeof(bool));
    memset(next_, 0, sizeof(u32));
    memset(data_, NULL, sizeof(LadoSt));
    h.heads = &heads_;
    h.size = n;
}

// adds new edge (x, y)
boolean HashAgregar(VerticeSt x, VerticeSt y, hashList h) {
    LadoSt l = CrearLado(x, y);
    u32 hash = hash(x.nombreV, y.nombreV);

    while (h.used[hash]) {
        if (ObtenerNombre(h.data[hash]) == hash) {
            return false;
        }
        else {
            hash = (hash + 1) % h.size;
        }
    }
    h.data[hash] = l;
    h.used[hash] = true;
    h.next[hash] = h.heads[x.nombreV];

    h.heads[hashelnombre(x)] = hash;

    return true;
}
// returns true if edge (x, y) is contained in the graph

boolean HashContiene(VerticeSt x, VerticeSt y, hashList h) {
    u32 hash = hash(x.nombreV, y.nombreV);
    while (h.used[hash]) {
        if (ObtenerNombre(h.data[hash]) == hash) {
            DestruirLado(lado);
            return true;
        }
        else {
            hash = (hash + 1) % h.size;
            return false;
        }
    }
}

VerticeSt HashSearch(VerticeSt x, VerticeSt y, hashList h) {
    u32 hash = hash(x.nombreV, y.nombreV);
    while (h.used[hash]) {
        if (ObtenerNombre(h.data[hash]) == hash) {
            DestruirLado(lado);
            return true;
        }
        else {
            hash = (hash + 1) % h.size;
            return false;
        }
    }
}


// enumerates the vertices adjacent to x
void HashEnumerar(VerticeSt x, hashList h) {
    for (u32 i = h.heads[x.nombreV]; i != -1; i = h.next[i]) {
        if(verticesIguales(x, ObtenerVerticeX(h.data[i]))) {
            printf("%d", ObtenerVerticeY(h.data[i]).nombreV);
        }
        else
            printf("%d", ObtenerVerticeX(h.data[i]).nombreV);
        if (h.next[i] != -1)
            printf(",");
    }
    printf(".");

}

// returns hash code for edge (x, y)
u32 hash(VerticeSt x, VerticeSt y, hashList h) {
    return fabs((x.nombreV + 111111) * (y.nombreV - 333333) % h.size);
}

u32 hashelnombre(VerticeSt x) {

}
void DestruirHashList (hashList h) {
    for (int i = 0; i>h.size; i++) {
        DestruirLado(h.data[i]);
    }
    free(h.heads);
    free(h.data);
    free(h.next);
    free(h.used);
    free(h.size);
}