#include "hashlink.h"


// n number of vertices
hashList HashNuevaHash(u32 n, u32 m) {
    hashList h;
    h = malloc(1*sizeof(struct hashList));
    h->heads = malloc(n*sizeof(int));
    memset(h->heads, -1, sizeof(int));

    h->used = calloc(m, sizeof(bool));
    h->data = calloc(m, sizeof(LadoSt));
    h->next = calloc(m, sizeof(int));
    h->orden = malloc(n*sizeof(struct VerticeSt));
    memset(h->orden, -1, sizeof(struct VerticeSt));

    h->size = n;
}

// adds new edge (x, y)
boolean HashAgregar(u32 z, u32 w, hashList h) {
    VerticeSt x = NULL;
    VerticeSt y = NULL;

    if(h->orden[HashNombre(z)] == -1) {
        h->orden[HashNombre(z)] = NuevoVertice(z);
        x = h->orden[HashNombre(z)];
    }
    else {
        x = h->orden[HashNombre(z)];
    }

   if(h->orden[HashNombre(w)] == -1) {
        h->orden[HashNombre(w)] = NuevoVertice(w);
        y = h->orden[HashNombre(w)];
    }
    else {
        y = h->orden[HashNombre(w)];
    }


    LadoSt l = CrearLado(x, y);
    x.gradoV++;
    y.gradoV++;
    u32 hash = hash(x->nombreV, y->nombreV);

    while (h->used[hash]) {
        if (ObtenerNombre(h->data[hash]) == hash) {
            return false;
        }
        else {
            hash = (hash + 1) % h->size;
        }
    }
    h->data[hash] = l;
    h->used[hash] = true;
    h->next[hash] = h->heads[x->nombreV];

    h->heads[HashNombre(x)] = hash;

    return true;
}
// returns true if edge (x, y) is contained in the graph

boolean HashContiene(VerticeSt x, VerticeSt y, hashList h) {
    u32 hash = hash(x->nombreV, y->nombreV);
    while (h->used[hash]) {
        if (ObtenerNombre(h->data[hash]) == hash) {
            DestruirLado(lado);
            return true;
        }
        else {
            hash = (hash + 1) % h->size;
            return false;
        }
    }
}

VerticeSt HashSearch(VerticeSt x, VerticeSt y, hashList h) {
    u32 hash = hash(x->nombreV, y->nombreV);
    while (h->used[hash]) {
        if (ObtenerNombre(h->data[hash]) == hash) {
            DestruirLado(lado);
            return true;
        }
        else {
            hash = (hash + 1) % h->size;
            return false;
        }
    }
}


// enumerates the vertices adjacent to x
void HashEnumerar(VerticeSt x, hashList h) {
    for (u32 i = h->heads[x->nombreV]; i != -1; i = h->next[i]) {
        if(verticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            printf("%d", ObtenerVerticeY(h->data[i])->nombreV);
        }
        else
            printf("%d", ObtenerVerticeX(h->data[i])->nombreV);
        if (h->next[i] != -1)
            printf(",");
    }
    printf(".");

}

// returns hash code for edge (x, y)
u32 hash(VerticeSt x, VerticeSt y, hashList h) {
    return fabs((x->nombreV + 111111) * (y->nombreV - 333333) % h->size);
}

u32 hashelnombre(VerticeSt x) {

}
void DestruirHashList (hashList h) {
    for (int i = 0; i>h->size; i++) {
        DestruirLado(h->data[i]);
    }
    free(h->heads);
    free(h->data);
    free(h->next);
    free(h->used);
    free(h->size);
}