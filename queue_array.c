#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#if 0
#define QUEUE_EMPTY	INT_MIN

typedef struct {
	int *values;
	int head;
	int tail;
	int num_entries;	// this helps to check for empty or full
	int size;
} queue;

void init_queue(queue* q, int max_size)
{
	q->values = malloc(max_size * sizeof(int));
	q->size = max_size;
	q->num_entries = 0;
	q->head = 0;
	q->tail = 0;
}

bool queue_empty(queue* q)
{
	return (q->num_entries == 0);
}

bool queue_full(queue* q)
{
	return (q->num_entries == q->size);
}

void queue_destroy(queue* q)
{
	free(q->values);
}

bool enqueue(queue* q, int val)
{
	if (queue_full(q)) {
		return false;
	}

	q->values[q->tail] = val;
	q->num_entries++;
	q->tail = (q->tail + 1) % q->size;
	return true;
}

int dequeue(queue* q)
{
	if (queue_empty(q)) {
		return QUEUE_EMPTY;
	}
	int result = q->values[q->head];
	q->head = (q->head + 1) % q->size;
	q->num_entries--;
	return result;
}

int main()
{
	queue q1;
	init_queue(&q1, 5);

	enqueue(&q1, 56);
	enqueue(&q1, 56);
	enqueue(&q1, 78);
	enqueue(&q1, 13);
	enqueue(&q1, 988);
	enqueue(&q1, 13);

	int tmp;

	while ((tmp = dequeue(&q1)) != QUEUE_EMPTY) {
		printf("t = %d\n", tmp);
	}
	return 0;
}
#endif
