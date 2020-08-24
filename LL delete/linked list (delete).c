#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
struct list{
		int num;
		struct list *p;
	};
struct list *start,*ptr,*prev;
void insert(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	if(start==NULL){
		start=new;
		new->p=NULL;
	}
	else{
		new->p=start;
		start=new;
	}
}
void delete_end(){
	struct list *temp,*prev;
	if(start==NULL){
		printf("Empty list\n");
		return;
	}
	else if(start->p==NULL)
		free(start);
	else{
		ptr=start;
		while(ptr->p->p!=NULL)
			ptr=ptr->p;
		temp=ptr->p;
		ptr->p=NULL;
		free(temp);
	}
	printf("Element deleted\n");
	return;
}
void delete_start(){
	struct list *temp;
	ptr=start;
	if(start==NULL){
		printf("Empty list\n");
		return;
	}
	temp=start;
	start=start->p;
	free(temp);
	printf("Element deleted\n");
	return;
}
void delete_num(int var){
	ptr=start;
	if(ptr==NULL){
		printf("List Empty Cannot delete\n");
		return;
	}
	else
		while(ptr!=NULL && ptr->num!=var){
			prev=ptr;
			ptr=ptr->p;
			}
	if(ptr!=NULL && ptr->num==var){
		prev->p=ptr->p;
		free(ptr);
		printf("Element deleted\n");
		}
	else 
		printf("Element not found\n");
}
void display(){
	int i;
	struct list *ptr;
	if(start==NULL){
		printf("Empty list\n");
	}
	else{
		for(ptr=start;ptr!=NULL;ptr=ptr->p){
			printf("%d\t",ptr->num);
		}
		printf("\n");
	}
	return;
}	
	
void main(){
	start=NULL;
	int i,var;
	char choice;
		for(i=10;i>0;i--)
			insert(i);
	printf("'X' to delete last element\n");
	printf("'Y' to delete first element\n");
	printf("'Z' to delete a specific element\n");
	printf("'D' to display\n");
	printf("'E' to exit\n");
	while(1){
		printf("Enter your choice :");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'X':{
				delete_end();
				break;
			}
			case 'Y':{
				delete_start();
				break;
			}
			case 'Z':{
				printf("Enter the element to be deleted\n");
				scanf("%d",&var);
				delete_num(var);
				break;
			}
				
			case 'D':{
				display();
				break;
			}
			case 'E':
				return;
			default:
				printf("Wrong Choice\n");
			}
			fflush(stdin);
	}
	getch();
}
