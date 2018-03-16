#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* initList(int key, char* value)
{
	Node *head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->key = key;
	head->value = value;

	return head;
}

void addNode(Node** head, int key, char* value)
{
	Node *tmp = (*head);
	Node *newNode = (Node*)malloc(sizeof(Node));
	while((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next = newNode;
	newNode->next = NULL;
	newNode->key = key;
	newNode->value = value;
	(*head) = tmp;
}

Node* findNode(Node* head, int key)
{
	Node* tmp = head;
	while(tmp)
	{
		if(tmp->key == key) return tmp;
		else tmp = tmp->next;
	}
	if(tmp == NULL) return NULL;	
}

void delNode(Node** head, int key)
{
	
	if((*head)->key == key) 
	{
		if((*head)->next) 
		{
			Node *tmp = (*head);
			free(*head);
			(*head) = (*head)->next;
		}
		else {
			free(*head);
		}
		return;
	}

	Node *tmpHead = (*head);

	while((*head)->next->key != key)
	{
		(*head) = (*head)->next;
		if((*head)->next == NULL) break;
	}

	Node *tmp = (*head)->next;
	(*head)->next = (*head)->next->next;
	free(tmp);
	(*head)->next = tmp->next;
	(*head) = tmpHead;
}


















// List* initList(int key, char* value)
// {
// 	List *list = (List*)malloc(sizeof(List));
// 	list->head = (Node*)malloc(sizeof(Node));
// 	list->head->key = key;
// 	list->head->value = value;
// 	list->head->next = NULL;
// 	list->size = 1;

// 	return list;
// }

// void addNode(List *list, int key, char* value)
// {
// 	if(list->head == NULL)
// 	{
// 		list = initList(key, value);
// 		return;
// 	}
// 	Node *newNode = (Node*)malloc(sizeof(Node));
// 	newNode->key = key;
// 	newNode->value = value;

// 	Node *tmp = list->head;
// 	while(list->head->next != NULL)
// 	{
// 		list->head = list->head->next;
// 	}
// 	list->head->next = newNode;
// 	newNode->next = NULL;
// 	list->head = tmp;
// }

// int delNode(List *list, int key)
// {
// 	if(list->head == NULL) return 1;
// 	if(list->head->next == NULL);
// 	{
// 		Node *prev = NULL;
// 		if(list->head->next)
// 		{
// 			prev = list->head;
// 			list->head = list->head->next;
// 			free(prev);
// 		}
// 		free(list->head);
// 		return 1;
// 	}

// 	Node *tmpHead = list->head;

// 	while(list->head->next->key != key)
// 	{
// 		list->head = list->head->next;
// 		if(list->head->next == NULL) return 0;
// 	} 

// 	Node *tmpNode = list->head->next;
// 	free(list->head->next);
// 	list->head->next = tmpNode->next;
// 	list->head = tmpHead;
// 	return 1;
// }
