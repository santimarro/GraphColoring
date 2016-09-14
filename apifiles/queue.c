#include "Cthulhu.h"

struct QueueSt CrearQueue(u32 size) {
	struct QueueSt q;
	q.head = q.tail = -1;
	q.theQueue = malloc(size*sizeof(VerticeP));
	return q;
}

void DestruirQueue(struct QueueSt q) {
	free(q.theQueue);
}

void Enqueue(struct QueueSt q, VerticeP v) {
	// Increment tail index
	// Add the item to the Queue
	q.theQueue[q.tail] = v;
	return;
}

VerticeP Dequeue(struct QueueSt q) {
	VerticeP v;
	v = q.theQueue[q.head]; // Get character to return
	return v;		    // Return popped character
}

u32 isEmpty(struct QueueSt q) {
	return (q.head == q.tail);
}