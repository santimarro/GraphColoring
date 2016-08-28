#include "hashlink.h"


// n number of vertices
hashList HashNuevaHash(u32 n, u32 m) {

    hashList h;
    h = malloc(1*sizeof(struct hashList_t));

    h->heads_ida = malloc(n*sizeof(int));
    h->heads_vuelta = malloc(n*sizeof(int));

    memset(h->heads_ida, -1, n*sizeof(int));
    memset(h->heads_vuelta, -1, n*sizeof(int));
    h->vertices_usados = calloc(n, sizeof(bool));

    h->used = calloc(m, sizeof(bool));
    h->data = calloc(m, sizeof(struct LadoSt));

    h->next_ida = calloc(m, sizeof(int));
    h->next_vuelta = calloc(m, sizeof(int));

    h->vertices = malloc((int) n*sizeof(struct VerticeSt));
    h->orden = malloc((int) n*sizeof(VerticeP));
    memset(h->vertices, 0, n*sizeof(struct VerticeSt));
    memset(h->orden, 0, n*sizeof(VerticeP));

    h->nvertices = n;
    h->aristas = m;
    return h;
}

// adds new edge (x, y)
bool HashAgregar(u32 z, u32 w, hashList h) {
    VerticeP xPuntero = NULL;
    VerticeP yPuntero = NULL;
    struct VerticeSt x;
    struct VerticeSt y;
    u32 id_z = HashNombre(z, h);
    u32 id_w = HashNombre(w, h);


    while (h->vertices_usados[id_z]) {
        if (h->vertices[id_z].nombreV == z) {
            xPuntero = &h->vertices[id_z];
            break;
        }
        else {
            id_z++;
            if (id_z == h->nvertices)
                id_z = 0;
        }
    }
    if(xPuntero == NULL) {
        x.nombreV = z;
        x.colorV = 0;
        x.gradoV = 0;
        x.hashV = id_z;
        h->vertices[id_z] = x;
        xPuntero = &h->vertices[id_z];
        h->vertices_usados[id_z] = true;
        h->orden[id_z] = xPuntero;
    }

    while (h->vertices_usados[id_w]) {
        if (h->vertices[id_w].nombreV == w) {
            yPuntero = &h->vertices[id_w];
            break;
        }
        else {
            id_w++;
            if (id_w == h->nvertices)
                id_w = 0;
        }
    }
    if(yPuntero == NULL) {
        y.nombreV = w;
        y.colorV = 0;
        y.gradoV = 0;
        y.hashV = id_w;
        h->vertices[id_w] = y;
        h->vertices_usados[id_w] = true;
        yPuntero = &h->vertices[id_w];
        h->orden[id_w] = yPuntero;
    }


    xPuntero->gradoV++;
    yPuntero->gradoV++;

    struct LadoSt l;
    l.x = xPuntero;
    l.y = yPuntero;


    u32 hash = HashCode(z, w, h);

    while (h->used[hash]) {
        if (CompararLados(h->data[hash], l)) {
            return false;
        }
        else {
            hash++;
            if(hash == h->aristas)
                hash = 0;
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
void HashEnumerar(VerticeP x, hashList h) {

    for (int i = h->heads_ida[x->hashV]; i != -1; i = h->next_ida[i]) {
        if(VerticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            //Comparacion para sacar el Vertice contrario.
            printf("%d", NombreDelVertice(*ObtenerVerticeY(h->data[i])));
        }
        else
            printf("%d", NombreDelVertice(*ObtenerVerticeX(h->data[i])));
        if (h->next_ida[i] != -1)
            printf(",");
    }

    for (int i = h->heads_vuelta[x->hashV]; i != -1; i = h->next_vuelta[i]) {
        if(VerticesIguales(x, ObtenerVerticeX(h->data[i]))) {
            //Comparacion para sacar el Vertice contrario.
            printf("%d", NombreDelVertice(*ObtenerVerticeY(h->data[i])));
        }
        else
            printf("%d", NombreDelVertice(*ObtenerVerticeX(h->data[i])));
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
                printf("%d", NombreDelVertice(*ObtenerVerticeY(h->data[i])));
            else
                printf("%d", NombreDelVertice(*ObtenerVerticeX(h->data[i])));
            if (h->next_ida[i] != -1)
                printf(",");
        }

        for (int i = h->heads_vuelta[j]; i != -1; i = h->next_vuelta[i]) {
            if(j == ObtenerVerticeX(h->data[i])->nombreV)
                printf("%d", NombreDelVertice(*ObtenerVerticeY(h->data[i])));
            else
                printf("%d", NombreDelVertice(*ObtenerVerticeX(h->data[i])));
            if (h->next_vuelta[i] != -1)
                printf(",");
        }
        printf(".\n");
    }
}

VerticeP HashIesimoVecino(VerticeP x, u32 z, hashList h) {

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


u32 HashNombre(u32 hash, hashList h) {
	hash ^= (hash >> 16);
	hash *= 0x85ebca6b;
	hash ^= (hash >> 13);
	hash *= 0xc2b2ae35;
	hash ^= (hash >> 16);
    return hash % h->nvertices;
}

void DestruirHashList (hashList h) {
    /*
    for (u32 i = 0; i < h->aristas; i++) {
        DestruirLado(h->data[i]);
    }

    for (u32 i = 0; i < h->nvertices; i++) {
        DestruirVertice(h->vertices[i]);
    }
     */
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
