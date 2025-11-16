#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left,*right;

}node;
node* root=NULL;
node* createNode()
{
    int x;
    printf("enter value(-1 for no node): ");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    printf("Enter left child of %d: ",x);
    newNode->left=createNode();
    printf("Enter right child of %d: ",x);
    newNode->right=createNode();
    return newNode;
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}
node* findrightmost(node* curr)
{
    while(curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
}
node* deleteNode(node* root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==val)
    {
        if(root->left==NULL && root->right==NULL)
        
        {
            printf("%d deleted",root->data);
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            node* temp=root->right;
            printf("%d deleted",root->data);
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            node* temp=root->left;
            printf("%d deleted",root->data);
            free(root);
            return temp;
        }
        else
        {
            node* lsubtree=root->left;
            node* rsubtree=root->right;
            node* rightmost=findrightmost(lsubtree);
            rightmost->right=rsubtree;
            printf("%d deleted",root->data);
            free(root);
            return lsubtree;
        }
        
    }
    root->left = deleteNode(root->left, val);
    root->right = deleteNode(root->right, val);
    return root;

}
int main()
{
    int ch,val;
    while(1)
    {
        printf("\n---Binary Tree---\n1.create\n2.preorder\n3.postorder\n4.inorder\n5.Delete\n6.exit\nEnter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            root=createNode();
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            printf("Enter Value: ");
            scanf("%d",&val);
            root=deleteNode(root,val);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid!\n");
            break;
        }
    }
    
    return 0;
}