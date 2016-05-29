//List implementation of Queues

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

typedef struct QueueList
{
	Node *front, *rear;
}QuList;


QuList *CreatListQueue()
{
	QuList *queue = malloc(sizeof(QuList));
	queue->front = queue->rear = NULL;
	return queue;
}


void DispListQueue(QuList *queue)
{
	printf("current List\n");

	Node *temp = queue->front;
	
	if(temp == NULL)
		return ;	

	while(temp)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}	
	
	printf("\n");	

	return;
}


void EnQList(QuList *queue, int data)
{
	Node *new = malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;

	if(!(queue->front))
	{
		queue->rear = queue->front = new;
	}
	else
	{
		queue->rear->next = new;
		queue->rear = new;
	}
		
	return;
}

int DeQList(QuList *queue)
{
	if(!queue->front)
		return INT_MIN;

	Node *temp = queue->front;
	queue->front = queue->front->next;

	if(!queue->front)
		queue->rear = NULL;  

	return temp->data;
}


int main()
{
	//QuList *queue = CreatListQueue();
	//use above function or below three lines
	//
	QuList *queue  = malloc(sizeof(QuList));
	queue->front = NULL;
	queue->rear = NULL;

	DispListQueue(queue);

	EnQList(queue, 1);
	EnQList(queue, 2);
	EnQList(queue, 3);
	
	DispListQueue(queue);
	DeQList(queue);	
	DispListQueue(queue);
	//DeQList(queue);	
	//DeQList(queue);	
	EnQList(queue, 4);
	EnQList(queue, 5);
	EnQList(queue, 6);
	EnQList(queue, 7);
	DispListQueue(queue);

	free(queue);
	queue = NULL;

	//DispListQueue(queue);

	return 0;
}
