#include <stdio.h>
#include <stdlib.h>
#include "hashlink.h"
#include <math.h>

typedef unsigned int *u32;


struct hashList {
    VerticeSt heads[SIZE];
    VerticeSt data[SIZE];
    bool used[SIZE];
    VerticeSt next[SIZE];
};
// n number of vertices
hashList newhashList(u32 n) {
    hashList h;
    h = malloc(1*sizeof(struct hashList));
    memset(h.heads, -1, sizeof(heads));
}
// adds new edge (x, y)
boolean hash_add(u32 x, u32 y, hashList h) {
    u32 code = hash_code(x, y);
    u32 hash = hash(x, y);
    while (h.used[hash]) {
        if (h.data[hash] == code) {
            return false;
        }
        else {
            hash = (hash + 1) % SIZE;
        }
    }
    h.data[hash] = code;
    h.used[hash] = true;
    h.next[hash] = heads[x];
    h.heads[x] = hash;
    return true;
}
// returns true if edge (x, y) is contained in the graph
boolean hash_contains(u32 x, u32 y, hashList h) {
    u32 code = hash_code(x, y);
    u32 hash = hash(x, y);
    while (h.used[hash]) {
        if (h.data[hash] == code) {
            return true;
        }
        else {
            hash = (hash + 1) % SIZE;
            return false;
        }
    }
}

u32 hash_search(u32 x, hashList h) {
    u32 code = hash_code(x, y);
    u32 hash = hash(x, y);
    while (h.used[hash]) {
        if (h.data[hash] == code) {
            return h.data[hash];
        }
    }
}

// enumerates the vertices adjacent to x
void hash_enumerate(u32 x, hashList h) {
    for (u32 i = h.heads[x]; i != -1; i = h.next[i]) {
        u32 y = (u32) h.data[i];
// do something with y
    }
}
// returns hash code for edge (x, y)
u32 hash(u32 x, u32 y) {
    return fabs((x + 111111) * (y - 333333) % SIZE);
}
// converts pair (x, y) to single integer value
u32 hash_code(u32 x, u32 y) {
    return ((1 * x) << 32) | y;
}