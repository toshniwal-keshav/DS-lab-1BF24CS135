#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node* prev;
};

struct Node *head=NULL;
struct Node *newNode=NULL;
struct Node *temp=NULL;

void createNode(int val){
    newNode=(struct Node*) malloc(sizeof(struct Node)) ;
    newNode->data=val;
    newNode->next=NULL;
}

void insertBegin(int ele){
    createNode(ele);
    if(head==NULL)
        head=newNode;
    else{
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
    printf("\nElement inserted ");
    return;
}

void deleteVal (int val){
    temp=head;
    while(temp!=NULL){
        if(temp->data ==val){
            if(temp->prev!= NULL) temp->prev->next = temp ->next;
            if(temp->next!= NULL) temp->next->prev = temp ->prev;
            if(temp== head ) head=temp->next;
            free(temp);
            printf("\nDeletion success");
            return;
        }
        temp=temp->next;
    }
    printf("\nElement NOT found");
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
                insertBegin(val);
                break;
            case 2:
                Display();
                break;
            case 3:
                printf("\nEnter value:");
                scanf("%d", &val);
                deleteVal(val);
                break;
            default:
                exit(0);
        }
    }
}
}
