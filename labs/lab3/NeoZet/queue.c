#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void enqueue(Queue *queue, char value)
{
	Element *tmp = (Element*)malloc(sizeof(Element));
	if(tmp == NULL) 
	{
		exit(QUEUE_OVERFLOW);
	}

	if(queue->head == NULL)
	{ 
		queue->head = (Element*)malloc(sizeof(Element));
		queue->tail = (Element*)malloc(sizeof(Element));	
		queue->head->value = value;
		queue->head->next = queue->tail;
		queue->tail = queue->head;
		queue->size++;
	}
	else {
		tmp->value = value;
		queue->tail->next = tmp;
		queue->tail = tmp;
		queue->size++;
	}
}

char dequeue(Queue *queue)
{
	if(queue->head == NULL)
	{
		return QUEUE_UNDERFLOW;
	}
	char value = queue->head->value;
	Element *tmp = (Element*)malloc(sizeof(Element));
	tmp = queue->head;
	queue->head = queue->head->next;
	free(tmp);
	queue->size--;
	return value;
}

















// void put(Queue *queue, char value)
// {
// 	Element *tmp = (Element*)malloc(sizeof(Element));
// 	if(tmp == NULL) 
// 	{
// 		exit(QUEUE_OVERFLOW);
// 	}

// 	if(queue->size == 0)
// 	{
// 		queue->head = (Element*)malloc(sizeof(Element));
// 		queue->tail = (Element*)malloc(sizeof(Element));	
// 		queue->head->value = value;
// 		queue->head->next = queue->tail;
// 		queue->tail->next = queue->head;
// 		queue->size++;
// 	}
// 	else if(queue->size == 1) 
// 	{
// 		queue->tail->value = value;
// 		queue->size++;	
// 	}
// 	else {
// 		tmp->value = value;
// 		tmp->next = queue->tail;
// 		queue->tail = tmp;
// 		queue->size++;
// 	}
// }

// char get(Queue *queue)
// {
// 	if(size == 0)
// 	{
// 		return STACK_UNDERFLOW;
// 	}
// 	char value = queue->head->value;

// }













// void push(Queue **tail, char value)
// {
// 	Queue *tmp = malloc(sizeof(Queue));
// 	if (tmp == NULL) 
// 	{
// 		exit(QUEUE_OVERFLOW);
// 	}
// 	tmp->value = value;
// 	tmp->next = *tail;
// 	*tail = tmp;
// 	(*tail)->size++;
// }

// char pop(Queue **head)
// {
// 	if(*head == NULL) 
// 	{
// 		return QUEUE_UNDERFLOW;
// 	}
// 	Queue *tmp = malloc(sizeof(Queue));

// }