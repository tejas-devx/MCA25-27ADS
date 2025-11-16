//Singly Linked Stack-- Creation, Insertion, Deletion, Traversal, Count.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Stack Overflow!Unable to push. \n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack. \n ",value);
}

void pop(){
    if(top==NULL){
        printf("Stack Underflow!Stack is empty. \n");
        return;
    }
    struct Node *temp = top;
    printf("%d popped from stack. \n",temp->data);
    top = top->next;
    free(temp);
}

void display(){
    if(top==NULL){
        printf("Stack is empty. \n");
        return;
    }
    struct Node *temp=top;
    printf("Stack elements(Top to Bottom) \n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp =temp->next;
    }
    printf("NULL \n");
}

void count(){
    int cnt = 0;
    struct Node *temp = top;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    printf("Total elements in stack=%d \n",cnt);
}

int main(){
    int choice,value;
    do{
        printf("\n---Stack Menu---\n");
        printf("1.Push(Insertion)\n");
        printf("2.Pop(Deletion) \n");
        printf("3.Display(Traversal)\n");
        printf("4.Count\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            count();
            break;
        case 5:
            printf("Exiting program \n");
            break;
        default:
        printf("Invalid choice \n");
            break;
        }
    }while(choice!=5);
    return 0;
}
