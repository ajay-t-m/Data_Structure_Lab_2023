#include<stdio.h>
int stack[20],choice,n,top,x,i;
void push();
void pop();
void traverse();
int main(){
top=-1;
printf("Enter the size of stack: ");
scanf("%d",&n);
  while(choice != 4)  {  
        printf("\nEnter the choice(1.Push 2.Pop 3.Display 4.Exit): ");  

        scanf("%d",&choice);  
        switch(choice) {  
            case 1:  {   
                push();  
                break;  
            }  
            case 2:  {  
                pop();  
                break;  
            }  
            case 3:{  
                traverse();  
                break;  
            }  
            case 4:{  
                printf("Exit\n");  
                break;   
            }  
            default:{  
                printf("Enter valid option");  
            }}}  
return 0;
}

void push ()  
{  
    if (top>= n-1 ){
    printf("\nStack is overflow");   
    }else{  
        printf("Enter the value: ");  
        scanf("%d",&x);         
        top = top +1;   
        stack[top] = x;   
    }} 
    
void pop(){
if(top<=-1){
        printf("\n Stack is underflow");
    }else{
        printf("\nThe popped elements is %d",stack[top]);
        top--;
    }}
    
void traverse(){
    if(top>=0){
        printf("Elements: \n");
        for(i=top; i>=0; i--){
            printf("\n%d",stack[i]);
    }}else{
            printf("\nStack is empty");
    }   
}

