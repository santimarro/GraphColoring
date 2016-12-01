#include <stdio.h>
#include <stdlib.h>


#include "../apifiles/Cthulhu.h"

#define min(a,b) (((a)<(b))?(a):(b))

struct Individuo {
    u32 fitness;
    u32 *permutacion;
};

struct Poblacion {
    u32 poblacion;
    struct Individuo *permutaciones;
};

struct Poblacion nuevaPoblacion(u32 poblacion, u32 n) {
// Genera los indivuduos y los guarda en su conjunto de inviduos
    struct Poblacion p;
    p.poblacion = poblacion;
    p.permutaciones = malloc(poblacion*sizeof(struct Individuo));

    for (u32 i = 0; i != poblacion; ++i) {
        p.permutaciones[i] = nuevoIndividuo(n);
    }

    return p;
}

struct Individuo nuevoIndividuo(u32 n){

    struct Individuo individuo;
    individuo.fitness = 0;

    u32 *x = malloc(n * sizeof(u32));

    for (u32 i = 0; i != n; ++i)
        x[i] = i;

    // Se genera un array aleatorio x, el cual servirá como individuo
    for (u32 j = n - 1; j != 0; --j) {
        u32 random_number = (u32) rand() % (j + 1); // 0 <= numero_random <= j

        u32 temp = x[random_number];
        x[random_number] = x[j];
        x[j] = temp;
    }

    individuo.permutacion = &x;
    return individuo;
}

void generarFitness(struct Poblacion *p, NimheP grafo, u32 ventaja_evolutiva) {
    u32 poblacion = p.poblacion;
    u32 colores = 0;
    u32 mayor_fitness = 0;
    u32 n = NumeroDeVertices(grafo);

    for(int i = 0; i < poblacion; i++) {
    // Generamos la fitness de cada individuo
        struct Individuo indv = p.permutaciones[i];
        OrdenEspecifico(grafo, indv.permutacion);
        coloreo = Greedy(grafo);
        indv.fitness = n + 1 - k;
        
        if(mayor_fitness < indv.fitness) {
        // Guardamos la mayor fitness a lo largo de las iteraciones
            mayor_fitness = indv.fitness;
        }
    }

    for(u32 i = 0; i < poblacion; i++) {
    // Buscamos los individuos con mayor fitness y les multiplicamos la constante establecida
        struct Individuo indv = p.permutaciones[i];
        if(indv.fitness == mayor_fitness) {
            indv.fitness = indv.fitness*ventaja_evolutiva;
        }
    }
}

int main() {

    u32 poblacion = 0;
    scanf("%u", &poblacion);

    u32 generaciones = 0;
    scanf("%u", &generaciones);

    u32 ventaja_evolutiva = 0;
    scanf("%u", ventaja_evolutiva);

    NimheP grafo = NuevoNimhe();

    if (grafo == NULL) {
        printf("Error en formato de entrada\n");
        return (EXIT_FAILURE);
    }

    
    if (Chidos(grafo)) {
        printf("Grafo Bipartito\n");
        return (EXIT_SUCCESS);
    }

    printf("Grafo No Bipartito\n");
    u32 seed = (u32) time(NULL);
    srand(seed);

    u32 alduin;                      // Cantidad de colores. 
    u32 n = NumeroDeVertices(grafo); // Cantidad de vertices del grafo
    u32 minimos_colores = n;         // Cantidad minima de colores usados. 

    struct Poblacion p = nuevaPoblacion(poblacion, n);

    generarFitness(&p, grafo, ventaja_evolutiva);

    alduin = min(alduin, Greedy(grafo));
    printf("Mejor coloreo con Greedy iterado 1001 veces: %u colores\n",
           alduin);

    DestruirNimhe(grafo);
}
