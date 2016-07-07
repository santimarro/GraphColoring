//
// Created by ophion on 23/06/16.
//

bool esVertice(VerticeSt *v, u32 longitud, u32 n) {
    bool result;
    u32 i = 0;
    while((i < longitud) && (!result)) {
        result = result || (v[i].nombreV == n);
        ++i;
    }
    return result;
}

void nuevoLado(NimheSt *G, u32 i, u32 j) { //Dudas aca si deberia ser puntero G
    if (!esVertice(grafo->vertices, n)
    agregarVertice(grafo->vertices, n);
    if (!esVertice(grafo->vertices, m)
    agregarVertice(grafo->vertices,m);

    //---Corregir esta parte con la hash ya uqe el nombre no es el indice ---------------------//
    AgregarLado(grafo->vertices[i], j);
    AgregarLado(grafo->vertices[j], i); //Pensar mejor implementacion pero no cambia mucho
    // --------------------------------------------------------------------------------------//
}

void inicOrdenes(u32 *primero, u32 *segundo, VerticeSt *v) {
    for(i=0; i < cantv; ++i) {
        primero[i], segundo[i] = v[i];
        // Inicializa los dos órdenes como los vértices ordenados por sus nombres.
    }// Poner en donde corresponda.
}