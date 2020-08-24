#include<stdio.h>
#include<malloc.h>
struct list{
	int num;
	struct list *prev,*next;
};
struct list *start=NULL,*end=NULL,*ptr;
void display(char direction){
	int i;
	if(end==NULL)
		printf("Empty list\n");
	else if(direction=='F'){
		for(ptr=start;ptr!=NULL;ptr=ptr->next)
			printf("%d\t",ptr->num);
		printf("\n");
	}
	else{
		for(ptr=end;ptr!=NULL;ptr=ptr->prev)
			printf("%d\t",ptr->num);
		printf("\n");
	}
	return;
}
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
		new->next=NULL;
		new->prev=end;
		end->next=new;
		end=new;
	}
	return;
}
void main(){
	int i,var,index;
	char choice;
	for(i=1;i<=10;i++)
		insert(i);
	printf("'F' to traverse forwards\n'B' to traverse backwards\n");
	printf("'E' to exit\n");
	while(1){
		printf("Enter your choice :");
		scanf("%c",&choice);
		switch(toupper(choice)){
			case 'F':
				display('F');
				break;
			case 'B':
				display('B');
				break;
			case 'E':
				return;
			default:
				printf("Wrong Choice\n");
			}
			fflush(stdin);
	}
}
