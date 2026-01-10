#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Create a new node */
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Find minimum value node */
Node* findMin(Node *root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

/* Search a value */
Node* find(Node *root, int value) {
    if (root == NULL || root->data == value)
        return root;
    else if (value < root->data)
        return find(root->left, value);
    else
        return find(root->right, value);
}

/* Insert a value */
Node* insert(Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Delete a value */
Node* deleteNode(Node *root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        /* Case 1: No child */
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        /* Case 2: One child */
        else if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        /* Case 3: Two children */
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

/* Inorder traversal */
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int ch, value;

    while (1) {
        printf("\n---- BST Operations ----\n");
        printf("1. Insert\n2. Delete\n3. Inorder\n4. Find\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (find(root, value)) {
                    root = deleteNode(root, value);
                    printf("%d deleted successfully\n", value);
                } else {
                    printf("%d not found in BST\n", value);
                }
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4: {
                printf("Enter value to find: ");
                scanf("%d", &value);
                Node *temp = find(root, value);
                if (temp)
                    printf("%d found in BST\n", value);
                else
                    printf("%d not found in BST\n", value);
                break;
            }

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
