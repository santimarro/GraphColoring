#include "hashlink.h"


// n number of vertices
hashList HashNuevaHash(u32 n, u32 m) {
    hashList h;
    h = malloc(1*sizeof(struct hashList_t));
    h->heads = malloc((int) n*sizeof(int));
    memset(h->heads, -1, sizeof(int));

    h->used = calloc(m, sizeof(bool));
    h->data = calloc(m, sizeof(struct LadoSt_t));
    h->next = calloc(m, sizeof(int));
    h->orden = malloc((int) n*sizeof(struct VerticeSt_t));
    memset(h->orden, -1, sizeof(struct VerticeSt_t));

    h->size = n;
    return h;
}

// adds new edge (x, y)
bool HashAgregar(u32 z, u32 w, hashList h) {
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
    x->gradoV++;
    y->gradoV++;
    u32 hash = HashCode(NombreDelVertice(x), NombreDelVertice(y), h);

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

bool HashContiene(VerticeSt x, VerticeSt y, hashList h) {
    u32 hash = HashCode(NombreDelVertice(x), NombreDelVertice(y), h);
    while (h->used[hash]) {
        if (ObtenerNombre(h->data[hash]) == hash) {
            return true;
        }
        else {
            hash = (hash + 1) % h->size;
        }
    }
    return false;
}

// enumerates the vertices adjacent to x
void HashEnumerar(VerticeSt x, hashList h) {

    for (int i = h->heads[NombreDelVertice(x)]; i != -1; i = h->next[i]) {
        if(VerticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            printf("%d", NombreDelVertice(ObtenerVerticeY(h->data[i])));
        }
        else
            printf("%d", NombreDelVertice(ObtenerVerticeX(h->data[i])));
        if (h->next[i] != -1)
            printf(",");
    }
    printf(".");

}
/*
u32 HashIesimoVecino(VerticeSt x, u32 z, hashList h) {
    for (u32 i = h->heads[x->nombreV]; i != -1; i = h->next[i]) {
        if(verticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            printf("%d", ObtenerVerticeY(h->data[i])->nombreV);
        }
        else
            printf("%d", ObtenerVerticeX(h->data[i])->nombreV);
        if (h->next[i] != -1)

}
*/

// returns hash code for edge (x, y)
u32 HashCode(u32 x, u32 y, hashList h) {
    return fabs((x + 111111) * (y - 333333) % h->size);
}

/*
int HashNombre(u32 x) {
    return (int) x;
}*/

void DestruirHashList (hashList h) {
    for (u32 i = 0; i>h->size; i++) {
        DestruirLado(h->data[i]);
    }
    free(h->heads);
    free(h->data);
    free(h->next);
    free(h->used);
    free(h);
}