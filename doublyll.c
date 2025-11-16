#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning \n", value);
}

// Insert at End
void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end \n", value);
}

// Delete from beginning
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("Deleted %d from beginning \n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    printf("Deleted %d from end", temp->data);
    free(temp);
}

// Traversal from beginning
void traverseFromBeginning()
{
    if (head == NULL)
    {
        printf("List is empty \n");
        return;
    }
    struct Node* temp = head;
    printf("List from beginning: ");
    while (temp !=NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}

//Traversal from end
void traverseFromEnd() {
    if(head == NULL) {
        printf("List is empty \n");
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    printf("List from end: ");
    while(temp != NULL) {
        printf("%d",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

//Count number of elements
void countElements(){
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }   
    printf("Number of elements: %d \n",count);
}

// Main menu
int main() {
    int choice, value;
    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Traverse from Beginning\n");
        printf("6. Traverse from End\n");
        printf("7. Count Elements\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                traverseFromBeginning();
                break;
            case 6:
                traverseFromEnd();
                break;
            case 7:
                countElements();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}