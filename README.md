# Laboratorio Discreta 2016.


Integrantes:

  - Santiago Marro
  - Ramiro Barraco

### Especificación.

Nuestro programa busca el mejor coloreo propio posible para un determinado grafo. Explicaremos el programa en diferentes etapas:

- La carga del grafo.
- El ordenamiento de sus vertices.
- Coloreo usando Greedy.
    
Primero vamos a explicar las estructuras utilizadas en el programa.
    
  - #### VerticeSt

```c
struct VerticeSt {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
    u32 hashV;
    u32 capacidad;
    VerticeP *vecinos;
};
```
 _nombreV_ : Se guarda el nombre del vertice.
 
 _gradoV_: Se guarda el grado del vertice.
 
 _colorV_ : Se guarda el color del vertice.
 
 _hashV_ : Se guarda el id del vertice.
 
 _capacidad_ : Cantidad de vecinos que puede tener.
 
 _vecinos_  : Puntero a un array, donde se encuentran los vecinos del vertice.


  - #### NihmeSt

```c
struct NimheSt {
    u32 cantVertices;
    u32 cantLados;
    u32 cantcolor;
    struct VerticeSt *vertices;
    VerticeP *orden;
    bool *vertices_usados;
    VerticeP *orden_natural;
};
```
_cantVertices_ : Cantidad de vertices del grafo.

_cantLados_ : Cantidad de lados en el grafo

_cantcolor_: Cantidad de colores en el grafo.

_vertices_: Puntero a un arreglo de vertices.

_orden_: Arreglo con el orden de los vertices.

_vertices_usados_: Arreglo para saber si ya creamos el vertice o no.

_orden_natural_: Arreglo con los vertices ordenados en su orden natural.

### Ahora procedemos a explicar la 3 etapas del programa:

#### _La carga del grafo._

El formato de entrada es una variacion de DIMACS. Primero para cargar el grafo se utiliza la función, _NuevoNihme()_. Lee el input descartando la lineas que empiecen con 'c', los comentarios. Hasta que se ingrese una linea que comienza con 'p'. Alli sabemos la cantidad de vertices y lados que va a tener el grafo. En ese momento se reserva la memoria necesaria para guardar el grafo completo. A continuacion se observan las lineas que tienen al principio 'e'. Para luego agregar los lados llamando a _AgregarLado()_, se revisa si los vertices estan creados o no. Si estan creados entonces se agregan como vecinos entre si con la funcion _AgregarVecino()_. Si no estan agregados se los crea con la funcion _NuevoVertice()_ y luego se los vuelve vecinos.

La funcion _AgregarLado()_ realiza la siguiente tarea. Se le asigna un id provisorio al vertice y apartir del mismo se busca si el vertice ya existe. Si no existe se obtiene el id definitivo y luego se lo guarda en el arreglo _vertices_ en la posicion del id. En ambos casos se consigue el puntero al vertice y se agregan como vecinos entre si.

La funcion _AgregarVecino()_ chequea si tiene capacidad para agregar un vecino a un vertice dado. Si ya esta lleno pide mas memoria y luego lo agrega al arreglo vecinos que es parte del vertice. Si no solo lo agrega.

#### _El ordenamiento de sus vertices._

#### _Coloreo usando greedy_

### Preguntas Puntuales.