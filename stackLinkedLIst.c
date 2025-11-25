#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;
struct Node *newNode=NULL;
struct Node *temp=NULL;

void createNode(int val){
    newNode=(struct Node*) malloc(sizeof(struct Node)) ;
    newNode->data=val;
    newNode->next=NULL;
}

void Push(int ele){
    createNode(ele);
    if(head==NULL)
        head=newNode;
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("\nElement inserted ");
}

void Pop(){
    if(head==NULL){
        printf("\nEmpty List");
        return;
    }
    else {
        temp =head;
        head=head->next;
        free(temp);
    }
    printf("\nDeletion success");
}

void Display(){
    if(head==NULL){
        printf("\nEmpty List");
        return;
    }
    else{
        temp=head;
        printf("\nList:\n");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void main(){
    {
    int ch, val,pos;
    printf("\n1.Insert , 2.Display, 3.Delete ");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter value:");
                scanf("%d", &val);
                Push(val);
                break;
            case 2:
                Display();
                break;
            case 3:
                Pop();
                break;
            default:
                exit(0);
        }
    }
}
}
