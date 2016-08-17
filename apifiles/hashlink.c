#include "hashlink.h"


// n number of vertices
hashList HashNuevaHash(u32 n, u32 m) {

    hashList h;
    h = malloc(1*sizeof(struct hashList_t));

    h->heads_ida = malloc(n*sizeof(int));
    h->heads_vuelta = malloc(n*sizeof(int));

    memset(h->heads_ida, -1, n*sizeof(int));
    memset(h->heads_vuelta, -1, n*sizeof(int));

    h->used = calloc(m, sizeof(bool));
    h->data = calloc(m, sizeof(LadoSt));

    h->next_ida = calloc(m, sizeof(int));
    h->next_vuelta = calloc(m, sizeof(int));

    h->vertices = malloc((int) n*sizeof(VerticeSt));
    h->orden = malloc((int) n*sizeof(VerticeSt));
    memset(h->vertices, 0, n*sizeof(VerticeSt));
    memset(h->orden, 0, n*sizeof(VerticeSt));

    h->nvertices = n;
    h->aristas = m;
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

    x->gradoV++;
    y->gradoV++;

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
    h->next_ida[hash] = h->heads_ida[id_z];
    h->heads_ida[id_z] = hash;

    h->next_vuelta[hash] = h->heads_vuelta[id_w];
    h->heads_vuelta[id_w] = hash;


    return true;
}

// enumerates the vertices adjacent to x
void HashEnumerar(VerticeSt x, hashList h) {

    for (int i = h->heads_ida[x->hashV]; i != -1; i = h->next_ida[i]) {
        if(VerticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            //Comparacion para sacar el Vertice contrario.
            printf("%d", NombreDelVertice(ObtenerVerticeY(h->data[i])));
        }
        else
            printf("%d", NombreDelVertice(ObtenerVerticeX(h->data[i])));
        if (h->next_ida[i] != -1)
            printf(",");
    }

    for (int i = h->heads_vuelta[x->hashV]; i != -1; i = h->next_vuelta[i]) {
        if(VerticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            //Comparacion para sacar el Vertice contrario.
            printf("%d", NombreDelVertice(ObtenerVerticeY(h->data[i])));
        }
        else
            printf("%d", NombreDelVertice(ObtenerVerticeX(h->data[i])));
        if (h->next_vuelta[i] != -1)
            printf(",");
    }
    printf(".");

}

void HashEnumerarGrafo(hashList h, u32 n) {

    for(u32 j = 0; j < n; j++ ) {
        printf("%d: ",j);
        for (int i = h->heads_ida[j]; i != -1; i = h->next_ida[i]) {
            if(j == ObtenerVerticeX(h->data[i])->nombreV)
                printf("%d", NombreDelVertice(ObtenerVerticeY(h->data[i])));
            else
                printf("%d", NombreDelVertice(ObtenerVerticeX(h->data[i])));
            if (h->next_ida[i] != -1)
                printf(",");
        }

        for (int i = h->heads_vuelta[j]; i != -1; i = h->next_vuelta[i]) {
            if(j == ObtenerVerticeX(h->data[i])->nombreV)
                printf("%d", NombreDelVertice(ObtenerVerticeY(h->data[i])));
            else
                printf("%d", NombreDelVertice(ObtenerVerticeX(h->data[i])));
            if (h->next_vuelta[i] != -1)
                printf(",");
        }
        printf(".\n");
    }
}

VerticeSt HashIesimoVecino(VerticeSt x, u32 z, hashList h) {

    int i = h->heads_ida[x->hashV];
    u32 j = 0; // Variable para contar

    for (;i != -1 && j < z; i = h->next_ida[i])
        j++;

    if(j < z || i == -1) {
        i = h->heads_vuelta[x->hashV];
        for (;i != -1 && j < z; i = h->next_vuelta[i])
            j++;
    }

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
    for (u32 i = 0; i < h->aristas; i++) {
        DestruirLado(h->data[i]);
    }

    for (u32 i = 0; i < h->nvertices; i++) {
        DestruirVertice(h->vertices[i]);
    }
    free(h->heads_ida);
    free(h->heads_vuelta);
    free(h->data);
    free(h->next_ida);
    free(h->next_vuelta);
    free(h->used);
    free(h->vertices);
    free(h->orden);
    free(h);
}