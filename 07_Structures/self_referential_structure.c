/**
 * self_referential_structure.c
 *
 * Demonstrates a self-referential structure in C
 * using a simple singly linked list.
 *
 * Author: Example
 */

#include <stdio.h>
#include <stdlib.h>

/* ======================================
   Self Referential Structure Definition
   ======================================

   Each node contains:
   1. data  -> value stored
   2. next  -> pointer to next node

   'next' pointer refers to same structure type.
*/

struct Node
{
    int data;          // Value stored in node
    struct Node *next; // Pointer to next node
};

/* ======================================
   Function: createNode
   Creates a new node and returns pointer
   ====================================== */

struct Node *createNode(int value)
{
    // allocate memory for new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // store data
    newNode->data = value;

    // initially next pointer is NULL
    newNode->next = NULL;

    return newNode;
}

/* ======================================
   Function: printList
   Traverses and prints linked list
   ====================================== */

void printList(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* ======================================
   Main Function
   ====================================== */

int main()
{
    /* Creating nodes */
    struct Node *head = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);

    /* Linking nodes */
    head->next = second;
    second->next = third;

    /* Display list */
    printf("Linked List:\n");
    printList(head);

    return 0;
}