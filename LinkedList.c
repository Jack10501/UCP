#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* construct()
{
    LinkedList* list;

    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void insertFirst(LinkedList* list, void* data)
{
    /*Create a new node*/
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->next = NULL;
    newNode->prev = NULL;
    /*Point data to the value to be inserted*/
    newNode->data = data;

    if(list->head == NULL)
    {
        list->head = newNode;
        list ->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }

    list->size++;
}

void insertLast(LinkedList* list, void* data)
{
    /*Create a new node*/
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->next = NULL;
    newNode->prev = NULL;
    /*Point data to the value to be inserted*/
    newNode->data = data;

    if(list->tail == NULL)
    {
        list->head = newNode;
        list ->tail = newNode;
    }
    else
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

LinkedListNode* removeFirst(LinkedList* list)
{
    LinkedListNode* temp;

    if((list->size == 0))
    {
        temp = NULL;
    }
    else
    {
        temp = list->head;
        list->head = list->head->next;
        temp->next = NULL;
        if(temp == list->head)
        {
            list->head = NULL;
            list->tail = NULL;
        }
    }
    list->size--;
    free(temp);
    return list->head;
}

LinkedListNode* removeLast(LinkedList* list)
{
    LinkedListNode* temp;

    if(list->size == 0)
    {
        temp = NULL;
    }
    else
    {
        temp = list->tail;
        list->tail = list->tail->prev;
        temp->prev = NULL;
        if(temp == list->tail)
        {
            list->head = NULL;
            list->tail = NULL;
        }
    }
    list->size--;
    /*free(temp);*/
    return list->tail;
}

LinkedListNode* find(LinkedList* list, int ii)
{
    LinkedListNode* currentNode;
    int curr = 0;

    if(ii >= list->size || ii <= 0)
    {
        currentNode = NULL;
    }
    else
    {
        currentNode = list-> head;
        while(curr < ii)
        {
            currentNode = currentNode -> next;
            curr++;
        }
    }

    return currentNode;
}

void print(LinkedList* list)
{
    int ii;
    LinkedListNode* curr;
    curr = list->head;
    for(ii = 0; ii < list->size;ii++)
    {
        printf("Data: %d\n", *((int*)curr->data));
        curr = curr->next;
    }
}

void freeLinkedList(LinkedList* list)
{
    freeNode(list->head);
    free(list);
}

void freeNode(LinkedListNode* node)
{
    if(node != NULL)
    {
        freeNode(node->next);
        free(node);
    }
}
