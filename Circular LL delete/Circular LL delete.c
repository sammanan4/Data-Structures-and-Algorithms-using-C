#include<stdio.h>
#include<malloc.h>
struct list{
	int num;
	struct list *prev,*next;
};
struct list *start=NULL,*ptr;
void display(){
	int i;
	if(!start)
		printf("Empty list");
	else{
		for(ptr=start;ptr->next!=start;ptr=ptr->next)
			printf("%d\t",ptr->num);
		printf("%d\n",ptr->num);
	}
	return;
}
void insert(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	if(!start){
		start=new;
		new->next=start;
		new->prev=start;
		ptr=start;
	}
	else{
		new->next=start;
		new->prev=start->prev;
		start->prev->next=new;
		start->prev=new;
	}
	return;
}
void delete_start(){
	struct list *temp;
	if(!start)
		printf("Empty list\n");
	else{	temp=start;
			start->prev->next=start->next;
			start->next->prev=start->prev;
			start=start->next;
			free(temp);
			printf("Element deleted\n");	} 	 
	return;
}
void delete_end(){
	if(!start)
		printf("Empty list");
	else{	ptr=start->prev;
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(ptr);	
			printf("Element deleted\n");	}
	return;	}
void delete_num(int var){
	ptr=start;
	if(!ptr)
		printf("List Empty Cannot delete\n");
	else{ while(ptr->next!=start && ptr->num!=var)
			ptr=ptr->next;
		  if(ptr!=NULL && ptr->num==var){
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(ptr);
			printf("Element deleted\n");	}
		  else	if(ptr->num==var){
		  		ptr->prev->next=ptr->next;
				ptr->next->prev=ptr->prev;
				free(ptr);	
		  	} 
		  else	printf("Element not found\n");	}
	return;
}
void main(){
	int i,var;
	char choice;
	for(i=1;i<=10;i++)
		insert(i);
	printf("'X' to delete last element\n'Y' to delete first element\n");
	printf("'Z' to delete a specific element\n'D' to display\n");
	printf("'E' to exit\n");
	while(1){
		printf("Enter your choice :");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'X':delete_end();
					 break;
			case 'Y':delete_start();
					 break;
			case 'Z':printf("Enter the element to be deleted\n");
					 scanf("%d",&var);
					 delete_num(var);
					 break;	
			case 'D':display();
					 break;
			case 'E':return;
			default:printf("Wrong Choice\n");	}
		fflush(stdin);	}
	getch();
}
