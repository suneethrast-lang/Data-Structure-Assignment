/*
 * FILE: printer_queue.c
 * PURPOSE: Implement a queue for a printer job management system
 * DESCRIPTION: This program simulates a printer queue where documents
 *              are queued in FIFO (First In First Out) order.
 *              Supports enqueue (add document), dequeue (print document),
 *              and display (show pending documents) operations.
 * DATA STRUCTURE: Linked list-based queue
 * AUTHOR: DSA Assignment
 * DATE: 2024
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * STRUCTURE: node
 * PURPOSE: Represents a single node in the queue (a document in the queue)
 * FIELDS: data - document number/ID
 *         next - pointer to next node in queue
 */
struct node
{
    int data;               // Document/job data
    struct node *next;      // Pointer to next node
};

struct node *front=NULL;   // Front pointer (dequeue position)
struct node *rear=NULL;    // Rear pointer (enqueue position)

/*
 * FUNCTION: enqueue
 * PURPOSE: Add a new document/job to the rear of the queue
 * PARAMETERS: None (reads input from user)
 * RETURN: void
 * ALGORITHM:
 *   1. Allocate memory for a new node
 *   2. Read document data from user
 *   3. If queue is empty, set both front and rear to new node
 *   4. Otherwise, link new node at rear and update rear pointer
 * DESCRIPTION: Adds elements to the queue from the rear end in FIFO order.
 *              Checks for queue overflow implicitly through malloc.
 */
void enqueue()
{
    struct node *temp=NULL;
    temp=(struct node*)malloc(sizeof(struct node));  // Allocate memory for new node
    printf("Enter the value:");
    scanf("%d",&temp->data);                        // Read document data
    temp->next=NULL;                                 // New node is last node

    if(rear==NULL)                                   // Queue is empty
    {
        front=rear=temp;                             // Both pointers point to new node
    }
    else
    {
        rear->next=temp;                             // Link new node after rear
        rear=temp;                                   // Update rear to new node
    }

    printf("Document entered successfully!!");
}

/*
 * FUNCTION: dequeue
 * PURPOSE: Remove and process (print) a document from the front of the queue
 * PARAMETERS: None
 * RETURN: void
 * ALGORITHM:
 *   1. Check for queue underflow (front == NULL)
 *   2. If not empty, remove node from front
 *   3. Free allocated memory
 *   4. If queue becomes empty, reset rear pointer
 * DESCRIPTION: Removes documents from the front of the queue in FIFO order.
 *              Deallocates memory of removed node.
 */
void dequeue()
{
    if(front==NULL)                          // Check for queue underflow
    {
        printf("Underflow!!!");
    }
    else
    {
        struct node *temp=front;              // Store front node
        front=front->next;                   // Move front pointer to next node
        free(temp);                          // Free memory of removed node
    }

    if(front==NULL)                          // If queue is now empty
    {
        rear=NULL;                           // Reset rear pointer
    }
    printf("Document deleted successfully!!");
}

/*
 * FUNCTION: display
 * PURPOSE: Display all pending documents in the queue from front to rear
 * PARAMETERS: None
 * RETURN: void
 * DESCRIPTION: Traverses the entire queue and prints each document ID.
 *              Shows all documents waiting to be processed in order.
 *              Displays "Queue empty!!" if no documents are pending.
 */
void display()
{
    if(front==NULL)                          // Check if queue is empty
    {
        printf("Queue empty!!");
    }
    else
    {
        struct node *temp=front;              // Start from front
        // Traverse entire queue from front to rear
        while(temp!=NULL)
        {
            printf("%d<->",temp->data);      // Print document ID
            temp=temp->next;                 // Move to next node
        }
    }
}

/*
 * FUNCTION: main
 * PURPOSE: Main driver function - provides menu interface for queue operations
 * MENU OPTIONS:
 *   1 - Enqueue: Add a new document to the queue
 *   2 - Dequeue: Remove and print a document from the queue
 *   3 - Display: Show all pending documents in the queue
 * FLOW: Displays menu, reads user choice, and calls appropriate function
 */
int main()
{
    int choice;              // Variable to store user's menu choice
    
    // Display menu options
    printf("1.-->Enqueue function\n 2.-->Dequeue function\n 3.-->Display function\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    
    // Process user choice
    switch(choice)
    {
        case 1:
            enqueue();       // Add document to queue
            break;

        case 2:
            dequeue();       // Remove document from queue
            break;

        case 3:
            display();       // Display all documents in queue
            break;

        default:
            break;
    }
    
    return 0;
}