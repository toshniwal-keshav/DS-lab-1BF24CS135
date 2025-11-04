#include<stdio.h>

#include <stdlib.h>
int arr[100],top=0;
void Push(int ele, int size){
    if(top == size)
        printf("Stack Overflow");
    else{
        arr[top]=ele;top++;
    }
}

 int Pop( ){
     top--;
    if(top == -1){
        printf("Stack Underflow");
        exit(0);
    }
    else{;
        return arr[top];
    }
}

 int Peak(){
    if(top == -1){
        printf("Stack Underflow");
        exit(0);
    }
    else
        return arr[top-1];
}

void main(){
    int s , top=0, choice;
    printf("Enter size: ");
    scanf("%d",&s);
    for(;;){
        printf("\n Make a choice \n 1.Push\n2.Pop\n3.Peak\n4.Display\nAny other number to escape\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                int ele;
                printf("Enter element to insert:");
                scanf("%d",&ele);
                Push(ele,s);
                break;
            case 2:
                printf("%d\n",Pop());
                break;
            case 3:
                printf("%d\n",Peak());
                break;
            case 4:
                for(int i=0;i<=top;i++){
                    printf("%d\n",arr[i]);
                }
                break;
            default:exit(0);
        }
    }
}


