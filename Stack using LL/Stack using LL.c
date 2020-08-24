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
		printf("Empty Stack");
	else{
		for(ptr=start;ptr!=NULL;ptr=ptr->next)
			printf("%d\t",ptr->num);
		printf("\n");
	}
	return;
}
int pop(){
	int d=start->num;
	ptr=start;
	start=start->next;
	free(ptr);
	return d; 
}
void push(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	if(start==NULL){
		start=new;
		new->next=NULL;
		end=new;
	}
	else{
		new->next=start;
		start=new;
	}
	return;
}
void main(){
	int i,var,index;
	char choice;
	printf("'I' -> push\n'O' -> pop\n");
	printf("'D' to display\n'E' to exit\n");
	while(1){
		A: printf("\nEnter your choice : ");
			scanf("%c",&choice);
			switch(toupper(choice)){
				case 'I': printf("Enter the element : ");
						  scanf("%d",&var);
						  push(var);
					 	  break;
				case 'O': if(!start)
							printf("Empty Stack");
						 else printf("Popped element = %d\n",pop());
						 break;
				case 'D': display();
						  break;
				case 'E': return;
				default: printf("Wrong Choice\n"); }
			fflush(stdin);
	}
}
