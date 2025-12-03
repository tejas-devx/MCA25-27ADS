#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int value) {
    Node *newNode = (Node *) malloc (sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* findMin(Node *root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* find(Node *root,int value) {
    if(root == NULL || root->data == value)
        return root;
    else if(value < root->data)
        return find(root->left,value);
    else    
        return find(root->right,value);
}

Node* insert(Node *root, int value) {
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insert(root->left,value);
    else if(value > root->data)
        root->right = insert(root->right,value);
    return root;
}

Node* delete(Node *root, int value) {
    if(root == NULL) 
        return root;
    else if(value < root->data)
        root->left = delete(root->left,value);
    else if(value > root->data)
        root->right = delete(root->right,value);
    else {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: one child
        else if(root->left == NULL) {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL) {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: 2 children
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
        return root;
    }
}

void inorder(Node *root) {
    if(root) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int ch,value;
    while(1) {
        printf("\n----BST Operations----\n");
        printf("1. Insert\n2. Delete\n3. Inorder\n4. Find\n5. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Enter value to insert:");
                scanf("%d",&value);
                root = insert(root,value);
                printf("%d is inserted\n",value);
                break;
            case 2:
                printf("Enter value to delete:");
                scanf("%d",&value);
                root = delete(root,value);
                printf("%d is deleted\n",value);
                break;
            case 3:
                printf("Inorder Traversal:");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter value:");
                scanf("%d",&value);
                Node *temp = find(root,value);
                if(temp)
                    printf("%d is found\n",value);
                else    
                    printf("%d not found\n",value);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong.....\n");
        }
    }
    return 0;
}