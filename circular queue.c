#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int q[51];
int ft=-1, r=-1;
bool isFull(int size){
    if(((r+1)%size)==ft)
       return true;
    else
       return false;
 }

 bool isEmpty(){
    if(ft==-1 && r==-1)
        return true;
    else
        return false;
 }

 void enqueue(int ele,int size){
    if(isFull(size)){
        printf("Overflow");
        //exit(0);
        return;
    }
    else if(isEmpty()){
        ft=0;r=0;
    }
    else
        r=(r+1)%size;
    q[r]=ele;
    printf("Element inserted");
 }

 void dequeue(int size){
    if(isEmpty()){
        printf("Underflow");
        //exit(0);
        return;
    }
    else if(ft==r){
        ft=-1;r=-1;
    }
    else
        ft=(ft-1)%size;
    printf("Element Removed");
 }

 int peak(){
    return q[r];
 }

 void main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);

    for(;;){
        printf("\nEnter choice :\n");
        printf("1.Enqueue\t2.Dequeue\t3.Peak\t4.Diplay all\nAny other number to escape\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element:");
                int ele;
                scanf("%d",&ele);
                enqueue(ele,size);
                break;
            case 2:
                dequeue(size);
                break;
            case 3:
                peak();
                break;
            case 4:
                for(int i=ft;i!=r;i=(i+1)%size)
                    printf("%d,",q[i]);
                printf("%d",q[r]);
                break;
            default:
                printf("Exiting from code");
                exit(0);
        }
    }
 }

