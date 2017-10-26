/**
 * LinkedList.c
 * Author: Jack Paull
 * Purpose: Creates a collects of elements stored in a list
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/**
 * construct()
 * Creates an empty linked list
 *
 * returns a new linked list
 */
LinkedList* construct()
{
    LinkedList* list;

    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/**
 * insertFirst()
 * Inserts an elements to the front of the list
 * list: The list to be added to
 * data: The data to be added to the list
 *
 * returns void
 */
void insertFirst(LinkedList* list, void* data)
{
    /*Create a new node*/
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->next = NULL;
    newNode->prev = NULL;
    /*Point data to the value to be inserted*/
    newNode->data = data;

    /*checks if the list is empty*/
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

/**
 * insertLast()
 * Inserts an element at the back of the list
 * list: The list to insert into
 * data: The data to added to the list
 *
 * returns void
 */
void insertLast(LinkedList* list, void* data)
{
    /*Create a new node*/
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->next = NULL;
    newNode->prev = NULL;
    /*Point data to the value to be inserted*/
    newNode->data = data;

    /*Checks if the list is empty*/
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

/**
 * removeFirst()
 * Removes the first element from the list
 * list: The list to remove from
 *
 * returns the lists new head
 */
void removeFirst(LinkedList* list)
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
        if(temp->next == NULL)
        {
            list->head = NULL;
            list->tail = NULL;
        }
    }
    list->size--;
    free(temp->data);
    free(temp);
}

/**
 * removeLast()
 * Removes the last element from the list
 * list: The list to remove from
 *
 * returns the lists new tail
 */
void removeLast(LinkedList* list)
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
        if(temp->prev == NULL)
        {
            list->head = NULL;
            list->tail = NULL;
        }
    }
    list->size--;
    free(temp->data);
    free(temp);
}

/**
 * find()
 * Finds a specific element within the list
 * list: The list to search
 * ii: The node to find
 *
 *returns to desired node
 */
LinkedListNode* find(LinkedList* list, int ii)
{
    LinkedListNode* currentNode;
    int curr = 0;

/*Checks that the desired node is within the list bounds*/
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


/**
 * freeLinkedList
 * Frees the LinkedList
 * list: The list to be freed
 *
 * returns void
 */
void freeLinkedList(LinkedList* list)
{
    freeNode(list->head);
    free(list);
}

/**
 * freeNode()
 * Recursively frees the next node in the list
 * node: The current node to be freed
 *
 * returns void
 */
void freeNode(LinkedListNode* node)
{
    if(node != NULL)
    {
        freeNode(node->next);
        free(node->data);
        free(node);
        node = NULL;
    }
}
