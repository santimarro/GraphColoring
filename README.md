# Laboratorio Discreta 2016.


Integrantes:

  - Santiago Marro
  - Ramiro Barraco

### Introducción
Realizamos un programa que afronta el problema de encontrar el numero cromático de un grafo determinado. Como sabemos por lo visto en la cátedra, no existe algoritmo alguno que resuelva esto en orden polinomial, al menos cuando el grafo no es bipartito (X(G) > 2). 

Para ello utilizamos el algoritmo Greedy como principal herramienta de coloreo, combinándolo con una serie aleatoria de ordenaciones de los vértices. Ya establecimos en la cátedra que el algoritmo de Greedy arroja distintos resultados, según el orden de los vértices que se van coloreando y, también, si se ordena de acuerdo a sus colores, el algoritmo de Greedy no puede devolver resultados mayores a la iteración anterior. Aprovechándonos de este hecho, resolvimos un programa donde se ejecuta Greedy más de 1000 veces a partir de un "mejor" coloreo previamente logrado, guardando siempre el menor coloreo como resultado. Todo este proceso será explicado luego en la especificación del main.

Siguiendo la consigna, el proyecto está separado en dos directorios llamados _apifiles_ y _dirmain_, donde el main se encuentra en _dirmain_ y los archivos fuente en _apifiles_. 

Para compilar el mismo se debe ejecutar lo siguiente:


