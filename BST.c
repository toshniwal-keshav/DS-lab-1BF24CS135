#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct Node *right;
    struct Node* left;
}Node;

Node * create(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp-> data =val;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(Node *root, Node *temp)
{

    if(temp->data < root->data)
    {
        if(root->left != NULL)  insert(root->left, temp);
        else {
            root->left = temp;
            return;
        }
    }
    else{
        if(root->right != NULL)   insert(root->right, temp);
        else{
            root->right = temp;
            return;
        }
    }
}

void preorder(Node *root)
{
    if(root != NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root){
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main()
{
    int ch;
    Node *root = NULL, *temp;
    printf("\n1. Insert, 2. Preorder, 3. Inorder:");
    while(1)
    {
        printf("\nEnter Choice:");
        scanf("%d", &ch);
        int val;
        switch(ch)
        {
        case 1:
            printf("\nEnter value to insert: ");
            scanf("%d", &val);
            temp=create(val);
            if(root == NULL) root=temp;
            else insert(root,temp);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        default:
            exit(0);
        }
    }


}


