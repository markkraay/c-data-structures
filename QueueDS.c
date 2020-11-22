/*
 * Linear
 * FIFO
 * Insertion takes place from the rear end
 * Deletation take place from the front end
 * 4 Major Operations - All constant time - O(1)
 * 	enqueue(x) - inserts x at top
 * 	dequeue() - removes the first element of the queue
 * 	peekfirst() - gets the first element of queue
 * 	peeklast() - gets the last element of the queue
*/

/*
 * === Advantages ===
 * FIFO
 * Insertion from beginning and deletion from end takes O(1)
 *
 * === Disadvantages ===
 * Manipulation is restricted to the front and rear end
 * Not much flexibility
 *
 * === Applications ===
 * Scheduling
 * Interrupt handling
 * Used in many algorithm - Depth's First Search
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = malloc(queue->capacity * sizeof(int));
	return queue;
}

int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
	{
		return;
	}
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}

int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
	{
		return INT_MIN;
	}
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;
	queue->size =- 1;
	return item;
}

int front(struct Queue* queue)
{
	if (isEmpty(queue))
	{
		return INT_MIN;
	}
	return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
	if (isEmpty(queue))
	{
		return INT_MIN;
	}
	return queue->array[queue->rear];
}

int main()
{
	struct Queue* queue = createQueue(100);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	printf("Dequeued %d\n", dequeue(queue));
	printf("Front: %d\n", front(queue));
	printf("Rear: %d\n", rear(queue));

	return 0;
}

