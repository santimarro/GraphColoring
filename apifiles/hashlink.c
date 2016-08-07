#include "hashlink.h"


// n number of vertices
hashList HashNuevaHash(u32 n, u32 m) {

    hashList h;
    h = malloc(1*sizeof(struct hashList_t));

    h->heads = malloc(n*sizeof(int));
    memset(h->heads, -1, n*sizeof(int));

    h->used = calloc(2*m, sizeof(bool));
    h->data = calloc(2*m, sizeof(struct LadoSt_t));
    h->next = calloc(2*m, sizeof(int));

    h->vertices = malloc((int) n*sizeof(VerticeSt));
    h->orden = malloc((int) n*sizeof(VerticeSt));
    memset(h->vertices, 0, n*sizeof(VerticeSt));
    memset(h->orden, 0, n*sizeof(VerticeSt));

    h->size = 2*m;
    return h;
}

// adds new edge (x, y)
bool HashAgregar(u32 z, u32 w, hashList h) {
    VerticeSt x = NULL;
    VerticeSt y = NULL;

    if(h->orden[z] == 0) {
        h->vertices[z] = NuevoVertice(z);
        h->orden[z] = h->vertices[z];
        x = h->vertices[z];
    }
    else {
        x = h->vertices[z];
    }

   if(h->orden[w] == 0) {
       h->vertices[w] = NuevoVertice(w);
       h->orden[w] = h->vertices[w];
       y = h->vertices[w];
    }
    else {
        y = h->vertices[w];
    }


    LadoSt l = CrearLado(x, y);

    if(!HashContiene(x, y, h)) {
        y->gradoV++;
        x->gradoV++;
    }

    u32 hash = HashCode(z, w, h);

    while (h->used[hash]) {
        if (CompararLados(h->data[hash], l)) {
            if(h->data[hash]->x->nombreV == x->nombreV)
                return false;
            else
                hash = (hash + 1) % h->size;
        }
        else {
            hash = (hash + 1) % h->size;
        }
    }
    h->data[hash] = l;
    h->used[hash] = true;
    h->next[hash] = h->heads[x->nombreV];

    h->heads[x->nombreV] = hash;


    return true;
}
// returns true if edge (x, y) is contained in the graph

bool HashContiene(VerticeSt x, VerticeSt y, hashList h) {
    u32 hashX = HashCode(x->nombreV, y->nombreV, h);
    u32 hashY = HashCode(y->nombreV, x->nombreV, h);
    LadoSt l = CrearLado(x, y);
    while (h->used[hashX]) {
        if (CompararLados(h->data[hashX], l)) {
            return true;
        }
        else {
            hashX = (hashX + 1) % h->size;
        }
    }
    while (h->used[hashY]) {
        if (CompararLados(h->data[hashY], l)) {
            return true;
        }
        else {
            hashY = (hashY + 1) % h->size;
        }
    }
    return false;
}

// enumerates the vertices adjacent to x
void HashEnumerar(VerticeSt x, hashList h) {

    for (int i = h->heads[NombreDelVertice(x)]; i != -1; i = h->next[i]) {
        if(VerticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            //Comparacion para sacar el Vertice contrario.
            printf("%d", NombreDelVertice(ObtenerVerticeY(h->data[i])));
        }
        else
            printf("%d", NombreDelVertice(ObtenerVerticeX(h->data[i])));
        if (h->next[i] != -1)
            printf(",");
    }
    printf(".");

}

void HashEnumerarGrafo(hashList h, u32 n) {

    for(u32 j = 0; j < n; j++ ) {
        printf("%d: ",j);
        for (int i = h->heads[j]; i != -1; i = h->next[i]) {
            if(j == ObtenerVerticeX(h->data[i])->nombreV)
                printf("%d", NombreDelVertice(ObtenerVerticeY(h->data[i])));
            else
                printf("%d", NombreDelVertice(ObtenerVerticeX(h->data[i])));
            if (h->next[i] != -1)
                printf(",");
        }
        printf(".\n");
    }
}

VerticeSt HashIesimoVecino(VerticeSt x, u32 z, hashList h) {
    int i = h->heads[x->nombreV];
    u32 j = 0;

    for (;i != -1 && j < z; i = h->next[i])
        j++;

    if(VerticesIguales(x, ObtenerVerticeX(h->data[i]))) {
        return ObtenerVerticeY(h->data[i]);
    }
    else
        return ObtenerVerticeX(h->data[i]);
}

// returns hash code for edge (x, y)
u32 HashCode(u32 x, u32 y, hashList h) {
    u32 i = (u32) (x + 111111) * (y - 333333) % h->size;
    return i;
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