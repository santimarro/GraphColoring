#include "hashlink.h"


// n number of vertices
hashList HashNuevaHash(u32 n, u32 m) {

    hashList h;
    h = malloc(1*sizeof(struct hashList_t));

    h->heads = malloc(n*sizeof(int));
    memset(h->heads, -1, n*sizeof(int));

    h->used = calloc(m, sizeof(bool));
    h->data = calloc(m, sizeof(struct LadoSt_t));
    h->next = calloc(m, sizeof(int));

    h->vertices = malloc((int) n*sizeof(VerticeSt));
    h->orden = malloc((int) n*sizeof(VerticeSt));
    memset(h->vertices, 0, sizeof(VerticeSt));
    memset(h->orden, 0, sizeof(VerticeSt));

    h->size = n;
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
    x->gradoV++;
    y->gradoV++;
    u32 hashX = HashCode(z, w, h);
    u32 hashY = HashCode(w, z, h);

    while (h->used[hashX]) {
        if (CompararLados(h->data[hashX], l)) {
            return false;
        }
        else {
            hashX = (hashX + 1) % h->size;
        }
    }
    h->data[hashX] = l;
    h->used[hashX] = true;
    h->next[hashX] = h->heads[x->nombreV];

    h->heads[x->nombreV] = hashX;

    h->next[hashY] = h->heads[y->nombreV];
    h->heads[y->nombreV] = hashY;



    return true;
}
// returns true if edge (x, y) is contained in the graph

/*bool HashContiene(u32 x, u32 y, hashList h) {
    u32 hash = HashCode(x, y, h);
    LadoSt l = CrearLado()
    while (h->used[hash]) {
        if (CompararLados(h->data[hash]) == hash) {
            return true;
        }
        else {
            hash = (hash + 1) % h->size;
        }
    }
    return false;
}*/

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

void HashEnumerarGrafo(hashList h) {

    for(u32 j = 0; j < h->size; j++ ) {
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