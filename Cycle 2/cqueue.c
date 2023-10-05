#include<stdio.h>
#define MAX 10
int q[10],n,choice,front=-1,rear=-1;

void insert(){
int x;
if((front==0 &&rear==MAX-1)||(front==rear+1)){
	printf("queue is full");
	return;
}else {
	printf("Enter the element: ");
	scanf("%d", &x);
	if (front == -1) {
	front = 0;
	}
rear=(rear+1)%MAX;
q[rear] = x;
}}

void delete(){
if (front==-1){
	printf("Queue is empty ");
}else {
int removed =q[front];
if (front == rear){
front = rear = -1;
}else{
front = (front + 1) % MAX;
}
printf("Element deleted is %d.\n", removed);
}}
void display(){
int i;
if(rear==-1 && front==-1){
	printf("Queue is empty");
}else if (front > rear){
for (i = front;i<n;i++){
	printf("%d ", q[i]);
}
for(i=0;i<=rear;i++)
	printf("%d ", q[i]);
}else{
printf("Elements: ");
for (i = front; i <= rear; i++)
	printf("%d ", q[i]);
	printf("\nFront element is %d ", q[front]);
	printf("\nRear element is %d ", q[rear]);
}}

int main(){
  while(choice != 4)  {  
        printf("\nEnter the choice(1.Insert 2.Delete 3.Display 4.Exit): ");  
        scanf("%d",&choice);  
        switch(choice) {  
            case 1:    
                insert();  
                break;  
            case 2:  
                delete();  
                break;  
            case 3:
                display();  
                break;  
            case 4:  
                printf("Exit\n");  
                break;   
            default:
                printf("Enter valid option");  
            }}  
return 0;
}
