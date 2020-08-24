#include<stdio.h>
#include<malloc.h>
struct list{
	int num;
	struct list *prev,*next;
};
struct list *start=NULL,*end=NULL,*ptr;
void insert(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	if(start==NULL){
		start=new;
		new->next=NULL;
		new->prev=NULL;
		ptr=start;
		end=new;
	}
	else{
		new->next=start;
		new->prev=NULL;
		start->prev=new;
		start=new;
	}
	return;
}
void delete_end(){
	struct list *temp;
	if(start==NULL)
		printf("Empty list");
	else if(start==end){
		free(start);
		start=NULL;
		end=NULL;
		printf("Element deleted\n");	}
	else{	temp=end;
			end=end->prev;
			end->next=NULL;
			free(temp);	
			printf("Element deleted\n");	}
	return;	}
void delete_start(){
	struct list *temp;
	if(start==NULL)
		printf("Empty list\n");
	else if(start==end){
		free(start);
		start=NULL;
		end=NULL;
		printf("Element deleted\n");	}
	else{	temp=start;
			start=start->next;
			start->prev=NULL;
			free(temp);
			printf("Element deleted\n");	} 	 
	return;
}
void delete_num(int var){
	ptr=start;
	if(ptr==NULL)
		printf("List Empty Cannot delete\n");
	else{ while(ptr!=NULL && ptr->num!=var)
			ptr=ptr->next;
		  if(ptr!=NULL && ptr->num==var){
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
			free(ptr);
			printf("Element deleted\n");	}
		  else 
			printf("Element not found\n");	}
	return;
}
void display(){
	if(start==NULL){
		printf("Empty list");
	}
	else{	for(ptr=start;ptr!=NULL;ptr=ptr->next)
				printf("%d\t",ptr->num);
			printf("\n");	}
	return;	}
void main(){
	int i,var;
	char choice;
	for(i=10;i>0;i--)
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
