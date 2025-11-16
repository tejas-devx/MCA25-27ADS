#include<stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1,rear = -1;

void enqueue(int val){
    if((front == 0 && rear == SIZE -1) || (front == rear +1)) { // (front == rear+1)%n
        printf("Queue Overflow! Cannot insert %d \n",val);
    } else {
        if(front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear+1) % SIZE;
        }
        cq[rear] = val;
        printf("%d inserted \n",val);
    }
}

void dequeue(){
    if(front == -1) {
        printf("Queue Underflow! Cannot delete \n");
    } else {
        printf("%d deleted \n",cq[front]);
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front +1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty \n");
    } else {
        int i = front;
        printf("Queue elements");

        while (1)
        {
            printf("%d ", cq[i]);
            if(i == rear)
            break;
            i = (i+1)%SIZE;
        }
        printf("\n");
    }
}

void countElements() {
    int count =0;
    if(front == -1) {
        printf("Queue has 0 elements \n");
        return;
    }

    int i = front;
    while(1) {
        count++;
        if(i==rear)
        break;
        i=(i+1) % SIZE;
    }
    printf("Number of elements in queue: %d \n",count);
}

int main() {
    int choice, val;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                countElements();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}
