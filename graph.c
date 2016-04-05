#include <stdio.h>
#include <stdlib.h>

typedef unsigned int *u32;

typedef NimheSt *NimheP;


struct VerticeSt  {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;

};

struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    u32 *PrimerOrden;
    u32 *SegundoOrden;
    //hash_link
    //Espacio para mas cosas
};

NimheP NuevoNimhe() {
    u32 cantv, cantl;
    char input[80];
    while (input[0] == 'c') {
        scanf("%s", &input);
    }
    if (input[0] != 'p') {
        printf("(Input invalido");
        return NULL;
    }

    char *edge;
    char input_format[] = "p edge n m";
    char input_format_2[] = "e n m";
    sscanf(input, input_format, "%c, %s, %u, %u", p, edge, &cantv, &cantl);
    //Chequeo el input correcto
    if (edge != "edge") {
        printf("(Input invalido");
        return NULL;
    }
    NimheP grafo = NULL;
    grafo = malloc(1*sizeof(struct NimheSt));
    grafo->cantVertices = cantv;
    grafo->cantLados = cantl;
    grafo->PrimerOrden, grafo->SegundoOrden = malloc(cantv*sizeof(u32));
    
    
    /* FALTA AGREGAR ESTRUCTURA A CADA VERTICE Y CONTAR EL GRADO.*/

    u32 n, m;
    bool existe = false;
    u32 len = 0;
    for (u32 i = 0; i < cantl; i++) {
        scanf("%s", &input);
        sscanf(input, input_format_2, "%c, %u, %u", p, &n, &m);
        if (p != 'e')
            return NULL;
        //Chequear si n y m son numeros
        hash_table_add(n, m);
        for (u32 i = 0; i < cantv; i++) {
            existe = existe || PrimerOrden[i] == n;    
        }
        if (!existe) {
            PrimerOrden[len];
            SegundoOrden[len];
            ++len;
        }
    }

    return grafo;
}
    /*Colorea en 0
    for (uint i = 0; i < cantv; ++i) {
        uf->trep[i] = -1;
    }*/