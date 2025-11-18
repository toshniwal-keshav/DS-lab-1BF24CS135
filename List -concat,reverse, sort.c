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

void swap(struct Node *fir,struct Node *sec){
    int t=fir->data;
    fir->data=sec->data;
    sec->data=t;
}

void sort(){
    struct Node *temp1=NULL;
    int sw=0;
    if (head== NULL || head->next ==NULL)
        return;
    do{
        sw=0;
        temp=head;
        while (temp->next != temp1) {
            if (temp->data > temp->next->data){
                swap(temp,temp->next);
                sw = 1;
            }
            temp=temp->next;
        }
        temp1=temp;
    }while (sw);
    printf("\nSorted");
    display();
}

void reverse(){
    struct Node *curr=head, *prev= NULL;
    temp=NULL;
    if (head== NULL || head->next ==NULL)
        return;
    while(curr!=NULL){
        temp=curr->next;
        curr->next= prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    printf("\nReverse");
    display();
}

void concat(struct Node *h1,struct Node *h2){
    if(h1==NULL && h2== NULL){
        printf("\nBoth lists are empty");
        return;
    }
    else if(h2==NULL){
        printf("\nSecond List is empty");
        return;
    }
    temp=h1;
    while(h1->next!=NULL)
        temp=temp->next;
    h1->next=h2;
    printf("\nConcatenated");
    display();
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
    printf("\n1.Insert at end, 2.Sort, 3.Reverse, 4.Concat, 5.Display");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter value:");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 2:
                sort();
                break;
            case 3:
                reverse();
                break;
            case 5:
                display();
                break;
            case 4:
                concat(head, NULL);
                break;
            default:
                exit(0);
        }
    }
}
