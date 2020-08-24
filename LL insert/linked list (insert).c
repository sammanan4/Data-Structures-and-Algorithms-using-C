#include<stdio.h>
#include<malloc.h>
struct list{
		int num;
		struct list *p;
	};
struct list *start,*ptr,*prev;

void display(){
	int i;
	struct list *ptr;
	if(start==NULL)
		printf("\nEmpty list");
	else
		for(ptr=start;ptr!=NULL;ptr=ptr->p)
			printf("%d\t",ptr->num);
	return;
}	
void insert_beg(int n){
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
void insert_end(int n){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	new->p=NULL;
	if(start==NULL){
		start=new;
		ptr=start;
	}
	else{
		for(ptr=start;ptr->p!=NULL;ptr=ptr->p);
		ptr->p=new;
	}
	return;
}	
void insert_at(int n,int index){
	struct list *new;
	new=(struct list *)malloc(sizeof(struct list));
	new->num=n;
	int counter=1;
	ptr=start;
	prev=ptr;
	if(index==1){
		insert_beg(n);
		printf("\nElement inserted");
		return;
	}
	while(counter<index && ptr!=NULL){
		prev=ptr;
		ptr=ptr->p;
		counter++;
	}
	if(counter<index || index<=0){
		printf("\nInvalid index");
		free(new);
		return;
	}
	else if(ptr==NULL){
		prev->p=new;
		new->p=NULL;
		printf("\nElement inserted");
		return;
	}
	else{
		prev->p=new;
		new->p=ptr;
		printf("\nElement inserted");
		return;
	}
}
void main(){
	start=NULL;
	int i,var,index;
	char choice;
	printf("'I' to insert at beginning\n");
	printf("'J' to insert at last\n");
	printf("'K' to insert at a certain index\n");
	printf("'D' to display\n");
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
