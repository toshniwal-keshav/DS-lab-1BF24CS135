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
void insertBegin(int ele){
    createNode(ele);
    if(head==NULL)
        head=newNode;
    else{
        newNode->next=head;
        head=newNode;
    }
    printf("\nElement inserted at begining");
    return;
}

void insertEnd(int ele)
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
    printf("\nElement inserted at end");
}

void insertPos(int val, int pos)
{
    if(pos == 0)
    {
        insertBegin(val);
        return;
    }
    createNode(val);
    if(head == NULL)
        head = newNode;
    else
    {
        temp = head;
        for(int i = 0; i<pos-1;i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("\nElement inserted at %d index of list" ,pos);
    return;
}

void display(){
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

void main()
{
    int ch, val,pos;
    while(1)
    {
        printf("\n1.Insert at front, 2.Insert at back, 3.Insert at a position, 4.Display :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value:");
                scanf("%d", &val);
                insertBegin(val);
                break;
            case 2:
                printf("Enter value:");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter value and position:");
                scanf("%d %d", &val,&pos);
                insertPos(val,pos);
                break;
            case 4:
                display();
                break;
            default:
                exit(0);
        }
    }
}