- _gcc -Wall -Wextra -O3 -std=c99 -Iapifiles dirmain/mainBarracoMarro.c apifiles/*.c -o BM_



### Especificación.
Explicaremos el programa en diferentes etapas:

- La carga del grafo.
- El ordenamiento de sus vértices.
- Coloreo usando Greedy.
    
Primero vamos a explicar las estructuras utilizadas en el programa.
    
  - #### VerticeSt

```c
struct VerticeSt {
    u32 nombreV;
    u32 gradoV;
    u32 colorV;
    u32 capacidad;
    VerticeP *vecinos;
};
```
 _nombreV_ : Se guarda el nombre del vértice.
 
 _gradoV_: Se guarda el grado del vértice.
 
 _colorV_ : Se guarda el color del vértice.
 
 _capacidad_ : Cantidad de vecinos que puede tener.
 
 _vecinos_  : Puntero a un array, donde se encuentran los vecinos del vértice.


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
_cantVertices_ : Cantidad de vértices del grafo.

_cantLados_ : Cantidad de lados en el grafo

_cantcolor_: Cantidad de colores en el grafo.

_vertices_: Puntero a un arreglo de vértices.

_orden_: Arreglo con el orden de los vértices.

_vertices_usados_: Arreglo para saber si ya creamos el vértice o no.

_orden_natural_: Arreglo con los vértices ordenados en su orden natural.

### Ahora procederemos a explicar la 3 etapas del programa:

#### _La carga del grafo._

El formato de entrada es una variación de DIMACS. Primero para cargar el grafo se utiliza la función, _NuevoNihme()_. Lee el input descartando la lineas que empiecen con 'c', los comentarios. Hasta que se ingrese una linea que comienza con 'p'. Allí sabemos la cantidad de vertices y lados que va a tener el grafo. En ese momento se reserva la memoria necesaria para guardar el grafo completo. A continuación se observan las lineas que tienen al principio 'e'. Para luego agregar los lados llamando a _AgregarLado()_, se revisa si los vertices están creados o no. Si están creados entonces se agregan como vecinos entre sí con la función _AgregarVecino()_. Si no estan agregados se los crea con la función _NuevoVertice()_ y luego se los vuelve vecinos.

La función _AgregarLado()_ realiza la siguiente tarea. Se le asigna un id provisorio al vértice y a partir del mismo se busca si el vertice ya existe. Si no existe se obtiene el id definitivo y luego se lo guarda en el arreglo _vertices_ en la posicion del id. En ambos casos se consigue el puntero al vértice y se agregan como vecinos entre si.

La función _AgregarVecino()_ chequea si tiene capacidad para agregar un vecino a un vértice dado. Si ya esta lleno pide mas memoria y luego lo agrega al arreglo vecinos que es parte del vértice. Si no solo lo agrega.


#### _El ordenamiento de sus vértices._

Luego de cargar el grafo, lo ordenamos de diferentes formas. A continuación explicamos cada una de ellas.

_OrdenNatural()_ : Usamos la función _qsort()_ con la comparación _CrecienteCompNombre_ la cual compara los vértices por su nombre de mayor a menor. Copiamos el orden en el arreglo del grafo que se llama "orden_natural".

_OrdenWelshPowell()_ : Parecido con el orden anterior utilizamos la función _qsort()_, esta vez usando la comparación _CompWelshPowell()_. Que compara los grados y pone los vértices de menor grado primero.

_ReordenAleatorioRestringido()_ : Esta vez usamos una variable global para guardar un numero aleatorio, que luego utilizamos en la función de comparación que usamos en _qsort()_. Para generar nuestro numero aleatorio usamos la función _rand()_. De esta forma ordenamos los vértices eligiendo un color al azar. Hacemos esto multiples veces para que todos los vertices queden ordenados en grupos de colores elegidos al azar.

_GrandeChico()_: Ordena los vértices poniendo primero los vértices cuyo color sea el mas usado  a menos usado. Utilizando la función _qsort()_ con la comparación _CompGrandeChico()_.

_ChicoGrande()_: Ordena los vértices poniendo primero los vértices cuyo color sea el menos usado a mas usado. Utilizando la función _qsort()_ con la comparación _CompGrandeChico()_.

_Revierte()_: Como dice el nombre revierte el orden de los vértices. También se utiliza la función _qsort()_  y la función _DecreCompColores()_.

_OrdenEspecifico()_: la función toma un arreglo de elementos del mismo tamaño que el grafo. Luego ordena los vértices en su orden natural con _OrdenNatural_ si el elemento  _orden_natural_ esta vacio. Luego hace un loop para chequear que el iesimo elemento no sea mas grande que el tamaño del arreglo, también se fija que no este repetido. Si no hay problemas, guarda en la posición iesima del arreglo _orden_, lo que se encuentra en el arreglo _orden_natural_ en la posición k-esima(siendo la posición k-esima el numero que corresponde a la iesima posición de la copia del arreglo).

Parte fundamental de los algoritmos de ordenación es la función _q_sort_, asi que le daremos una breve explicación a continuacion.

La funcion _q_sort_ toma la informacion de un arreglo de elementos, su tamaño y cantidad como tambien una función para comparar cada uno. Si la funcion que se usa para comparar devuelve 0 no se hace nada, pues lo dos elementos son iguales. Pero si la funcion devuelve 1 o -1 entonces q_sort lo mueve a la derecha o izquierda correspondientmente.

#### _Main y el coloreo de los vertices._

Empezamos cargando el grafo con la funcion _NuevoNihme()_. Para luego correr _Chidos_  y verificar si el grafo es bipartito o no, si el grafo es bipartito el program termina. Si el grafo no es bipartito, entonces corremos 10 veces el algoritmo de _Greedy()_ usando los ordenes que duelve la funcion _OrdenEspecifico()_. Cada vez que ordenamos pasamos un arreglo x hecho al azar. Siempre fijandonos cual fue el mejor coloreo y su orden.
luego de los 10 _Greedy_, ordenamos una vez mas usando Welsh-Powell y si con ese orden el coloreo es 3. Entonces el programa termina y devuelve que 3 es el mejor coloreo posible. Si es distinto de 3, se realizan 1001 _Greedy()_ mas con ordenes elegidos al azar.

- 50% para el orden _ChicoGrande()_.
- 12,5% para el orden _GrandeChico()_.
- 31,25% para el orden _Revierte()_.
- 6,25% para el orden _ReordenAleatorioRestringido()_.

A continuacion se duvuelve el mejor coloreo y la cantidad de veces que se uso cada orden.

Para las funciones _Greedy()_ y _Chidos()_ se usaron los algoritmos que fueron enseñados en la catedra.

### Preguntas Puntuales.
 >¿Como hicieron para resolver el problema de que los vértices pueden ser cualquier u32? Dependiendo de como resuelvan este problema, deben responder otras preguntas
 
 Para resolver este problema decidimos utilizar un array donde guardamos los vértices a medida que se va leyendo el grafo. La primera complicación que tuvimos fue el hecho de saber si un vertice que estábamos leyendo ya lo habíamos leido antes. Recorrer el array no era una opción debido a su complejidad.
 
 Para ello resolvimos utilizar un array de booleanos donde su indice indica el _hash_ del nombre del vértice. Si el array en esa posición esta seteado en true, quiere decir que el vértice ya fue creado y no se lo crea.
 
 El _hash_ de cada vértice se obtiene de la siguiente forma:

- 1° Se toma el nombre del vértice a guardar y se le aplica la función modulo con respecto a la cantidad de vértices que tiene el grafo.
- 2° Se revisa en el array _vertices_usados_, parte de la estructura del grafo,  en la posición _hash_. Si se encuentra en true, quiere decir que esa posición ya fue tomada por algún vértice, donde lo más probable es que sea el mismo que se quiere agregar. Por lo tanto se revisa si ese vértice posee el mismo nombre al que queremos agregar. Si es así, no se crea un vértice nuevo, ya que ya lo habíamos leído previamente. Si no es el mismo, se procede a sumarle 1 a hash y se realiza el mismo procedimiento. Esto continúa hasta que se encuentre una posición en _vertices_usados_ donde sea false ó se encuentre el mismo vértice a agregar.
- 3° En el caso de que se encuentre una posición en _vertices_usados_ donde sea false su valor, se debe crear el vértice, y luego settear esa posición como true.


>Cómo implementaron Gamma(x)?

Resolvimos este problema agregando a cada vértice _x_, una lista de sus vecinos. Es decir, si tengo el _VerticeSt x_, para ver sus vecinos solo debo hacer:
_iesimoVecino = x.vecinos[i]_. Donde i es el iesimo vecino.


>Cómo implementaron el orden de los vértices? 

Simplemente guardamos en la estructura NimheSt un arreglo llamado _orden_ de punteros a VerticeSt, en determinado orden. Estos punteros _VerticeP_ apuntan a vértices _VerticeSt_ guardados en el array _vertices_, también en la estructura del grafo NimheSt.
Cuando el programa recién termina de cargar el grafo, el orden de los vertices en _vertices_ y _orden_ es el mismo. Luego cuando se quiere ordenar solo se cambia _orden_.

Side note: Para facilitar la función _OrdenEspecifico_ también tenemos un array llamado _orden_natural_ donde guardamos el orden natural según como lo especifica la consigna.


>Cómo implementaron Greedy? ¿Qué estrategia usaron para lograr reducir la velocidad?