#include <stdio.h>
#include <stdlib.h>
#include "hashlink.h"
#include <math.h>
#include "lados.h"

typedef unsigned int *u32;

struct hashList {
    u32 *heads;
    LadoSt *data;
    bool *used;
    u32 *next;
    u32 size;
};

// n number of vertices
hashList newhashList(u32 n) {
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
boolean hash_add(VerticeSt x, VerticeSt y, hashList h) {
    LadoSt l = crearLado(x, y);
    u32 hash = hash(x.nombreV, y.nombreV);

    while (h.used[hash]) {
        if (obtenerNombre(h.data[hash]) == obtenerNombre(l)) {
            return false;
        }
        else {
            hash = (hash + 1) % h.size; //TODO ver SIZE si meterlo en la hashlist
        }
    }
    h.data[hash] = l;
    h.used[hash] = true;
    h.next[hash] = h.heads[x.nombreV];
    h.heads[x.nombreV] = hash;

    return true;
}
// returns true if edge (x, y) is contained in the graph

boolean hash_contains(VerticeSt x, VerticeSt y, hashList h) {
    LadoSt lado = crearLado(x, y);
    u32 hash = hash(x.nombreV, y.nombreV);
    while (h.used[hash]) {
        if (obtenerNombre(h.data[hash]) == obtenerNombre(lado)) {
            destruirLado(lado);
            return true;
        }
        else {
            hash = (hash + 1) % h.size;
            destruirLado(lado);
            return false;
        }
    }
}

/*u32 hash_search(u32 x, hashList h) {
    u32 code = hash_code(x, y);

    u32 hash = hash(x, y);
    while (h.used[hash]) {
        if (h.data[hash] == code) {
            return h.data[hash];
        }
    }
}*/

// enumerates the vertices adjacent to x
void hash_enumerate(VerticeSt x, hashList h) {
    for (u32 i = h.heads[x.nombreV]; i != -1; i = h.next[i]) {
        printf("%d", obtenerNombre(h.data[i]));
        if (h.next[i] != -1)
            printf(",");
    }
    printf(".");

}

// returns hash code for edge (x, y)
u32 hash(VerticeSt x, VerticeSt y) {
    return fabs((x.nombreV + 111111) * (y.nombreV - 333333) % SIZE);
}

void destruirHashList (hashList h) {
    for (int i = 0; i>h.size; i++) {
        destruirLado(h.data[i]);
    }
    free(h.heads);
    free(h.data);
    free(h.next);
    free(h.used);
    free(h.size);
}