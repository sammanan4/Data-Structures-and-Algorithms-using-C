#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#define size 100
int front=-1,rear=-1;
int Queue[size];
void display(){
	int i;
	if(front==-1)
		printf("Empty Queue\n");
	else{	printf("Elements is Queue are : \n");
			for(i=front;i<=rear;++i)
				printf("%d\t",Queue[i]);
			printf("\n");	}
	return;	}
void Enqueue(int data){
	if(rear>=size)
		printf("Queue Overflow\n");
	else{	if(front==-1 && rear==-1){
				front=rear=0;
				Queue[rear]=data;	}
			else Queue[++rear]=data;	}
	return;	}
void Dequeue(){
	if(front==-1)
		printf("Queue Underflow\n");
	else{	printf("Dequeued element : %d\n",Queue[front++]);
			if(front>rear)
				front=rear=-1;
			}
	return;	}
void main(){
	char choice;
	int data;
	printf("'i' -> Enqueue\n'o' -> Dequeue\n'd' -> Display\n'q' -> Quit\n");
	while(1){
		printf("Select an option : ");
		choice=getchar();
		switch(tolower(choice)){
			case 'i':
				printf("Enter the element : ");
				scanf("%d",&data);
				Enqueue(data);
				break;
			case 'o':
				Dequeue();
				break;
			case 'd':
				display();
				break;	
			case 'q':return;
				break;	
			default: printf("Invalid option\n");	
		}
		fflush(stdin);
	}
	getch();
}
