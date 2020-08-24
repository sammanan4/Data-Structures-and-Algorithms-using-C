#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<ctype.h>
struct list{
	int num;
	struct list *next;
};
struct list *start=NULL,*end=NULL,*ptr;
void display(){
	int i;
	if(!start)
		printf("Empty Queue");
	else{
		for(ptr=start;ptr!=NULL;ptr=ptr->next)
			printf("%d\t",ptr->num);
		printf("\n");
	}
	return;
}
int Dequeue(){
	int d;
	d=start->num;
	ptr=start;
	start=start->next;
	free(ptr);
	return d; 
}
void Enqueue(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	if(start==NULL){
		start=new;
		new->next=NULL;
		end=new;
	}
	else{
		new->next=NULL;
		end->next=new;
		end=new;
	}
	return;
}
void main(){
	int i,var,index;
	char choice;
	printf("'I' -> Enqueue\n'O' -> Dequeue\n");
	printf("'D' to display\n'E' to exit\n");
	while(1){
			printf("\nEnter your choice : ");
			scanf("%c",&choice);
			switch(toupper(choice)){
				case 'I': printf("Enter the element : ");
						  scanf("%d",&var);
						  Enqueue(var);
					 	  break;
				case 'O': if(!start)
							printf("Empty Queue");
						 else printf("Dequeued element = %d\n",Dequeue());
						 break;
				case 'D': display();
						  break;
				case 'E': return;
				default: printf("Wrong Choice\n"); }
			fflush(stdin);
	}
	getch();
}
