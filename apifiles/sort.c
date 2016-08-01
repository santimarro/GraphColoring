

int CrecienteComp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

// Ordena los vertices en orden creciente de sus "nombres" reales
void OrdenNatural(NimheP G) {

	qsort(G.OrdenActual, G.cantVertices, sizeof(int), CrecienteComp);
}

/*Ordena los vertices de G de acuerdo con el orden Welsh-Powell, es decir,
 * con los grados en orden no creciente. */
void OrdenWelshPowell(NimheP G);

/*
 * Si G esta coloreado con r colores y W1 sno los vertices coloreados con 1,
 * W2 los con 2, etc. Se ordena poniendo primero los vertices de Wj1(en algun orden)
 * luego los de Wj2 etc, donde j1,j2,..,etc son aleatorios distintos
 */
void ReordenAleatorioRestringido(NimheP G);


 /* Si G esta coloreado con r colores y W1 sno los vertices coloreados con 1,
 * W2 los con 2, etc. Se ordena poniendo primero los vertices de Wj1(en algun orden)
 * luego los de Wj2 etc, donde j1,j2,..,etc son tales que |Wj1| >= |Wj2| >= ... >= |Wjr|
 */
void GrandeChico(NimheP G);

// Igual que el anterior pero al reves los ordenes.. |Wj1| <= |Wj2|<= ...
void ChicoGrande(NimheP G);

/*Si G esta coloreado con r colores y W 1 son los vertices coloreados con 1, W 2 los coloreados con 2,
 * etc, entonces esta funcion ordena los vertices poniendo primero los vertices de Wr (en algun orden)
 * luego los de W r−1 (en algun orden), etc. */
void Revierte(NimheP G);


// Leer el pdf, muy largo.
void OrdenEspecifico(NimheP G, u32 *x);