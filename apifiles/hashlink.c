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

    h->nvertices = n;
    h->aristas = 2*m;
    return h;
}

// adds new edge (x, y)
bool HashAgregar(u32 z, u32 w, hashList h) {
    VerticeSt x = NULL;
    VerticeSt y = NULL;
    u32 id_z = HashNombre(z, h);
    u32 id_w = HashNombre(w, h);


    while (h->vertices[id_z]) {
        if (h->vertices[id_z]->nombreV == z) {
            x = h->vertices[id_z];
            break;
        }
        else
            id_z = (id_z + 1) % h->nvertices;
    }
    if(h->vertices[id_z] == NULL) {
        h->vertices[id_z] = NuevoVertice(z);
        x = h->vertices[id_z];
    }

    while (h->vertices[id_w]) {
        if (h->vertices[id_w]->nombreV == w) {
            y = h->vertices[id_w];
            break;
        }
        else
            id_w = (id_w + 1) % h->nvertices;
    }

    if(h->vertices[id_w] == NULL) {
        h->vertices[id_w] = NuevoVertice(w);
        y = h->vertices[id_w];
    }
    x->hashV = id_z;
    y->hashV = id_w;

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
                hash = (hash + 1) % h->aristas;
        }
        else {
            hash = (hash + 1) % h->aristas;
        }
    }
    h->data[hash] = l;
    h->used[hash] = true;
    h->next[hash] = h->heads[id_z];

    h->heads[id_z] = hash;


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
            hashX = (hashX + 1) % h->aristas;
        }
    }
    while (h->used[hashY]) {
        if (CompararLados(h->data[hashY], l)) {
            return true;
        }
        else {
            hashY = (hashY + 1) % h->aristas;
        }
    }
    return false;
}

// enumerates the vertices adjacent to x
void HashEnumerar(VerticeSt x, hashList h) {

    for (int i = h->heads[x->hashV]; i != -1; i = h->next[i]) {
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
    int i = h->heads[x->hashV];
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
    u32 i = (u32) (x + 111111) * (y - 333333) % h->aristas;
    return i;
}


u32 HashNombre(u32 x, hashList h) {
    u32 hash = x % h->nvertices;
    return hash;
}

void DestruirHashList (hashList h) {
    for (u32 i = 0; i > h->aristas; i++) {
        DestruirLado(h->data[i]);
    }
    free(h->heads);
    free(h->data);
    free(h->next);
    free(h->used);
    free(h);
}