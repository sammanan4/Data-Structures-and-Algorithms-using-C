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
void insert_beg(int n){
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
		start=new;
	}
	printf("\nElement inserted");
	return;
}
void insert_end(int n){
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
	printf("\nElement inserted");
	return;
}
void insert_at(int n,int index){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	int counter=1;
	ptr=start;
	if(index==1){
		insert_beg(n);
		return;
	}
	while(counter<index && ptr->next!=start){
		ptr=ptr->next;
		counter++;
	}
	if(counter<index-1 || index<=0){
		printf("\nInvalid index");
		free(new);
		return;
	}
	else if(ptr->next==start){
		insert_end(n);
		return;
	}
	else{
		new->next=ptr;
		new->prev=ptr->prev;
		ptr->prev->next=new;
		ptr->prev=new;
		printf("\nElement inserted");
		return;
	}
}
void main(){
	start=NULL;
	int i,var,index;
	char choice;
	printf("'I' to insert at beginning\n'J' to insert at last\n");
	printf("'K' to insert at a certain index\n'D' to display\n");
	printf("'E' to exit\n");
	while(1){
		printf("\nEnter your choice : ");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'I':
				printf("Enter the element : ");
				scanf("%d",&var);
				insert_beg(var);
				break;
			case 'J':
				printf("Enter the element : ");
				scanf("%d",&var);
				insert_end(var);
				break;
			case 'K':
				printf("Enter the element : ");
				scanf("%d",&var);
				printf("Enter the index at which number is to be inserted : ");
				scanf("%d",&index);
				insert_at(var,index);
				break;
			case 'D':
				display();
				break;
			case 'E':
				return;
			default:
				printf("Wrong Choice\n");
			}
			fflush(stdin);
	}
}
