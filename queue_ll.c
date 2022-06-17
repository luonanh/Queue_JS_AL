#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

//#if 0
#define QUEUE_EMPTY	INT_MIN

typedef struct _node {
	int val;
	struct _node* next;
} node;

typedef struct {
	node* head;
	node* tail;
} queue;

void init_queue(queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

bool enqueue(queue* q, int val)
{
	node* newnode = malloc(sizeof(node));
	if (newnode == NULL) return false;
	newnode->val = val;
	newnode->next = NULL;
	if (q->tail == NULL) {
		q->head = newnode;
	}
	else
	{
		q->tail->next = newnode;
	}
	q->tail = newnode;
	return true;
}

int dequeue(queue* q)
{
	if (q->head == NULL) {
		return QUEUE_EMPTY;
	}

	int result;
	node* tmp = q->head;
	result = tmp->val;
	q->head = tmp->next;
	if (q->head == NULL) {
		q->tail = NULL;
	}
	free(tmp);
	return result;
}

int main()
{
	queue q1, q2, q3;
	init_queue(&q1);
	init_queue(&q2);
	init_queue(&q3);

	enqueue(&q1, 56);
	enqueue(&q1, 56);
	enqueue(&q2, 78);
	enqueue(&q2, 13);
	enqueue(&q2, 988);
	enqueue(&q3, 13);

	int tmp;

	while ((tmp = dequeue(&q2)) != QUEUE_EMPTY) {
		printf("t = %d\n", tmp);
	}
	return 0;

}
//#endif
