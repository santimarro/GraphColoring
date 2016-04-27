#include <stdio.h>
#include <stdlib.h>

#include "vSt.h"
#include "lenla.h"

typedef unsigned int *u32;

typedef NimheSt *NimheP;


/*struct VerticeSt  {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
    //gamma 
};*/

struct NimheSt {

    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    VerticeSt *PrimerOrden; //Tengo dudas aca si deberia ser una lista 
                            //de vertices completos o de numero de vertices
    VerticeSt *SegundoOrden;
    
    //hash_link
    //Espacio para mas cosas
};

NimheP NuevoNimhe() {
    u32 cantv, cantl;
    char input[80];
    input[0] = 'c';
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
VerticeSt IesimoVerticeEnElOrden(NimheP G, u32 i) {
    IesimoVecinoPlus(G->SegundoOrden, i);
}

void nuevoLado(NimheSt *G, u32 i, u32 j) { //Dudas aca si deberia ser puntero G
    NuevoVertice(i);
    NuevoVertice(j);
    VerticeSt f = G->SegundoOrden[i];
    VerticeSt s = G->SegundoOrden[j];
    AgregarLado(f, j);
    AgregarLado(j, f); //Pnesar mejor implementacion pero no cambia mucho
}