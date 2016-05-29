//Queue implementation by array
//Time complexity of all operations like enqueue(), dequeue(), isFull(), isEmpty(), front() and rear() is O(1)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue
{
	int front, rear, size;
	int capacity;
	int *arr;
}QueArr;

QueArr *CreateQueue(int capacity)
{
	QueArr *quearr = malloc(sizeof(QueArr));
	quearr->front = quearr->size = 0;
	quearr->capacity = capacity;
	quearr->rear = 0;
	quearr->arr = malloc(sizeof(int) * quearr->capacity);
	return quearr;
}

int IsFull(QueArr *queue)
{
	return (queue->size == queue->capacity);
}


int IsEmpty(QueArr *queue)
{
	return (queue->size == 0);
}

void EnQueue(QueArr *que, int data)
{
	if(IsFull(que))
		return;

	que->arr[que->rear] = data;
	que->rear = (que->rear +1)%que->capacity;
	que->size++;
	
	//printf("ele = %d front = %d rear = %d size = %d\n", que->arr[(que->rear-1)%que->capacity], que->front, que->rear, que->size);
	return ;
}

int DeQueue(QueArr *que)
{
	if(IsEmpty(que))
		return INT_MIN;
	
	int data = que->arr[que->front];
	que->front = (que->front +1)%que->capacity;	
	que->size--;

	//printf("ele = %d front = %d rear = %d size = %d\n", data, que->front, que->rear, que->size);

	return data;
}

int QueFront(QueArr *que)
{
	if(IsEmpty(que))
		return INT_MIN;

	return que->arr[que->front];
}

int QueRear(QueArr *que)
{
	if(IsEmpty(que))
		return INT_MIN;
	
	return que->arr[que->rear - 1];
}

void QueDisplay(QueArr *que)
{
	if(IsEmpty(que))
		return ;
	

	printf("current list\n");
	int i = 0;
	int j = que->front;	

	for(; i < que->size; i++)
		printf("%d  ", que->arr[(i + j)%que->capacity]);

	
	printf("\n");

	printf("size = %d, rear = %d, front = %d\n", que->size, que->rear, que->front);
	
	return;
}

void QueDel(QueArr *que)
{
	free(que->arr);
	que->arr = NULL;
	free(que);
	que = NULL;
	
	return;
}

int main()
{
	QueArr *queue = CreateQueue(5);
	
	EnQueue(queue, 1);
	EnQueue(queue, 2);
	EnQueue(queue, 3);
	EnQueue(queue, 4);

	QueDisplay(queue);

	printf("Dequeue = %d\n", DeQueue(queue));
	printf("Dequeue = %d\n", DeQueue(queue));

	QueDisplay(queue);

	EnQueue(queue, 5);
	EnQueue(queue, 6);
	QueDisplay(queue);

	EnQueue(queue, 7);
	QueDisplay(queue);

	printf("front = %d\n", QueFront(queue));
	printf("rear = %d\n", QueRear(queue));

	QueDel(queue);

	return 0;
}
