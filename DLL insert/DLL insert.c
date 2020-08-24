#include<stdio.h>
#include<malloc.h>
struct list{
	int num;
	struct list *prev,*next;
};
struct list *start=NULL,*end=NULL,*ptr;
void display(){
	int i;
	if(end==NULL)
		printf("Empty list");
	else{
		for(ptr=start;ptr!=NULL;ptr=ptr->next)
			printf("%d\t",ptr->num);
		printf("\n");
	}
	return;
}
void insert_beg(int n){
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
void insert_end(int n){
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
		new->next=NULL;
		new->prev=end;
		end->next=new;
		end=new;
	}
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
		printf("\nElement inserted");
		return;
	}
	while(counter<index && ptr!=NULL){
		ptr=ptr->next;
		counter++;
	}
	if(counter<index || index<=0){
		printf("\nInvalid index");
		free(new);
		return;
	}
	else if(ptr==NULL){
		insert_end(n);
		printf("\nElement inserted");
		return;
	}
	else{
		ptr->prev->next=new;
		new->prev=ptr->prev;
		new->next=ptr;
		ptr->prev=new;
		printf("\nElement inserted");
		return;
	}
}
void main(){
	start=NULL;
	end=NULL;
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
				printf("Enter the index at which number is to be inserted\n");
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
