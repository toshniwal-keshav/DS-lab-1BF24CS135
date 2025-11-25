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

void Enqueue(int ele)
{
    createNode(ele);
    if(head==NULL)
        head=newNode;
    else{
        temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("\nElement inserted");
}

void Dequeue(){
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
                printf("\nEnter even value:");
                scanf("%d", &val);
                //if(val %2 ==0)
                    Enqueue(val);
                //else
                //  printf("\n Number is odd , element not pushed ");
                break;
            case 2:
                Display();
                break;
            case 3:
                Dequeue();
                break;
            default:
                exit(0);
        }
    }
    }
}

